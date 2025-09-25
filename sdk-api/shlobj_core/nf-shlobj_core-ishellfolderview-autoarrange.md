# IShellFolderView::AutoArrange

## Description

[**AutoArrange** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Arranges moved icons so that they tend toward the left side of the viewing area and displace other icons with which they come into contact.

## Return value

Type: **HRESULT**

Returns S_OK if successful, S_FALSE if the view is not in Auto Arrange mode, or an error value otherwise.

## Remarks

This method has the same effect as selecting **View | Arrange Icons By | Auto Arrange** in Windows Explorer on Windows XP, and also the same as right-clicking the desktop and selecting **Arrange Icons By | Auto Arrange** on Windows XP or Windows Vista.

## See also

[IShellFolderView](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderview)

[IShellFolderView::ArrangeGrid](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishellfolderview-arrangegrid)