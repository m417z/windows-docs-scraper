# SECURITY_STRING structure

## Description

The **SECURITY_STRING** structure is used as the string interface for kernel operations and is a clone of the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/subauth/ns-subauth-unicode_string) structure. This is used for 32-bit mode.

## Members

### `Length`

Specifies the length, in bytes, of the string pointed to by the **Buffer** member, not including the terminating **NULL** character, if any.

### `MaximumLength`

Specifies the total size, in bytes, of memory allocated for **Buffer**. Up to **MaximumLength** bytes may be written into the buffer without trampling memory.

### `Buffer`

Pointer to a wide-character string. Note that the strings returned by the various LSA functions might not be **NULL**-terminated.

### `Buffer.size_is`

### `Buffer.size_is.MaximumLength/2`

### `Buffer.length_is`

### `Buffer.length_is.Length/2`

## Remarks

## See also