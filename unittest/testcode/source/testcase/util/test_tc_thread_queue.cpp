#include "gtest/gtest.h"
#include "servant/Application.h"
#include "TarsTest/TestcaseServer/RPCTest.h"
#include "servant/AdminF.h"
#include "TarsServantName.h"


#include "util/tc_monitor.h"
#include "util/tc_common.h"
#include "util/tc_thread_queue.h"
#include "util/tc_autoptr.h"
#include "util/tc_thread.h"
#include "util/tc_logger.h"
#include <iostream>
using namespace std;
using namespace tars;
using namespace TarsTest;

TC_ThreadQueue<string> _queue;
TC_RollLogger _logger;

struct A : public TC_HandleBase
{
};

typedef TC_AutoPtr<A> APtr;

class WriteThread : public TC_Thread, public TC_HandleBase
{
    /**
     * ����
     */
protected:
    virtual void run() 
    {
        int i = 300;
        while(i-- > 0)
        {
            timeval t1;
            gettimeofday(&t1, NULL);

            _queue.push_back("abc");
            usleep(1000);

            timeval t2;
            gettimeofday(&t2, NULL);

            _logger.debug() << "push_back:" << t2.tv_usec - t1.tv_usec << endl;
				usleep(1000);
				cout << "write" << endl;
        }
    }
};

typedef TC_AutoPtr<WriteThread> WriteThreadPtr;

class ReadThread : public TC_Thread, public TC_HandleBase
{
    /**
     * ����
     */
protected:
    virtual void run() 
    {
        int i = 100;
        while(i-- > 0)
        {
            string t;
            timeval t1;
            gettimeofday(&t1, NULL);
            if(_queue.pop_front(t, 10))
            {
                timeval t2;
                gettimeofday(&t2, NULL);
                _logger.debug() << "pop_front:" << t2.tv_usec - t1.tv_usec << endl;
//                cout << pthread_self() << ":" << t << endl;
                usleep(20 * 1000);
            }

        }
    }
};

typedef TC_AutoPtr<ReadThread> ReadThreadPtr;

TEST(TarsUtilTestcase, UT_TC_ThreadQueue)
{
    return;
    
    WriteThreadPtr wt = new WriteThread();
    wt->start();
    wt->getThreadControl().join();    

    vector<ReadThreadPtr> rts;
    for(size_t i = 0; i < 3;i++)
    {
        rts.push_back(new ReadThread());
        rts.back()->start();
        rts.back()->getThreadControl().join();
    }
    
    int done = true;
    while(true) {
        done = true;
        usleep(1000*1000);
        for(size_t i = 0; i < 3;i++)
        {
            if(rts[i]->isAlive())    {
                done = false;
            }
        }        
        
        if(wt->isAlive())   {
            done =false;
        }
        
        if(done)    { break; }
    }

}

                           
