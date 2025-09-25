# ITBasicCallControl::Finish

## Description

The
**Finish** method is called on a consultation call to finish a conference or a transfer.

## Parameters

### `finishMode` [in]

A
[FINISH_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-finish_mode) indicator of the type of call being finished, such as FM_ASCONFERENCE.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_INVALCALLSTATE** | Call is not flagged as a transfer or a conference. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Conference](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-conference)

[Conference overview](https://learn.microsoft.com/windows/desktop/Tapi/conference-ovr)

[Create a Simple Conference code snippet](https://learn.microsoft.com/windows/desktop/Tapi/create-a-simple-conference)

[FINISH_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-finish_mode)

[Forward overview](https://learn.microsoft.com/windows/desktop/Tapi/forward-ovr)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[Transfer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-transfer)

[Transfer overview](https://learn.microsoft.com/windows/desktop/Tapi/transfer-ovr)