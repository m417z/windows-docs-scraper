# ITStreamControl::CreateStream

## Description

The
**CreateStream** method creates a new media stream.

## Parameters

### `lMediaType` [in]

Indicates
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) for stream.

### `td` [in]

Indicates the
[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction).

### `ppStream` [out]

Pointer to pointer for newly created
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppStream* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_INVALIDMEDIATYPE** | The *lMediaType* parameter is not a valid media type. |
| **TAPI_E_INVALIDDIRECTION** | The *td* parameter is not a valid terminal direction. |
| **TAPI_E_MAXSTREAMS** | The maximum number of streams supported has already been reached. |
| **TAPI_E_NOTSUPPORTED** | This operation is not supported. |

## Remarks

Many MSPs do not support dynamic creation of streams, and simply return TAPI_E_MAXSTREAMS in their implementation of this method. Default streams are automatically available when a call is created, so most applications do not have to use this method.

Stream creation or removal may involve interaction with a remote endpoint, resulting in a CMC_REMOTE_REQUEST rather than the CMC_LOCAL_REQUEST messages that are received when a stream is stopped or started.

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface returned by **ITStreamControl::CreateStream**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITStream** interface to free resources associated with it.

## See also

[ITStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstreamcontrol)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction)

[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants)