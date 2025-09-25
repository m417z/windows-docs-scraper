# IAVIFile::EndRecord

## Description

The **EndRecord** method writes the "REC" chunk in a tightly interleaved AVI file (having a one-to-one interleave factor of audio to video). Called when an application uses the [AVIFileEndRecord](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifileendrecord) function.

#### - pf

Pointer to the interface to a file.

## Return value

Returns the HRESULT defined by OLE.

## Remarks

This file handler method is typically not used.

For handlers written in C++, **EndRecord** has the following syntax:

```cpp

HRESULT EndRecord(VOID);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)