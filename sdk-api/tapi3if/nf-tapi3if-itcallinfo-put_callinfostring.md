# ITCallInfo::put_CallInfoString

## Description

The
**put_CallInfoString** method sets call information items described by a string, such as the displayable address.

## Parameters

### `CallInfoString` [in]

[CALLINFO_STRING](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_string) indicator of information type, such as CIS_DISPLAYABLEADDRESS.

### `pCallInfoString` [in]

Pointer to a BSTR representation of the string.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_INVALIDARG** | The *CallInfoString* parameter is not a valid value. |
| **TAPI_E_INVALCALLSTATE** | The current [call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) is not valid for this operation. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the string data referenced by *pCallInfoString* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

## See also

[CALLINFO_STRING](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callinfo_string)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[get_CallInfoString](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callinfostring)