## Description

Allows a file viewer to determine whether it can display a file and, if it can, to perform initialization operations before showing the file.

## Parameters

### `lpfsi`

A pointer to an [IFileViewerSite](https://learn.microsoft.com/windows/win32/api/shlobj/nn-shlobj-ifileviewersite) interface. A file viewer uses this interface to retrieve the handle to the current pinned window or to specify a new pinned window.

## Return value

The Shell calls this method before the [IFileViewerW::Show](https://learn.microsoft.com/windows/win32/api/shlobj/nf-shlobj-ifileviewerw-show) method. The Shell specifies the name of the file to display by calling the file viewer's [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load) method.

## Remarks

## See also