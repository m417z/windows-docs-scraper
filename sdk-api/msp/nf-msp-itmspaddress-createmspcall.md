# ITMSPAddress::CreateMSPCall

## Description

The **CreateMSPCall** method creates an MSP Call object. TAPI aggregates this onto the main Call object and exposes the
[ITStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstreamcontrol) interface.

## Parameters

### `hCall` [in]

Handle for this MSP.

### `dwReserved` [in]

Reserved value – will be 0.

### `dwMediaType` [in]

Indicates
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) required for the call.

### `pOuterUnknown` [in]

The pointer to the
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the TAPI 3 call object. Since the MSP Call object is aggregated in the TAPI 3 call object, it needs to know the outer **IUnknown**.

### `ppStreamControl` [out]

Pointer to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer of
[ITStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstreamcontrol) interface for newly created call.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | The MSP failed to initialize. |
| **E_POINTER** | *pMSPCallback* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_INVALIDMEDIATYPE** | *dwMediaType* is not a valid [media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants). |

## See also

[ITMSPAddress](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itmspaddress)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)