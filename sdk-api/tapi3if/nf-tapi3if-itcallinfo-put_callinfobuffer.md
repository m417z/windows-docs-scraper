# ITCallInfo::put_CallInfoBuffer

## Description

The
**put_CallInfoBuffer** method sets call information items which require a buffer, such as user-user information. This method is provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[ITCallInfo::SetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-setcallinfobuffer) method.

## Parameters

### `CallInfoBuffer` [in]

[CALLINFO_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_buffer) indicator of information type, such as CIB_USERUSERINFO.

### `pCallInfoBuffer` [in]

**VARIANT**

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_INVALIDARG** | The *CallInfoBuffer* parameter is not a valid value. |
| **TAPI_E_INVALCALLSTATE** | The current [call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) is not valid for this operation. |

## See also

[CALLINFO_BUFFER](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_buffer)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[GetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-getcallinfobuffer)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[SetCallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-setcallinfobuffer)

[get_CallInfoBuffer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfobuffer)