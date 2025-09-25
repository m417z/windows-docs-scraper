# PrjFillDirEntryBuffer function

## Description

Provides information for one file or directory to an enumeration.

## Parameters

### `fileName` [in]

A pointer to a null-terminated string that contains the name of the entry

### `fileBasicInfo` [in, optional]

Basic information about the entry to be filled.

### `dirEntryBufferHandle` [in]

An opaque handle to a structure that receives information about the filled entries.

## Return value

HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) indicates that dirEntryBufferHandle doesn't have enough space for the new entry.

## Remarks

The provider uses this routine to service a [PRJ_GET_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_directory_enumeration_cb) callback. When processing the callback, the provider calls this routine for each matching file or directory in the enumeration.

If this routine returns HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) when adding an entry to the enumeration, the provider returns S_OK from the callback and waits for the next [PRJ_GET_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_directory_enumeration_cb) callback.

The provider resumes filling the enumeration with the entry it was trying to add when it got HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER).

If this routine returns HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) for the first entry added during any invocation of a [PRJ_GET_DIRECTORY_ENUMERATION_CB](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nc-projectedfslib-prj_get_directory_enumeration_cb) callback, the provider must return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) from the callback.