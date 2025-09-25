# ITBasicCallControl::Hold

## Description

The
**Hold** method places or removes the call from the hold.

## Parameters

### `fHold` [in]

If *fHold* is VARIANT_TRUE and the method succeeds, the
[call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) transitions to the CS_HOLD state. If *fHold* is VARIANT_FALSE, the call state transitions to CS_CONNECTED.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_INVALCALLSTATE** | The call associated with this interface no longer exists. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Hold overview](https://learn.microsoft.com/windows/desktop/Tapi/hold-ovr)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[lineHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehold)