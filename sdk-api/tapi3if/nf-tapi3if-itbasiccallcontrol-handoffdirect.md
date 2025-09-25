# ITBasicCallControl::HandoffDirect

## Description

The
**HandoffDirect** method hands off the call to another application. This indicates that the application no longer requires ownership of the call.

## Parameters

### `pApplicationName` [in]

Pointer to **BSTR** containing the specific application name to hand off call to. Can be full path name or executable name.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pApplicationName* parameter is not a valid pointer. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

If the receiving application has not opened the line for the media types involved in the call, the handoff will fail. If TAPI fails to hand off the call, TAPI will call
[Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect).

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pApplicationName* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect)

[Handoffs overview](https://learn.microsoft.com/windows/desktop/Tapi/handoffs-ovr)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[lineHandoff](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linehandoff)