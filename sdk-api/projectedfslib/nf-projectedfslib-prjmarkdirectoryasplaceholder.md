# PrjMarkDirectoryAsPlaceholder function

## Description

Converts an existing directory to a directory placeholder.

## Parameters

### `rootPathName` [in]

A null-terminated Unicode string specifying the full path to the virtualization root.

### `targetPathName` [in, optional]

A null-terminated Unicode string specifying the full path to the directory to convert to a placeholder.

If this parameter is not specified or is an empty string, then this means the caller wants to designate rootPathName as the virtualization root. The provider only needs to do this one time, upon establishing a new virtualization instance.

### `versionInfo` [in, optional]

Optional version information for the target placeholder. The provider chooses what information to put in the [PRJ_PLACEHOLDER_VERSION_INFO](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ns-projectedfslib-prj_placeholder_version_info) structure. If not specified, the placeholder gets zeros for its version information.

### `virtualizationInstanceID` [in]

A value that identifies the virtualization instance.

## Return value

HRESULT_FROM_WIN32(ERROR_REPARSE_POINT_ENCOUNTERED) typically means the directory at targetPathName has a reparse point on it. HRESULT_FROM_WIN32(ERROR_DIRECTORY) typically means the targetPathName does not specify a directory.

## Remarks

The provider must use this API to designate the virtualization root before calling [PrjStartVirtualizing](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjstartvirtualizing).