# IAccClientDocMgr::GetFocused

## Description

Clients call the **IAccClientDocMgr::GetFocused** method to access a pointer for the document that has focus.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `riid` [in]

Type: **REFIID**

IID of the document being requested. This is usually IID_ITextStoreAnchor.

### `ppunk` [out]

Type: **IUnknown***

Interface pointer to the document being requested.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

If the window that has focus is not a document that implements the [ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp) interface, *ppunk* will be **NULL**.

Servers might need to poll this method more than once before they receive a document. There can be a limited time lapse (approximately second) between when a document appears in the system and when it is registered with document services.