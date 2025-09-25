# ITfLangBarItemMgr::UnadviseItemsSink

## Description

Removes one or more language bar item event sinks.

## Parameters

### `ulCount` [in]

Contains the number of advise sinks to install.

### `pdwCookie` [in]

Pointer to an array of **DWORD**s that identify the advise sinks to remove. These cookies are obtained when the advise sinks are installed with [ITfLangBarItemMgr::AdviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemsink) or [ITfLangBarItemMgr::AdviseItemsSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemssink). This array must be at least *ulCount* elements in length.

## Return value

This method has no return values.

## See also

[ITfLangBarItemMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbaritemmgr)

[ITfLangBarItemMgr::AdviseItemSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemsink)

[ITfLangBarItemMgr::AdviseItemsSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbaritemmgr-adviseitemssink)