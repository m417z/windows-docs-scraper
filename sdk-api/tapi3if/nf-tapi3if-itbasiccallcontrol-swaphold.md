# ITBasicCallControl::SwapHold

## Description

The
**SwapHold** method swaps the call (which is active) with the specified call on hold.

Swapping the active call with the call on consultation hold allows the application to toggle between these two calls. This is typical in call waiting.

## Parameters

### `pCall` [in]

Call, currently on hold, that is to be made active.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | This operation is not supported. |
| **E_POINTER** | The *pCall* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *pCall* parameter does not describe a currently existing call. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_OPERATIONFAILED** | The operation failed. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold)