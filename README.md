Configurator
============
Summary
-------
Creates the database schema for webos Applications.

Description
-----------
Configurator is a userspace service that creates the database schema (webOS Db8 kinds) for Applications. It scans the /etc/palm/db/kinds directory to read the App's Db8
schema files to create the db kinds in the Db8.

Dependencies
============
Below are the tools and libraries required to build.

	- cmake 2.8.7 
	- glib-2.0
	- webosose/Db8 libraries (libmojocore, libmojoluna)
	- webosose/luna-service2 3.0.0
	- webosose/cmake-modules-webos

How to Build on Linux
=====================

## Building

Once you have downloaded the source, execute the following to build it (after
changing into the directory under which it was downloaded):

    $ mkdir BUILD
    $ cd BUILD
    $ cmake ..
    $ make
    $ sudo make install

The directory under which the files are installed defaults to
<tt>/usr/local/webos</tt>.
You can install them elsewhere by supplying a value for
<tt>WEBOS_INSTALL_ROOT</tt>
when invoking <tt>cmake</tt>. For example:

    $ cmake -D WEBOS_INSTALL_ROOT:PATH=$HOME/projects/webosose ..
    $ make
    $ make install

will install the files in subdirectories of <tt>$HOME/projects/webosose</tt>.

Specifying <tt>WEBOS_INSTALL_ROOT</tt> also causes <tt>pkg-config</tt> to look
in that tree first before searching the standard locations. You can specify
additional directories to be searched prior to this one by setting the
the <tt>PKG_CONFIG_PATH</tt> environment variable.

To see all of the make targets that CMake has generated, issue:

    $ make help


# Copyright and License Information

Unless otherwise specified, all content, including all source code files and
documentation files in this repository are:

Copyright (c) 2010-2018 LG Electronics, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

SPDX-License-Identifier: Apache-2.0
