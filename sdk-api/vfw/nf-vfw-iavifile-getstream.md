# IAVIFile::GetStream

## Description

The **GetStream** method opens a stream by accessing it in a file. Called when an application uses the [AVIFileGetStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilegetstream) function.

## Parameters

### `ppStream`

Pointer to a buffer that receives a pointer to the interface to a stream.

### `fccType`

Four-character code indicating the type of stream to locate.

### `lParam`

Stream number.

#### - pf

Pointer to the interface to a file.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

It is typically easier to implement this method by creating all of the stream objects in advance by using the [IAVIFile::Open](https://learn.microsoft.com/previous-versions/dd798007(v=vs.85)) method. Then, this method accesses the interface to the specified stream.

Remember to increment the reference count maintained by the **AddRef** method for the stream when this method is used.

For handlers written in C++, GetStream has the following syntax:

```cpp

HRESULT GetStream(PAVISTREAM *ppStream,
    DWORD fccType, LONG lParam);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)