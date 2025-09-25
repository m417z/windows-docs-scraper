# ITCallInfo::GetCallInfoBuffer

## Description

The
**GetCallInfoBuffer** method gets call information items that require a buffer, such as user-user information. Automation client applications, such as those written in Visual Basic, must use the
[ITCallInfo::get_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfobuffer) method.

## Parameters

### `CallInfoBuffer` [in]

[CALLINFO_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_buffer) indicator of information type needed, such as CIB_USERUSERINFO.

### `pdwSize` [out]

Size of buffer returned in bytes.

### `ppCallInfoBuffer` [out]

Pointer to buffer containing the needed call information.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pdwSize* or *ppCallInfoBuffer* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *CallInfoBuffer* parameter is not a valid value. |
| **TAPI_E_INVALCALLSTATE** | The current [call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) is not valid for this operation. |

## See also

[CALLINFO_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_buffer)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[SetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-setcallinfobuffer)

[get_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfobuffer)

[put_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfobuffer)