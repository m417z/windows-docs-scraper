# SHCOLUMNINIT structure

## Description

Passes initialization information to [IColumnProvider::Initialize](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-icolumnprovider-initialize).

## Members

### `dwFlags`

Type: **ULONG**

Initialization flags. Reserved. Set to **NULL**

### `dwReserved`

Type: **ULONG**

Reserved. Set to **NULL**.

### `wszFolder`

Type: **WCHAR[MAX_PATH]**

A pointer to a null-terminated Unicode string with a fully qualified folder path. The string will be empty if multiple folders are specified.