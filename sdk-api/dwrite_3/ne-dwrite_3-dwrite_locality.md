# DWRITE_LOCALITY enumeration

## Description

Specifies the location of a resource.

## Constants

### `DWRITE_LOCALITY_REMOTE`

The resource is remote, and information about it is unknown, including the file size and date. If you attempt to create a font or file stream, the creation will fail until locality becomes at least partial.

### `DWRITE_LOCALITY_PARTIAL`

The resource is partially local, which means you can query the size and date of the file stream. With this type, you also might be able to create a font face and retrieve the particular glyphs for metrics and drawing, but not all the glyphs will be present.

### `DWRITE_LOCALITY_LOCAL`

The resource is completely local, and all font functions can be called without concern of missing data or errors related to network connectivity.