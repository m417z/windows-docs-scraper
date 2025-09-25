# ITfLangBarItemButton::GetText

## Description

Obtains the text to be displayed for the button in the language bar.

## Parameters

### `pbstrText` [out]

Pointer to a **BSTR** that receives the string for the language bar item. This string must be allocated using the [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) function. The caller must free this buffer when it is no longer required by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pbstrText* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfLangBarItemButton](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritembutton)

[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)