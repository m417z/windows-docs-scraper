# IAVIFile::Info

## Description

The **Info** method returns with information about an AVI file. Called when an application uses the [AVIFileInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifileinfo) function.

## Parameters

### `pfi`

A pointer to an [AVIFILEINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avifileinfoa) structure. The method fills the structure with information about the file.

### `lSize`

The size, in bytes, of the buffer specified by *pfi*.

#### - pf

Pointer to the interface to a file.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

If the buffer allocated is too small for the structure, this method should fail the call by returning AVIERR_BUFFERTOOSMALL. Otherwise, it should fill the structure and return its size.

For handlers written in C++, **Info** has the following syntax:

```cpp

HRESULT Info(AVIFILEINFO *pfi, LONG lSize)

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)