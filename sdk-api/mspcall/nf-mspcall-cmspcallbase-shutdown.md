# CMSPCallBase::ShutDown

## Description

The
**ShutDown** method is called by the **MSPAddress** object (in the method
[ShutdownMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-shutdownmspcall)) to shut down the call. The derived class implementation should shut down all the streams on the call. (See also
[CMSPCallMultiGraph::ShutDown](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-shutdown).)

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)