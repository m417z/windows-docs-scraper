# CMSPCallMultiGraph::ShutDown

## Description

The
**ShutDown** method is called by the MSP address object (in the method
[ShutdownMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-shutdownmspcall)) to shut down the MSP call object. Cancels the thread pool waits on the call's graph events. Releases the references on all the stream objects. Calls the shutdown method on all the stream objects. Acquires the lock in the function.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)