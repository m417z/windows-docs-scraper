# InvalidateName function

## Description

Enables the user to remove a single name and all associated data from the name cache.

## Parameters

### `pNameCache` [in]

A pointer to the name cache that the client will use.

### `lpbName` [in]

The bytes that the user provides for the name of the cache item.

### `cbName` [in]

The actual byte count of the name.

## Return value

Returns **TRUE** if the name and associated data are removed from the name cache; otherwise, it returns **FALSE**.