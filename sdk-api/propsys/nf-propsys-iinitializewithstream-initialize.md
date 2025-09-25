# IInitializeWithStream::Initialize

## Description

Initializes a handler with a stream.

## Parameters

### `pstream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface that represents the stream source.

### `grfMode` [in]

Type: **DWORD**

One of the following [STGM](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants) values that indicates the access mode for *pstream*.

#### STGM_READ

The stream indicated by *pstream* is read-only.

#### STGM_READWRITE

The stream indicated by *pstream* is read/write accessible.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is preferred to [Initialize](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-iinitializewithfile-initialize) due to its ability to use streams that are not accessible through a Win32 path, such as the contents of a compressed file with a .zip file name extension.

The stream pointed to by *pstream* must remain open for the lifetime of the handler or until [IPropertyStore::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb761470(v=vs.85)) is called.

When first opened, the source stream reference points to the beginning of the stream. The handler can seek and read from the stream at any time. A handler can be implemented to read all properties from the stream during **Initialize** or it can wait until the calling process attempts to enumerate or read properties before fetching them from the stream.

A handler instance should be initialized only once in its lifetime. Attempts by the caller to reinitialize the handler should result in the error `HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)`.