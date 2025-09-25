# IAVIStream::Info

## Description

The **Info** method fills and returns an [AVISTREAMINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avistreaminfoa) structure with information about a stream. Called when an application uses the [AVIStreamInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreaminfoa) function.

## Parameters

### `psi`

Pointer to an [AVISTREAMINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avistreaminfoa) structure to contain stream information.

### `lSize`

Size, in bytes, of the structure specified by *psi*.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

If the buffer allocated is too small for the structure, the **Info** method should fail the call by returning AVIERR_BUFFERTOOSMALL. Otherwise, it should fill the structure and return its size.

For handlers written in C++, **Info** has the following syntax:

```cpp

HRESULT Info(AVIFILEINFO *psi, LONG lSize)

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)