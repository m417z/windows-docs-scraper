# ITfLangBarItemMgr::GetItemFloatingRect

## Description

Obtains the bounding rectangle of an item on the language bar.

## Parameters

### `dwThreadId` [in]

Not currently used. Must be zero.

### `rguid` [in]

Contains the **GUID** that identifies the item to obtain the bounding rectangle for. This is the item **GUID** that the item supplies in [ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo). This can be a custom value or one of the [predefined language bar items](https://learn.microsoft.com/windows/desktop/TSF/predefined-lang-bar-items).

### `prc` [out]

Pointer to a **RECT** structure that receives the bounding rectangle in screen coordinates.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *prc* is invalid. |

## See also

[ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[Predefined language bar items](https://learn.microsoft.com/windows/desktop/TSF/predefined-lang-bar-items)