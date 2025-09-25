# IAVIFile::ReadData

## Description

The **ReadData** method reads file headers. Called when an application uses the [AVIFileReadData](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilereaddata) function.

## Parameters

### `ckid`

A chunk identifier.

### `lpData`

A pointer specifying the memory into which the data is read.

### `lpcbData`

A pointer to a LONG specifying the number of bytes read.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **ReadData** has the following syntax:

```cpp

HRESULT ReadData(DWORD fcc, LPVOID lp, LONG *lpcb);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)