# IFolderView::GetSpacing

## Description

Gets a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the width (x) and height (y) dimensions, including the surrounding white space, of an item.

## Parameters

### `ppt` [in, out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

A pointer to an existing structure to be filled with the current sizing dimensions of the items in the folder's view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

As an example, consider an icon measuring 75 pixels by 70 pixels, with its upper-left corner located at pixel (0,0). Note that this measurement includes both the visible graphic and its surrounding buffer area. **IFolderView::GetSpacing** would return a pointer to a POINT structure containing an x value of 75 and a y value of 70. If you were using this information to avoid overlap, the next icon in line to the right would be placed with its upper-left corner at pixel (75,0). Similarly, the next icon below would be placed at pixel (0,70).

## See also

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::GetDefaultSpacing](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-getdefaultspacing)