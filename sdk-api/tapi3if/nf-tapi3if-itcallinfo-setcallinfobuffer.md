# ITCallInfo::SetCallInfoBuffer

## Description

The
**SetCallInfoBuffer** method sets call information items that require a buffer, such as user-user information. Automation client applications, such as those written in Visual Basic, must use the
[ITCallInfo::put_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfobuffer) method.

## Parameters

### `CallInfoBuffer` [in]

[CALLINFO_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_buffer) indicator of information type needed, such as CIB_USERUSERINFO.

### `dwSize` [in]

Size of *pCallInfoBuffer*.

### `pCallInfoBuffer` [in]

Pointer to call information buffer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCallInfoBuffer* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *CallInfoBuffer* parameter is not a valid value. |
| **TAPI_E_INVALCALLSTATE** | The current [call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) is not valid for this operation. |

## See also

[CALLINFO_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_buffer)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[GetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-getcallinfobuffer)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[get_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfobuffer)

[put_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfobuffer)