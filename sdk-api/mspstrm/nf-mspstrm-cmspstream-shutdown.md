# CMSPStream::ShutDown

## Description

The
**ShutDown** method is called by the **MSPCall** object. It unselects all the terminal objects (via
[UnselectTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-unselectterminal)). It also calls
[MSPCallRelease](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-mspcallrelease) on the call object. This is needed to break the circular refcount.