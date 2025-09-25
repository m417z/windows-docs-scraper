# IPersistStream::Load

## Description

Initializes an object from the stream where it was saved previously.

## Parameters

### `pStm` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to the stream from which the object should be loaded.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_OUTOFMEMORY** | The object was not loaded due to lack of memory. |
| **E_FAIL** | The object was not loaded due to some reason other than a lack of memory. |

## Remarks

This method loads an object from its associated stream. The seek pointer is set as it was in the most recent [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) method. This method can seek and read from the stream, but cannot write to it.

### Notes to Callers

Rather than calling **IPersistStream::Load** directly, you typically call the [OleLoadFromStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oleloadfromstream) function does the following:

1. Calls the [ReadClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstm) function to get the class identifier from the stream.
2. Calls the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function to create an instance of the object.
3. Queries the instance for [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream).
4. Calls **IPersistStream::Load**.

The [OleLoadFromStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oleloadfromstream) function assumes that objects are stored in the stream with a class identifier followed by the object data. This storage pattern is used by the generic, composite-moniker implementation provided by OLE.

If the objects are not stored using this pattern, you must call the methods separately yourself.

### URL Moniker Notes

Initializes an URL moniker from data within a stream, usually stored there previously using its [IPersistStream::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-save) (using [OleSaveToStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olesavetostream)). The binary format of the URL moniker is its URL string in Unicode (may be a full or partial URL string, see [CreateURLMonikerEx](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775103(v=vs.85)) for details). This is represented as a **ULONG** count of characters followed by that many Unicode characters.

## See also

[IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream)