# LSA_UNICODE_STRING structure

## Description

The **LSA_UNICODE_STRING** structure is used by various [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) functions to specify a [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) string.

## Members

### `Length`

Specifies the length, in bytes, of the string pointed to by the **Buffer** member, not including the terminating null character, if any.

### `MaximumLength`

Specifies the total size, in bytes, of the memory allocated for **Buffer**. Up to **MaximumLength** bytes can be written into the buffer without trampling memory.

### `Buffer`

Pointer to a wide character string. Note that the strings returned by the various LSA functions might not be null-terminated.

### `Buffer.size_is`

### `Buffer.size_is.MaximumLength/2`

### `Buffer.length_is`

### `Buffer.length_is.Length/2`