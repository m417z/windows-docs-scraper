# ITCallInfo::get_CallInfoLong

## Description

The
**get_CallInfoLong** method gets call information items described by a long, such as the bearer mode.

## Parameters

### `CallInfoLong` [in]

[CALLINFO_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_long) indicator of information type needed, such as CIL_BEARERMODE.

### `plCallInfoLongVal` [out]

Pointer to value returned.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plCallInfoLongVal* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *CallInfoLong* parameter is not a valid value. |
| **TAPI_E_INVALCALLSTATE** | The current [call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) is not valid for this operation. |

## See also

[CALLINFO_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_long)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[put_CallInfoLong](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-put_callinfolong)