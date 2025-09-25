## Description

Displays a file. The Shell specifies the name of the file to display by calling the file viewer's [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load) method.

## Parameters

### `pvsi`

A pointer to an [FVSHOWINFO](https://learn.microsoft.com/windows/desktop/api/shlobj/ns-shlobj-fvshowinfo) structure to contain information that the file viewer uses to display the file. A file viewer can return information to the Shell by modifying the members of the structure.

## Return value

Returns S_OK if successful, or E_UNEXPECTED if the [ShowInitialize](https://learn.microsoft.com/windows/win32/api/shlobj/nf-shlobj-ifileviewera-showinitialize) method was not called before **IFileViewerA::Show**.

## Remarks

## See also