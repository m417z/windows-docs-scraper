# IShellImageStore::GetEntry

## Description

[[IShellImageStore](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ishellimagestore) is supported through Windows XP. It is not supported in later operating systems.]

Gets a handle to an image in the cache.

## Parameters

### `pszName` [in]

Type: **PCWSTR**

A pointer to a null-terminated string that specifies the path to the file that contains the image.

### `dwMode`

Type: **DWORD**

The storage instantiation mode specified by one of the [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants)  values.

### `phImage` [out]

Type: **HBITMAP***

A pointer to the handle of the bitmap.

## Return value

Type: **HRESULT**

Returns the result of [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) if the process was successful. Otherwise, returns one of the following values:

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | Storage is not open. |
| **E_FAIL** | The stream cannot be found. |

## Remarks

It is the caller's responsibility to free the handle after a call to this method.