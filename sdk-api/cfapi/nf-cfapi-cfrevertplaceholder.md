# CfRevertPlaceholder function

## Description

Reverts a placeholder back to a regular file, stripping away all special characteristics such as the reparse tag, the file identity, etc.

## Parameters

### `FileHandle` [in]

A handle to the file or directory placeholder that is about to be reverted to a normal file or directory. The platform properly synchronizes the revert operation with other active requests. An attribute or no-access handle is sufficient.

### `RevertFlags` [in]

Placeholder revert flags. *RevertFlags* should be set to **CF_REVERT_FLAG_NONE**.

### `Overlapped` [in, out, optional]

When specified and combined with an asynchronous *FileHandle*, *Overlapped* allows the platform to perform the **CfRevertPlaceholder** call asynchronously. See the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfrevertplaceholder#-remarks) for more details.

If not specified, the platform will perform the API call synchronously, regardless of how the handle was created.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller must have **WRITE_DATA** or **WRITE_DAC** access to the placeholder to be reverted.

If the placeholder is not already fully hydrated at the time of the call, then the filter will send a **FETCH_DATA** callback to the sync provider to hydrate the file. If the file can’t be hydrated, the revert will fail with status **STATUS_CLOUD_FILE_ACCESS_DENIED**.

If the API returns HRESULT_FROM_WIN32(ERROR_IO_PENDING) when using *Overlapped* asynchronously, the caller can then wait using [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult).

## See also

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)

[CF_REVERT_FLAGS](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_revert_flags)