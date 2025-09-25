# CMSPCallMultiGraph::Init

## Description

The
**Init** method is called by the MSP address object (in the method
[CreateMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-createmspcall)) to initialize the MSP call object. The
[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph) implementation initializes its members using the passed-in information. It calls
[MSPAddressAddRef](https://learn.microsoft.com/windows/desktop/api/mspaddr/nf-mspaddr-cmspaddress-mspaddressaddref) on the MSP address object. Derived MSPs will want to override this method and call it in the overridden method; the overridden method should create the default streams based on the passed-in media types.

## Parameters

### `pMSPAddress`

Pointer to
[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress) for call being initialized.

### `htCall`

The MSP's handle for the call being initialized

### `dwReserved`

Reserved parameter.

### `dwMediaType`

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) or types of call.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)