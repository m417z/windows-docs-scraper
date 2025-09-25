## Description

Loads the migration table at a specified path.

## Parameters

### `bstrMigrationTablePath` [in]

The path of the migration table to be loaded. Use a null-terminated string.

### `ppMigrationTable`

The migration table interface that contains the entries from the migration table.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMMigrationTable** object.

### VB

Returns a reference to a **GPMMigrationTable** object.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMMigrationTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmmigrationtable)