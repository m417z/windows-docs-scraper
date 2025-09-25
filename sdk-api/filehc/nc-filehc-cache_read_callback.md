# CACHE_READ_CALLBACK callback function

## Description

A callback that is provided to the cache to help examine items within the cache.

## Parameters

### `cb` [in]

The size, in bytes, of the data indicated in the *lpb* parameter.

### `lpb` [in]

A pointer to the data portion of the key.

### `lpvContext` [in]

The context that is specified by the user.

## Return value

Returns **TRUE** if the function succeeds; otherwise, it returns **FALSE**.

**Note** This return value is ignored.