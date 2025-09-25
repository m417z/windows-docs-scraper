# ITfLangBarItemMgr::UnadviseItemSink

## Description

Removes a language bar item event sink.

## Parameters

### `dwCookie` [in]

Contains a *DWORD* that identifies the advise sink to remove. This cookie is obtained when the advise sink is installed with [ITfLangBarItemMgr::AdviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemsink) or [ITfLangBarItemMgr::AdviseItemsSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemssink).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[ITfLangBarItemMgr::AdviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemsink)

[ITfLangBarItemMgr::AdviseItemsSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemssink)