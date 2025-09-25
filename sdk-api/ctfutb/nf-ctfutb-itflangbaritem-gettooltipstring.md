# ITfLangBarItem::GetTooltipString

## Description

Obtains the text to be displayed in the tooltip for the language bar item.

## Parameters

### `pbstrToolTip` [out]

Pointer to a **BSTR** value that receives the tooltip string for the language bar item. This string must be allocated using the [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) function. The caller must free this buffer when it is no longer required by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pbstrToolTip* is invalid. |
| **E_NOTIMPL** | The language bar item does not support tooltip text. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring)

[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring)