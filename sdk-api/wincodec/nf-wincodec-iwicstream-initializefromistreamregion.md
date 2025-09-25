# IWICStream::InitializeFromIStreamRegion

## Description

Initializes the stream as a substream of another stream.

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to the input stream.

### `ulOffset` [in]

Type: **ULARGE_INTEGER**

The stream offset used to create the new stream.

### `ulMaxSize` [in]

Type: **ULARGE_INTEGER**

The maximum size of the stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The stream functions with its own stream position, independent of the underlying stream but restricted to a region. All seek positions are relative to the sub region. It is allowed, though not recommended, to have multiple writable sub streams overlapping the same range.