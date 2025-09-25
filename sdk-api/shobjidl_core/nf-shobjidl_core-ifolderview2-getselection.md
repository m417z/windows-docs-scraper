# IFolderView2::GetSelection

## Description

Gets the current selection as an IShellItemArray.

## Parameters

### `fNoneImpliesFolder` [in]

Type: **BOOL**

If **TRUE**, this method returns an IShellItemArray containing the parent folder when there is no current selection.

### `ppsia` [out]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)****

The address of a pointer to an IShellItemArray.

## Return value

Type: **HRESULT**

Returns one of the following values, or an error otherwise.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **S_FALSE** | The IShellItemArray returned has zero items. |