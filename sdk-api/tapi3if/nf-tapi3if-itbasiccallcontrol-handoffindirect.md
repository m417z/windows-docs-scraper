# ITBasicCallControl::HandoffIndirect

## Description

The
**HandoffIndirect** method hands off the call to another application based on the
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) of the call. If multiple applications have registered as able to handle the types involved, TAPI will hand off to the highest-priority application, which is usually the one that registered first.

This indicates that the application no longer requires ownership of the call.

## Parameters

### `lMediaType` [in]

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) to transfer to.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *lMediaType* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

If TAPI fails to hand off the call, TAPI will call
[Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect).

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Handoffs overview](https://learn.microsoft.com/windows/desktop/Tapi/handoffs-ovr)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[TAPIMEDIATYPE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants)

[lineHandoff](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehandoff)