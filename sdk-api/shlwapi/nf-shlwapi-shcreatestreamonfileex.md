# SHCreateStreamOnFileEx function

## Description

Opens or creates a file and retrieves a stream to read or write to that file.

## Parameters

### `pszFile` [in]

Type: **LPCWSTR**

A pointer to a null-terminated string that specifies the file name.

### `grfMode` [in]

Type: **DWORD**

One or more [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) values that are used to specify the file access mode and how the object that exposes the stream is created and deleted.

### `dwAttributes` [in]

Type: **DWORD**

One or more flag values that specify file attributes in the case that a new file is created. For a complete list of possible values, see the *dwFlagsAndAttributes* parameter of the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `fCreate` [in]

Type: **BOOL**

A **BOOL** value that helps specify, in conjunction with *grfMode*, how existing files should be treated when creating the stream. See Remarks for details.

### `pstmTemplate` [in, optional]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Reserved.

### `ppstm` [out]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

Receives an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface pointer for the stream associated with the file.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **SHCreateStreamOnFileEx** function extends the semantics of the [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) flags and produces the same effect as calling the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

The *grfMode* and *fCreate* parameters work together to specify how the function should behave with respect to existing files.

| *grfMode* | *fCreate* | File exists? | Behavior |
| --- | --- | --- | --- |
| **STGM_CREATE** | Ignored | Yes | The file is recreated. |
| **STGM_CREATE** | Ignored | No | The file is created. |
| **STGM_FAILIFTHERE** | **FALSE** | Yes | The file is opened. |
| **STGM_FAILIFTHERE** | **FALSE** | No | The call fails. |
| **STGM_FAILIFTHERE** | **TRUE** | Yes | The call fails. |
| **STGM_FAILIFTHERE** | **TRUE** | No | The file is created. |