# IInitializeWithFile::Initialize

## Description

Initializes a handler with a file path.

## Parameters

### `pszFilePath` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the file path as a null-terminated Unicode string.

### `grfMode` [in]

Type: **DWORD**

One of the following [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) values that indicates the access mode for *pszFilePath*.

#### STGM_READ

The file indicated by **IInitializeWithFile::Initialize** is read-only.

#### STGM_READWRITE

The file indicated by **IInitializeWithFile::Initialize** can be read from and written to.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[Initialize](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-iinitializewithstream-initialize) is preferred to this method because of its ability to use files that are not accessible through a Win32 path, such as the contents of a compressed file with a .zip file name extension. Use **IInitializeWithFile::Initialize** only when the API used by the handler to access the file accepts file paths only.

The file pointed to by *pszFilePath* must remain open for the lifetime of the handler or until [IPropertyStore::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761470(v=vs.85)) is called.

If the file cannot be opened according to the method's parameter values, this method returns a suitable error code.

A handler instance should be initialized only once in its lifetime. Attempts by the calling application to reinitialize the handler should result in the error `HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)`.