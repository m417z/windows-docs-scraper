# ITfLangBarMgr::AdviseEventSink

## Description

The **ITfLangBarMgr::AdviseEventSink** method advises a sink about a language bar event.

## Parameters

### `pSink` [in]

Sink object to advise about the event.

### `hwnd` [in]

Reserved; must be **NULL**.

### `dwFlags` [in]

Reserved; must be 0.

### `pdwCookie` [in]

Pointer to an identifier for the connection.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pSink* is invalid. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

*pdwCookie* receives an identifier that should be passed to [ITfLangBarMgr::UnadviseEventSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbarmgr-unadviseeventsink) when the event sink is no longer required.

## See also

[ITfLangBarMgr](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbarmgr)

[ITfLangBarMgr::UnadviseEventSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nf-ctfutb-itflangbarmgr-unadviseeventsink)

[Thread Manager](https://learn.microsoft.com/windows/desktop/TSF/thread-manager)