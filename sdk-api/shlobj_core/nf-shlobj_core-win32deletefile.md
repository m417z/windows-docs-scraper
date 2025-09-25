# Win32DeleteFile function

## Description

[**Win32DeleteFile** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Deletes a file.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a buffer that contains the full name of the file to delete.

## Return value

Type: **BOOL**

**TRUE** if the file was successfully deleted; otherwise **FALSE**.