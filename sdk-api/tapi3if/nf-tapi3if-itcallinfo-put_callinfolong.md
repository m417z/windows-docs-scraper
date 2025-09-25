# ITCallInfo::put_CallInfoLong

## Description

The
**put_CallInfoLong** method sets call information items described by a long, such as the bearer mode.

## Parameters

### `CallInfoLong` [in]

[CALLINFO_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_long) indicator of information type needed, such as CIL_BEARERMODE.

### `lCallInfoLongVal` [in]

Pointer to new value.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_INVALIDARG** | The *CallInfoLong* parameter is not a valid value. |
| **TAPI_E_INVALCALLSTATE** | The current [call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) is not valid for this operation. |

## See also

[CALLINFO_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_long)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[get_CallInfoLong](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfolong)