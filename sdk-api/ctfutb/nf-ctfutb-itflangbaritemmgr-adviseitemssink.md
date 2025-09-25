# ITfLangBarItemMgr::AdviseItemsSink

## Description

Installs one or more language bar item event sinks for one or more language bar items.

## Parameters

### `ulCount` [in]

Contains the number of advise sinks to install.

### `ppunk` [in]

Pointer to an array of [ITfLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemsink) objects to install. This array must be at least *ulCount* elements in length.

### `pguidItem` [in]

Pointer to an array of **GUID**s that identify the items to install the advise sinks for. These are the item **GUID**s that the item supplies in [ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo). This array must be at least *ulCount* elements in length.

### `pdwCookie` [out]

Pointer to an array of **DWORD**s that receive the corresponding advise sink identification cookies. These cookies identify the advise sinks when they are removed with the [ITfLangBarItemMgr::UnadviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-unadviseitemsink) or [ITfLangBarItemMgr::UnadviseItemsSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-unadviseitemssink) method. This array must be at least *ulCount* elements in length.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfLangBarItem::GetInfo](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritem-getinfo)

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[ITfLangBarItemMgr::UnadviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-unadviseitemsink)

**ITfLangBarItemMgr::UnadviseItemsSink**

[ITfLangBarItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemsink)