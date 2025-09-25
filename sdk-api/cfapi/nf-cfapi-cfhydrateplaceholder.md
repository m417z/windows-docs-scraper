# CfHydratePlaceholder function

## Description

Hydrates a placeholder file by ensuring that the specified byte range is present on-disk in the placeholder. This is valid for files only.

## Parameters

### `FileHandle` [in]

Handle of the placeholder file to be hydrated. An attribute or no-access handle is sufficient.

### `StartingOffset` [in]

The starting point offset of the placeholder file data.

### `Length` [in]

The length, in bytes, of the placeholder file whose data must be available locally on the disk after the API completes successfully. A length of `CF_EOF` (defined as -1) signifies end of file. For any subrange that is not present in the placeholder, the platform will fetch the data from the sync provider and store it on disk in the placeholder.

### `HydrateFlags` [in]

The placeholder hydration flags. *HydrateFlags* must be set to **CF_HYDRATE_FLAG_NONE**.

### `Overlapped` [in, out, optional]

When specified and combined with an asynchronous *FileHandle*, *Overlapped* allows the platform to perform the **CfHydratePlaceholder** call asynchronously. See the [Remarks](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfhydrateplaceholder#-remarks) for more details.

If not specified, the platform will perform the API call synchronously, regardless of how the handle was created.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

The caller must have **READ_DATA** or **WRITE_DAC** access to the placeholder to be hydrated.

If the API returns **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** when using *Overlapped* asynchronously, the caller can then wait using [GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult).

## See also

[GetOverlappedResult](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getoverlappedresult)