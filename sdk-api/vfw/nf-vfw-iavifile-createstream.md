# IAVIFile::CreateStream

## Description

The **CreateStream** method creates a stream for writing. Called when an application uses the [AVIFileCreateStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilecreatestream) function.

## Parameters

### `ppStream`

Pointer to a buffer that receives a pointer to the interface to the new stream.

### `psi`

Pointer to an [AVISTREAMINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avistreaminfoa) structure defining the stream to create.

## Return value

Returns HRESULT defined by OLE.

## Remarks

For handlers written in C++, **CreateStream** has the following syntax:

```cpp

HRESULT CreateStream(PAVISTREAM *ppstream,
    AVISTREAMINFO *psi);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)