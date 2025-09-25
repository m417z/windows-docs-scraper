# IStream_ReadPidl function

## Description

Reads a pointer to an item identifier list (PIDL) from an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object into a PIDLIST_RELATIVE object.

## Parameters

### `pstm` [in]

Type: **IStream***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) from which the PIDL is read.

### `ppidlOut` [out]

Type: **PIDLIST_RELATIVE***

A pointer to the resulting PIDL.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.