# OpenRegStream function

## Description

[**OpenRegStream** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [SHOpenRegStream2](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shopenregstream2a) or [SHOpenRegStream](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shopenregstreama).]

Opens a registry value and supplies an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface that can be used to read from or write to the value.

## Parameters

### `hkey` [in]

Type: **HKEY**

A handle to the key that is currently open.

### `pszSubkey` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that specifies the name of the subkey.

### `pszValue` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that specifies the value to be accessed.

### `grfMode`

Type: **DWORD**

The type of access for the stream. This can be one of the following values.

#### STGM_READ

Open the stream for reading.

#### STGM_WRITE

Open the stream for writing.

#### STGM_READWRITE

Open the stream for reading and writing.

## Return value

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Returns the address of an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface if successful, or **NULL** otherwise.