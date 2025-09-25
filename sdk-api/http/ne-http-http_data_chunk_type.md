## Description

Defines the data source for a data chunk.

## Constants

### `HttpDataChunkFromMemory`

The data source is a memory data block. The union should be interpreted as a **FromMemory** structure.

### `HttpDataChunkFromFileHandle`

The data source is a file handle data block. The union should be interpreted as a **FromFileHandle** structure.

### `HttpDataChunkFromFragmentCache`

The data source is a fragment cache data block. The union should be interpreted as a **FromFragmentCache** structure.

### `HttpDataChunkFromFragmentCacheEx`

The data source is a fragment cache data block. The union should be interpreted as a **FromFragmentCacheEx** structure.

**Windows Server 2003 with SP1 and Windows XP with SP2:** This flag is not supported.

### `HttpDataChunkTrailers`

The data source is a trailers data block. The union should be interpreted as a **Trailers** structure.

**Windows 10, version 2004 and prior:** This flag is not supported.

### `HttpDataChunkMaximum`