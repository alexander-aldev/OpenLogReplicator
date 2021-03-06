/* Header for WriterService class
   Copyright (C) 2018-2020 Adam Leszczynski (aleszczynski@bersler.com)

This file is part of OpenLogReplicator.

OpenLogReplicator is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation; either version 3, or (at your option)
any later version.

OpenLogReplicator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License
along with OpenLogReplicator; see the file LICENSE;  If not see
<http://www.gnu.org/licenses/>.  */

#ifdef LINK_LIBRARY_GRPC
#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#endif /* LINK_LIBRARY_GRPC */

#include "types.h"
#include "Writer.h"

#ifdef LINK_LIBRARY_PROTOBUF
#include "OraProtoBuf.pb.h"
#include "OraProtoBuf.grpc.pb.h"
#endif /* LINK_LIBRARY_PROTOBUF */

#ifndef WRITERSERVICE_H_
#define WRITERSERVICE_H_

using namespace std;
#ifdef LINK_LIBRARY_GRPC
using namespace grpc;
#endif /* LINK_LIBRARY_GRPC */

namespace OpenLogReplicator {

    class RedoLogRecord;
    class OracleAnalyser;

    class WriterService : public Writer {
    protected:
        string uri;

        virtual void sendMessage(uint8_t *buffer, uint64_t length, bool dealloc);
        virtual string getName();

    public:
        WriterService(const char *alias, OracleAnalyser *oracleAnalyser, const char *uri);
        virtual ~WriterService();
    };
}

#endif
