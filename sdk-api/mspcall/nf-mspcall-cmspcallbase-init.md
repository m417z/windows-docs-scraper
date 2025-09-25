# CMSPCallBase::Init

## Description

The
**Init** method is called by the MSP address object (in the method
[CreateMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-createmspcall)) to initialize the MSP call object. The derived class should initialize its members using the passed-in information.

## Parameters

### `pMSPAddress`

Pointer to MSP call object to be initialized.

### `htCall`

The MSP handle for the call.

### `dwReserved`

Reserved.

### `dwMediaType`

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) or types of call.

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)

[CMSPCallMultiGraph::Init](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-init)

[CreateMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-createmspcall)