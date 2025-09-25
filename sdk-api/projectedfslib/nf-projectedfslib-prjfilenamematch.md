# PrjFileNameMatch function

## Description

Determines whether a file name matches a search pattern.

## Parameters

### `fileNameToCheck` [in]

A null-terminated Unicode string of at most MAX_PATH characters specifying the file name to check against pattern.

### `pattern` [in]

A null-terminated Unicode string of at most MAX_PATH characters specifying the pattern to compare against fileNameToCheck.

## Return value

True if fileNameToCheck matches pattern, False otherwise.

## Remarks

The provider must use this routine when processing a [PRJ_GET_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_directory_enumeration_cb) callback to determine whether a name in its backing store matches the searchExpression passed to the callback. This routine performs pattern matching in the same way the file system does when it is processing a directory enumeration