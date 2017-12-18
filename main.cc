#include "AIOContext.h"

#include <cstring>
#include <system_error>
#include <chrono>
#include <thread>
#include <iostream>

#include <fcntl.h>

#include <cstdlib>


int main(int argc, char **argv) {
    AIOContext aio_ctx( 64 );
    (void)aio_ctx;
    
    int fd = open( "/dev/fake-dev0", O_DIRECT | O_RDWR | O_CLOEXEC );
    if( fd == -1 )
    {
        throw std::system_error( errno, std::system_category(), "failed to open test block device" );
    }
    
    
    uint8_t* data = new uint8_t[ 4096 ];
    std::memset( data, 3, 4096 );
    
    
    for( int i = 0; i < 10; ++i )
    {
        aio_ctx.queueWrite( fd, data, 4096, 0 );
    }
    aio_ctx.submitRequests();
    
    auto events = aio_ctx.collectRequests( 10, 10 );
    std::cerr << events.size() << std::endl;
    for( auto event : events )
    {
        delete event.getData();
    }
    
    return 0;
}
