# IStream_Reset function

## Description

Moves the seek position in a specified stream to the beginning of the stream.

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the stream whose position is to be reset.

## Return value

Type: **HRESULT**

Returns **S_OK** on success or a COM failure code otherwise. See [IStream::Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek) for further discussion of possible error codes.

## Remarks

This function calls [IStream::Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek) to move the stream's seek position to the beginning of the stream.