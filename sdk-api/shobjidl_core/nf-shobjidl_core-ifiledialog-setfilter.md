# IFileDialog::SetFilter

## Description

[Deprecated. **SetFilter** is no longer available for use as of Windows 7.]

Sets the filter.

## Parameters

### `pFilter`

Type: **[IShellItemFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemfilter)***

A pointer to the [IShellItemFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemfilter) that is to be set.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be used if the application needs to perform special filtering to remove some items from the dialog box's view. [IncludeItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitemfilter-includeitem) will be called for each item that would normally be included in the view. [GetEnumFlagsForItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitemfilter-getenumflagsforitem) is not used.
To filter by file type, [IFileDialog::SetFileTypes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfiletypes) should be used, because in folders with a large number of items it may offer better performance than applying an [IShellItemFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemfilter).