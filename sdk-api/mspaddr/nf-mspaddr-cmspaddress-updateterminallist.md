# CMSPAddress::UpdateTerminalList

## Description

The
**UpdateTerminalList** method populates the MSP's list of static terminals. It assumes that we have no static terminals available and it is always called in situations where this is true. This method uses DirectShow's "devenum" component and a static list of categories to discover monikers for static terminals. It uses the static
[CreateTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-createterminal) methods on each type of terminal (see below) to actually create the terminals, possibly failing if the moniker in question is not acceptable (see below). For each successfully created terminal, it adds the terminal to the address' list. When this process is complete, devenum is released. An MSP that uses different static terminals than the ones created or that needs to use additional static terminals must override this method. The categories currently used here are CLSID_CWaveInClassManager, CLSID_CWaveOutClassManager, and CLSID_CVidCapClassManager. The method does not use categories that correspond to media types that the derived MSP does not support (this is checked automatically in the base class).

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)