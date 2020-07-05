/**
 * Tencent is pleased to support the open source community by making Tars available.
 *
 * Copyright (C) 2016THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this file except 
 * in compliance with the License. You may obtain a copy of the License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software distributed 
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the 
 * specific language governing permissions and limitations under the License.
 */

/*
 * MockServerObjProxy.h
 *
 *  Created on: 2018年8月22日
 *      Author: abelguo
 */

#ifndef MOCK_PROXY_MOCKSERVEROBJPROXY_H_
#define MOCK_PROXY_MOCKSERVEROBJPROXY_H_
#include "servant/Servant.h"
#include "servant/ServantProxy.h"

using namespace tars;
using namespace std;

namespace mockProxy
{
    /* proxy for client */
    class MockServerObjProxy : public ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        MockServerObjProxy* tars_hash(int64_t key);
        MockServerObjProxy* tars_consistent_hash(int64_t key);
        MockServerObjProxy* tars_set_timeout(int msecond);
        const char* tars_prxname() const { return "MockServerObjProxy"; }
    };
    typedef TC_AutoPtr<MockServerObjProxy> MockServerObjPrx;
}

#endif /* MOCK_PROXY_MOCKSERVEROBJPROXY_H_ */