# ITfLangBarItemMgr::AddItem

## Description

Adds an item to the language bar.

## Parameters

### `punk` [in]

Pointer to the [ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem) object to add to the language bar.

Starting with Windows 8, only the first item that returns GUID_LBI_INPUTMODE (from [GetInfo](https://learn.microsoft.com/windows/win32/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo)) is shown. For more information, see [Third-party input method editors](https://docs.microsoft.com/en-us/windows/win32/w8cookbook/third-party-input-method-editors#manifestation) in the Compatibility cookbook for Windows.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful (silently ignored calls also return this status). |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *punk* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)