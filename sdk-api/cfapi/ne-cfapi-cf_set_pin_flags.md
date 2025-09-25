# CF_SET_PIN_FLAGS enumeration

## Description

The placeholder pin flags.

## Constants

### `CF_SET_PIN_FLAG_NONE:0x00000000`

No pin flag.

### `CF_SET_PIN_FLAG_RECURSE:0x00000001`

The platform applies the pin state to the placeholder *FileHandle* and every file recursively beneath it (relevant only if *FileHandle* is a handle to a directory).

### `CF_SET_PIN_FLAG_RECURSE_ONLY:0x00000002`

The platform applies the pin state to every file recursively beneath the placeholder *FileHandle*, but not to *FileHandle* itself.

### `CF_SET_PIN_FLAG_RECURSE_STOP_ON_ERROR:0x00000004`

The platform will stop the recursion when encountering the first error; otherwise the platform skips the error and continues the recursion.

## See also

[CfSetPinState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate)