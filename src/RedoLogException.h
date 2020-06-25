/* Header for RedoLogException class
   Copyright (C) 2018-2020 Adam Leszczynski (aleszczynski@bersler.com)

This file is part of Open Log Replicator.

Open Log Replicator is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

Open Log Replicator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License
along with Open Log Replicator; see the file LICENSE;  If not see
<http://www.gnu.org/licenses/>.  */

#include <exception>
#include <iostream>

#ifndef REDOLOGEXCEPTION_H_
#define REDOLOGEXCEPTION_H_

using namespace std;

namespace OpenLogReplicator {

    class RedoLogException: public exception {
    public:
        const char* msg;

        RedoLogException(const char* msg);
        virtual ~RedoLogException();

        friend ostream& operator<<(ostream& os, const RedoLogException& ors);
    };
}

#endif
