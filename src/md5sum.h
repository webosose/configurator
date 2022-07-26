// @@@LICENSE
// (c) Copyright 2016-2022 LG Electronics US
//
// Confidential computer software. Valid license from LG required for
// possession, use or copying. Consistent with FAR 12.211 and 12.212,
// Commercial Computer Software, Computer Software Documentation, and
// Technical Data for Commercial Items are licensed to the U.S. Government
// under vendor's standard commercial license.
// # LICENSE@@@

#ifndef __MD5_SUM_H__
#define __MD5_SUM_H__

#include <vector>
#include <string>

int validateSettingsCache(const std::vector<std::string>& md5List);
bool doesExistOnFileSystem(const char* pathAndFile);
std::vector<std::string> getGlob(const std::string& pat);
std::string makeMD5Checksum(std::string& contents);

#endif // __MD5_SUM_H__

