# CItemIDFactory::GetPropertyStorage

## Description

Gets a read only pointer to the serialized property storage that is used for storing metadata.

## Parameters

### `pidl` [in, optional]

A PIDL that contains the location of the property storage.

### `pcb` [out]

When this method returns, contains the size, in bytes, of the storage.

## Return value

If this method succeeds, it returns a read only pointer to the serialized property storage.

## See also

[CItemIDFactory](https://learn.microsoft.com/windows/desktop/api/shidfact/nl-shidfact-citemidfactory)