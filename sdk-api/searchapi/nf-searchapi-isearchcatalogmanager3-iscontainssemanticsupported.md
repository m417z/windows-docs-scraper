## Description

Returns a Boolean value that indicates whether the [CONTAINSSEMANTIC](https://learn.microsoft.com/windows/win32/search/-search-sql-containssemantic) SQL predicate is supported on the current device.

## Parameters

### `isContainsSemanticSupported` [out]

TRUE if semantic SQL predicates are supported on the current device; otherwise, FALSE.

## Return value

Returns S_OK on success. Otherwise it returns an error code.

## Remarks

Starting with Windows 11, build 26100, Windows Search queries can include new SQL syntax that enables searching for semantically-related items. The semantic search syntax includes the **CONTAINSSEMANTIC** predicate and [MERGE](https://learn.microsoft.com/windows/win32/search/-search-sql-rankby#mergemerge_operation) operations. Older versions of Windows do not support this syntax. **IsContainsSemanticSupported** allows apps to confirm that **CONTAINSSEMANTIC** is supported on the current device before executing queries that use this predicate.

## See also