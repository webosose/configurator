// @@@LICENSE
// (c) Copyright 2016-2022 LG Electronics US
//
// Confidential computer software. Valid license from LG required for
// possession, use or copying. Consistent with FAR 12.211 and 12.212,
// Commercial Computer Software, Computer Software Documentation, and
// Technical Data for Commercial Items are licensed to the U.S. Government
// under vendor's standard commercial license.
// # LICENSE@@@

#include <openssl/md5.h>

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>

#include <string>
#include "md5sum.h"

using namespace std;

bool doesExistOnFileSystem(const char* pathAndFile)
{
    if (!pathAndFile)
        return false;

    struct stat buf;
    if(-1 == stat(pathAndFile, &buf))
        return false;
    return true;
}

string binTohex(const unsigned char *bin, size_t len)
{
    const char hex[] = "0123456789abcdef";

    string res;
    for(size_t i = 0; i < len; ++i) {
    unsigned char c = (unsigned char)bin[i];
        res += hex[c >> 4];
        res += hex[c & 0xf];
    }

    return res;
}

vector<string> getGlob(const string& pat)
{
    glob_t glob_result;
    glob(pat.c_str(), GLOB_TILDE, NULL, &glob_result);
    vector<string> ret;
    for(unsigned int i = 0; i < glob_result.gl_pathc; ++i)
    {
        ret.push_back(string(glob_result.gl_pathv[i]));
    }
    globfree(&glob_result);
    return ret;
}

std::string makeMD5Checksum(string& contents)
{
    unsigned char checksum[MD5_DIGEST_LENGTH];
    memset(checksum, 0, MD5_DIGEST_LENGTH);
    MD5((unsigned char*)contents.c_str(), contents.length(), checksum);
    return binTohex(checksum, MD5_DIGEST_LENGTH);
}
