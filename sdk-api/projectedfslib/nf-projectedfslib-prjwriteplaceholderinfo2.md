# PrjWritePlaceholderInfo2 function

## Description

Sends file or directory metadata to ProjFS and allows the caller to specify extended information.

## Parameters

### `namespaceVirtualizationContext` [in]

Opaque handle for the virtualization instance. This must be the value from the VirtualizationInstanceHandle member of the callbackData passed to the provider in the [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback.

### `destinationFileName` [in]

A null-terminated Unicode string specifying the path, relative to the virtualization root, to the file or directory for which to create a placeholder.

This must be a match to the FilePathName member of the callbackData parameter passed to the provider in the [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback. The provider should use the PrjFileNameCompare function to determine whether the two names match.

For example, if the [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback specifies “dir1\dir1\FILE.TXT” in callbackData->FilePathName, and the provider’s backing store contains a file called “File.txt” in the dir1\dir2 directory, and [PrjFileNameCompare](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjfilenamecompare) returns 0 when comparing the names “FILE.TXT” and “File.txt”, then the provider specifies “dir1\dir2\File.txt” as the value of this parameter.

### `placeholderInfo` [in]

A pointer to the metadata for the file or directory.

### `placeholderInfoSize` [in]

Size in bytes of the buffer pointed to by placeholderInfo.

### `extendedInfo`

A pointer to a [PRJ_EXTENDED_INFO](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_extended_info) struct specifying extended information about the placeholder to be created.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The provider uses this routine to provide the data requested in an invocation of its [PRJ_GET_PLACEHOLDER_INFO_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_placeholder_info_cb) callback, or it may use it to proactively lay down a placeholder.

The EaInformation, SecurityInformation, and StreamsInformation members of [PRJ_PLACEHOLDER_INFO](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_placeholder_info) are optional. If the provider does not wish to provide extended attributes, custom security descriptors, or alternate data streams, it must set these fields to 0.

### Symbolic Links

To specify that this placeholder is to be a symbolic link, the provider formats a buffer with a single [PRJ_EXTENDED_INFO](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_extended_info) struct and passes a pointer to it in the `extendedInfo` parameter. The provider sets the struct's fields as follows:

* `extendedInfo.InfoType = PRJ_EXT_INFO_TYPE_SYMLINK`
* `extendedInfo.NextInfoOffset = 0`
* `extendedInfo.Symlink.TargetName = `

## See also