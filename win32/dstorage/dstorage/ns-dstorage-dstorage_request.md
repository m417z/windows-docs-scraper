# DSTORAGE_REQUEST structure (dstorage.h)

Represents a DirectStorage request.

## Members

`Options`

Combination of decompression and other options for this request.

`Source`

The source for this request.

`Destination`

The destination for this request.

`UncompressedSize`

The uncompressed size in bytes for the destination for this request. If the request is not compressed, then this can be left as 0. Otherwise, this should be equal to the destination size.

If the destination is to memory or buffer, then the destination size should be specified in the corresponding struct (for example, [DSTORAGE_DESTINATION_MEMORY](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_destination_memory)). For textures, it's the value of *pTotalBytes* returned by [GetCopyableFootprints](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-getcopyablefootprints). For tiles, it's 64k * number of tiles.

`CancellationTag`

An arbitrary **UINT64** number used for cancellation matching.

`Name`

Optional name of the request. Used for debugging. If specified, the string should be accessible until the request completes.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |