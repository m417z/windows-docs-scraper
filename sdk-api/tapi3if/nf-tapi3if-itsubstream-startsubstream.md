# ITSubStream::StartSubStream

## Description

The **StartSubStream** method starts the substream. See the Remarks section under
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) for additional information.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_NOTERMINALSELECTED** | No terminal has been selected on the substream so it cannot be started. |
| **TAPI_E_NOTSTOPPED** | Substream has already been started. |
| **TAPI_E_NOTSUPPORTED** | This operation is not supported. |

## See also

[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)