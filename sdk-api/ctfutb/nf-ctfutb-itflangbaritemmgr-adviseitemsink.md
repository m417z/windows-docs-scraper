# ITfLangBarItemMgr::AdviseItemSink

## Description

Installs a language bar item event sink for a language bar item.

## Parameters

### `punk` [in]

Pointer to the [ITfLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemsink) object to install.

### `pdwCookie` [out]

Pointer to a **DWORD** that receives an advise sink identification cookie. This cookie identifies the advise sink when it is removed with the [ITfLangBarItemMgr::UnadviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-unadviseitemsink) or [ITfLangBarItemMgr::UnadviseItemsSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-unadviseitemssink) method.

### `rguidItem` [in]

Contains the **GUID** that identifies the item to install the advise sink for. This is the item **GUID** that the item supplies in [ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo). This can be a custom value or one of the [predefined language bar items](https://learn.microsoft.com/windows/desktop/TSF/predefined-lang-bar-items).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | *rguidItem* is invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |
| **E_POINTER** | *punk* and/or *pdwCookie* is invalid. |

## See also

[ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[ITfLangBarItemMgr::UnadviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-unadviseitemsink)

[ITfLangBarItemMgr::UnadviseItemsSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-unadviseitemssink)

[ITfLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemsink)

[Predefined language bar items](https://learn.microsoft.com/windows/desktop/TSF/predefined-lang-bar-items)