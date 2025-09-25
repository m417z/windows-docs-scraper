# ITfFunction::GetDisplayName

## Description

Obtains the function display name.

## Parameters

### `pbstrName` [out]

Pointer to a BSTR value that receives the display name. This value must be allocated using [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The caller must free this memory using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_INVALIDARG** | *pbstrName* is invalid. |

## See also

[ITfFunction](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itffunction)

[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)