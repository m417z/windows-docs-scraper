# MI_Class_GetServerName function

## Description

Gets the name of the server from the specified class.

## Parameters

### `self` [in]

A pointer to the class from which to retrieve the server name.

### `serverName`

A pointer to a pointer to the returned server name. This string is owned by the class and does not need to be deleted.

## Return value

This function returns MI_INLINE MI_Result.