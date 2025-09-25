# SHQUERYRBINFO structure

## Description

Contains the size and item count information retrieved by the [SHQueryRecycleBin](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shqueryrecyclebina) function.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes. This member must be filled in prior to calling the function.

### `i64Size`

Type: **__int64**

The total size of all the objects in the specified Recycle Bin, in bytes.

### `i64NumItems`

Type: **__int64**

The total number of items in the specified Recycle Bin.