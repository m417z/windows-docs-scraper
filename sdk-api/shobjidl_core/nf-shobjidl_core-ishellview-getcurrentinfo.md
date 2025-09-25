# IShellView::GetCurrentInfo

## Description

Gets the current folder settings.

## Parameters

### `pfs`

Type: **LPFOLDERSETTINGS**

The address of a [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure to receive the settings.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

Windows Explorer uses this method to query the view for standard settings.

### Note to Calling Applications

This method is used to retrieve the current view settings of the view.

### Notes to Implementers

Return as many of the settings as apply. This is intended to maintain the same basic settings when the user browses from view to view. For example, if the user sets the Details view, that view should be maintained as the user goes from one folder to the other in Windows Explorer mode.

## See also

[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)