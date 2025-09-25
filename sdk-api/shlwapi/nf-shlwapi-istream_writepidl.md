# IStream_WritePidl function

## Description

Writes a pointer to an item identifier list (PIDL) from a PCUIDLIST_RELATIVE object into an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object.

## Parameters

### `pstm` [in]

Type: **IStream***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object in which to write.

### `pidlWrite` [in]

Type: **PCUIDLIST_RELATIVE**

The source PIDL.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.