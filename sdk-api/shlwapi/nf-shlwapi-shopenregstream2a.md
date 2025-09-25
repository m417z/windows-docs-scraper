# SHOpenRegStream2A function

## Description

Opens a registry value and supplies a stream that can be used to read from or write to the value. This function supersedes [SHOpenRegStream](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shopenregstreama).

## Parameters

### `hkey` [in]

Type: **HKEY**

Required. The subtree, such as HKEY_LOCAL_MACHINE, that contains the value.

### `pszSubkey` [in, optional]

Type: **LPCTSTR**

Optional. Pointer to a null-terminated string that specifies the subkey that contains the value. This value can be **NULL**.

### `pszValue` [in, optional]

Type: **LPCTSTR**

Pointer to a null-terminated string that specifies the value to be accessed. This value can be **NULL**.

### `grfMode` [in]

Type: **DWORD**

The type of access for the stream. This can be one of the following values:

#### STGM_READ

Open the stream for reading.

#### STGM_WRITE

Open the stream for writing.

#### STGM_READWRITE

Open the stream for reading and writing.

## Return value

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Returns an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface pointer if successful; otherwise, **NULL**. A **NULL** value can be caused by several situations, including an invalid *hkey* or *pszSubkey*, a subkey named by *pszSubkey* that does not exist, a caller without sufficient permissions to access the subkey, or an inability to open the stream.

## Remarks

The calling application is responsible for calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method of the returned object when that [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object is no longer needed.

> [!NOTE]
> The shlwapi.h header defines SHOpenRegStream2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).