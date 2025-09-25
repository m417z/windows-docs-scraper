# CACHE_DESTROY_CALLBACK callback function

## Description

A function that is called whenever an entry in the name cache is destroyed. It provides the client with an opportunity to track any relationships between the key and data components.

## Parameters

### `cb` [in]

The size of the data or key pointed to by the *lpb* parameter, in bytes.

### `lpb` [in]

A pointer to the data or key.

## Remarks

If the client does not associate data with the name, this function is called only for the key data.