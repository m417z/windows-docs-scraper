# ResUtilSetValueEx function

## Description

Sets a value in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

A key that identifies the location of the value in the cluster database.

### `valueName` [in]

A Null-terminated Unicode string that contains the name of the value to update.

### `valueType` [in]

A flag that indicates the type of the value to update.

### `valueData` [in]

A pointer to the new data for the value.

### `valueSize` [in]

The size of the new value, in bytes.

### `flags` [in]

The flags that specify settings for the operation.

## Return value

Returns **ERROR_SUCCESS** if the operation succeeds; otherwise, returns a system error code.