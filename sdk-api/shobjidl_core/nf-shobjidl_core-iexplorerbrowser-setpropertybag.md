# IExplorerBrowser::SetPropertyBag

## Description

Sets the name of the property bag.

## Parameters

### `pszPropertyBag` [in]

Type: **LPCWSTR**

A pointer to a constant, null-terminated, Unicode string that contains the name of the property bag.
View state information that is specific to the application of the client is stored (persisted) using this name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

ExplorerBrowser can retrieve the properties stored in the property bag by calling function [SHGetViewStatePropertyBag](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shgetviewstatepropertybag).
ExplorerBrowser writes to this property bag which is also stored (persisted) in the registry. Persistence occurs automatically when ExplorerBrowser destroys the current view, begins a navigation, or is destroyed. After any of these events, it writes information about the view state in case it has been modified by the user.

 If no properties have been stored, the default view state of the ExplorerBrowser is used. The default view state is the view state that the user has set for a particular location, or if the view state for a location has not been set (never modified by the user), then the default view state is based on the template for the file type (for example, documents, music and pictures) at the location. All Explorer windows use the same sequence to determine the default view state.