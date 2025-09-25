# SHCreateStreamOnFileW function

## Description

[**SHCreateStreamOnFile** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [SHCreateStreamOnFileEx](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatestreamonfileex).]

Opens or creates a file and retrieves a stream to read or write to that file.

## Parameters

### `pszFile` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that specifies the file name.

### `grfMode` [in]

Type: **DWORD**

One or more [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) values that are used to specify the file access mode and how the object that exposes the stream is created and deleted.

### `ppstm` [out]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

Receives an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface pointer for the stream associated with the file.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[SHCreateStreamOnFileEx](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatestreamonfileex) fully supports all [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) modes and allows the caller to specify file attributes if creating a new file.

> [!NOTE]
> The shlwapi.h header defines SHCreateStreamOnFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).