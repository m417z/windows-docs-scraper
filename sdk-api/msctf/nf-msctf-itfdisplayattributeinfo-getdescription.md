# ITfDisplayAttributeInfo::GetDescription

## Description

Obtains the description string of the display attribute.

## Parameters

### `pbstrDesc` [out]

Pointer to a BSTR value that receives the description string. This value must be allocated using [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The caller must free this memory using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pbstrDesc* is invalid. |

## See also

[ITfDisplayAttributeInfo interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfdisplayattributeinfo), [SysAllocString function](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysallocstring), [SysFreeString function](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring)