# ICommDlgBrowser::IncludeObject

## Description

Allows the common dialog box to filter objects that the view displays.

## Parameters

### `ppshv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the view's [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface.

### `pidl`

Type: **LPCITEMIDLIST**

A PIDL, relative to the folder, that identifies the object.

## Return value

Type: **HRESULT**

The browser should return S_OK to include the object in the view, or S_FALSE to hide it.

## Remarks

This method is called by the [IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist) implementation when hosted in file dialog boxes. The enumerator calls this method to let the common dialog box filter out objects that should not be displayed. Typically, the file dialog boxes will get the display text of the item, and filter by the extension.

### Note to Calling Applications

Call this method before returning an object in the Shell folder's IDLIST enumerator.

When dealing with data sources that have many items, such as libraries and searches, the callback to this method results in poor performance. To avoid that situation, implement [GetViewFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icommdlgbrowser2-getviewflags) and return CDB2GVF_NOINCLUDEITEM. Doing so enables the view to skip calling **ICommDlgBrowser::IncludeObject**, thereby improving performance.

## See also

[Explorer Browser Search Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940358(v=vs.85))

[ICommDlgBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icommdlgbrowser)