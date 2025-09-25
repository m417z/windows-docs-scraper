# IMsmMerge2::CreateSourceImage

## Description

The
**CreateSourceImage** method enables the client to extract the files from a module to a source image on disk after a merge, taking into account changes to the module that might have been made during module configuration. For more information, see the
[CreateSourceImage](https://learn.microsoft.com/windows/desktop/Msi/merge-createsourceimage) method of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

## Parameters

### `Path` [in]

The path of the root of the source image for the install.

### `fLongFileNames` [in]

*fLongFileNames* determines whether or not long file names are used for both path segments and final file names.

### `pFilePaths` [out]

A pointer to a memory location. This memory location receives a second pointer to a string enumerator containing a list of fully qualified paths for the files that were extracted. The list is empty if no files can be extracted. This argument may be null. No list is provided if *pFilePaths* is Null.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)