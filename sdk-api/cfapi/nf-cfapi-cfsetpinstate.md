# CfSetPinState function

## Description

This sets the pin state of a placeholder, used to represent a user’s intent. Any application (not just the sync provider) can call this function.

## Parameters

### `FileHandle` [in]

The handle of the placeholder file. The platform properly synchronizes the operation with other active requests. An attribute or no-access handle is sufficient. The caller must have **READ_DATA** or **WRITE_DAC** access to the placeholder, otherwise the operation will be failed with **STATUS_CLOUD_FILE_ACCESS_DENIED**.

### `PinState` [in]

The pin state of the placeholder file. For a list of valid *PinState* values, see [CF_PIN_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state).

### `PinFlags` [in]

The pin state flags. *PinFlags* can be set to the following values:

- If **CF_PIN_FLAG_RECURSE** is specified, the platform applies the pin state to *FileHandle* and every file recursively beneath it (relevant only if *FileHandle* is a handle to a directory).
- If **CF_PIN_FLAG_RECURSE_ONLY** is specified, the platform applies the pin state to every file recursively beneath *FileHandle*, but not to *FileHandle* itself.
- If **CF_PIN_FLAG_RECURSE_STOP_ERROR** is specified, the platform will stop the recursion when encountering first error. Otherwise, the platform skips the error and continues the recursion.

### `Overlapped` [in, out, optional]

Allows the call to be performed asynchronously. See the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate#-remarks) section for more details.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

When specified and combined with an asynchronous *FileHandle*, *Overlapped* allows the platform to perform the call asynchronously.

The caller must have initialized the overlapped structure with an event to wait on. If this returns **HRESULT_FROM_WIN32(ERROR_IO_PENDING)**, the caller can then wait using [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult). If not specified, the platform will perform the API call synchronously, regardless of how the handle was created.

## See also

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)

[CF_PIN_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state)

[CF_SET_PIN_FLAGS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_set_pin_flags)