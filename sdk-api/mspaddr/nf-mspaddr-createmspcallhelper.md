# CreateMSPCallHelper function

## Description

The
**CreateMSPCallHelper** helper template function is called in the derived class' implementation of
[CreateMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-createmspcall). It checks all of the arguments for validity, including the media type argument (via the address object method
[IsValidSetOfMediaTypes](https://learn.microsoft.com/windows/desktop/api/mspaddr/nf-mspaddr-cmspaddress-isvalidsetofmediatypes); see above). It sets up the aggregation between the MSP call object and the TAPI call object using the **CComAggObject** ATL class template. It then calls the
[Init](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-init) method on the MSP call object.

## Parameters

### `pCMSPAddress`

Pointer to
[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress) interface for call.

### `htCall`

Handle for MSP.

### `dwReserved`

Reserved parameter, not currently used.

### `dwMediaType`

[Media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) desired for call.

### `pOuterUnknown`

Pointer to **IUnknown** interface for TAPI call object.

### `ppMSPCall`

Pointer to **IUnknown** interface for MSP call object.

### `ppCMSPCall`

Pointer to templated MSP call class, type implementation dependent.

### `unnamedParam8`

TBD

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CMSPAddress](https://learn.microsoft.com/windows/desktop/api/mspaddr/nl-mspaddr-cmspaddress)

[CreateMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-createmspcall)