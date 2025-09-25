# IAccServerDocMgr::RevokeDocument

## Description

Server applications call the **IAccServerDocMgr::RevokeDocument** method to notify the Microsoft Active Accessibility run time that a document is no longer available. Calling **RevokeDocument** removes it from the store so that clients cannot see the document.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `punk` [in]

Type: **IUnknown***

An interface pointer to the document being revoked.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.