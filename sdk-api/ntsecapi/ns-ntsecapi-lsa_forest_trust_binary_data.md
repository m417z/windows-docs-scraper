# LSA_FOREST_TRUST_BINARY_DATA structure

## Description

The **LSA_FOREST_TRUST_BINARY_DATA** structure contains binary data used in [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) forest trust operations.

## Members

### `Length.range`

### `Length.range.0`

### `Length.range.MAX_FOREST_TRUST_BINARY_DATA_SIZE`

### `Buffer.size_is`

### `Buffer.size_is.Length`

### `Length`

Size of the structure in bytes.

### `Buffer`

Pointer to an array of type **UCHAR** that contains the binary data. The buffer can contain at most 128 KB of data.