# IAVIEditStream::SetInfo

## Description

The **SetInfo** method changes the characteristics of a stream. Called when an application uses the [EditStreamSetInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-editstreamsetinfoa) function.

## Parameters

### `lpInfo`

Pointer to an [AVISTREAMINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avistreaminfoa) structure containing the new stream characteristics.

### `cbInfo`

Size, in bytes, of the buffer.

#### - pavi

Pointer to the interface to a stream.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

For handlers written in C++, **SetInfo** has the following syntax:

```cpp

HRESULT SetInfo(AVISTREAMINFO *lpInfo, LONG cbInfo);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)

[EditStreamSetInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-editstreamsetinfoa)