# ITfLangBarMgr::UnadviseEventSink

## Description

Uninstalls an advise event sink.

## Parameters

### `dwCookie` [in]

A DWORD value that identifies the advise event sink to uninstall. This value is provided by a previous call to [ITfLangBarMgr::AdviseEventSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbarmgr-adviseeventsink).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfLangBarMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbarmgr)

[ITfLangBarMgr::AdviseEventSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbarmgr-adviseeventsink)

[Thread Manager](https://learn.microsoft.com/windows/desktop/TSF/thread-manager)