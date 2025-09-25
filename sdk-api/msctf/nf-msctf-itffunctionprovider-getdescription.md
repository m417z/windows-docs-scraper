# ITfFunctionProvider::GetDescription

## Description

Obtains the description of the function provider.

## Parameters

### `pbstrDesc` [out]

Pointer to a BSTR that receives the description string. This value must be allocated using [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The caller must this memory using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_INVALIDARG** | *pbstrDesc* is invalid. |

## See also

[ITfFunctionProvider](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itffunctionprovider)

[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)