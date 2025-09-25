# ITfLangBarItemMgr::GetItem

## Description

Obtains the ITfLangBarItem interface for an item in the language bar.

## Parameters

### `rguid` [in]

GUID that identifies the item to obtain. This is the item GUID that the item supplies in [ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo). This identifier can be a custom value or one of the [predefined language bar items](https://learn.microsoft.com/windows/desktop/TSF/predefined-lang-bar-items).

### `ppItem` [out]

Pointer to an [ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem) interface pointer that receives the item interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The item cannot be found. |
| **E_INVALIDARG** | The *ppItem* parameter is invalid. |

## See also

[ITfLangBarItem](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritem)

[ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[Predefined language bar items](https://learn.microsoft.com/windows/desktop/TSF/predefined-lang-bar-items)