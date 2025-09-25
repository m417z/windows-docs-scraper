# IStream_Size function

## Description

Retrieves the size, in bytes, of a specified stream.

## Parameters

### `pstm` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

A pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the stream whose size is to be determined.

### `pui` [out]

Type: **[ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1)***

A pointer to a [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1) structure to receive the size of the stream.

## Return value

Type: **HRESULT**

Returns **S_OK** on success or a COM failure code otherwise. See [IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) for further discussion of possible error codes.

## Remarks

This function gets the size of the stream by calling the specified stream object's [IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) method. It then copies the value of the **cbSize** member of the [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure returned by **IStream::Stat** to the [ULARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-ularge_integer~r1) structure pointed to by *pui*. If the function fails, the contents of the **ULARGE_INTEGER** structure are undefined.