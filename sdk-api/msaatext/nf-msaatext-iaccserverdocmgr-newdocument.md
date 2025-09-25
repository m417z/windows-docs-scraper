# IAccServerDocMgr::NewDocument

## Description

Server applications call the **IAccServerDocMgr::NewDocument** method when it is available. The adapter creates a wrapped document and registers it with the store, so clients can access information about the text in the document.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `riid` [in]

Type: **REFIID**

IID of the document. This is usually IID_ITextStoreAnchor.

### `punk`

Type: **IUnknown***

[in, iid_is(riid)] An interface pointer to the document.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

The server application calls the **IAccServerDocMgr::NewDocument** method to notify the Microsoft Active Accessibility run time that a document is available. Calling **NewDocument** adds the document to the Microsoft Active Accessibility store so that clients can access the document.