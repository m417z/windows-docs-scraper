# IAccServerDocMgr::OnDocumentFocus

## Description

Applications that use Text Services Framework call **IAccServerDocMgr::OnDocumentFocus** to notify the Microsoft Active Accessibility run time when a document gets or loses focus. The store keeps this information so that clients can access the document that has focus.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `punk` [in]

Type: **IUnknown***

An interface pointer to the document getting focus.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

## Remarks

This can be null indicating that no document has focus.