# IAccClientDocMgr::LookupByHWND

## Description

Clients call **IAccClientDocMgr::LookupByHWND** to get a document by providing the **HWND** for the document.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `hWnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The **HWND** of the document to be returned.

### `riid` [in]

Type: **REFIID**

IID of the document being requested. This is usually IID_ITextStoreAnchor.

### `ppunk` [out]

Type: **IUnknown***

Interface pointer to the document being requested.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns the following value or another standard COM error code.

| Error | Description |
| --- | --- |
| **E_FAIL** | If the **HWND** does not correspond to an active document, then *ppunk* will be **NULL**. |

## Remarks

Servers might need to poll this method more than once before they receive a document. There can be a limited time lapse (approximately second) between when a document appears in the system and when it is registered with document services.