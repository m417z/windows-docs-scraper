# CfSetPinState function

## Description

This function sets the pin state of a placeholder, which represents a user’s intent. Any application, not just the sync provider, can call this function.

## Parameters

### `FileHandle` [in]

The handle of the placeholder file. The platform properly synchronizes the operation with other active requests. An attribute or no-access handle is sufficient. The caller must have **READ_DATA** or **WRITE_DAC** access to the placeholder. Otherwise, the operation fails with **STATUS_CLOUD_FILE_ACCESS_DENIED**.

### `PinState` [in]

The pin state of the placeholder file. For a list of valid *PinState* values, see [CF_PIN_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state).

### `PinFlags` [in]

The pin state flags. Set *PinFlags* to one of the following values:

- If you specify **CF_SET_PIN_FLAG_RECURSE**, the platform applies the pin state to *FileHandle* and every file recursively beneath it. This flag is relevant only if *FileHandle* is a handle to a directory.
- If you specify **CF_SET_PIN_FLAG_RECURSE_ONLY**, the platform applies the pin state to every file recursively beneath *FileHandle*, but not to *FileHandle* itself.
- If you specify **CF_SET_PIN_FLAG_RECURSE_STOP_ON_ERROR**, the platform stops the recursion when it encounters the first error. Otherwise, the platform skips the error and continues the recursion.

Use **CF_SET_PIN_FLAG_NONE** to specify no flags.

### `Overlapped` [in, out, optional]

Allows the call to be performed asynchronously. See the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetpinstate#-remarks) section for more details.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

When you specify and combine an asynchronous *FileHandle* with *Overlapped*, the platform can perform the call asynchronously.

You must initialize the overlapped structure with an event to wait on. If this function returns **HRESULT_FROM_WIN32(ERROR_IO_PENDING)**, you can wait by using [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult). If you don't specify this parameter, the platform performs the API call synchronously, regardless of how you created the handle.

## See also

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)

[CF_PIN_STATE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_pin_state)

[CF_SET_PIN_FLAGS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_set_pin_flags)