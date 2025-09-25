## Description

Represents a buffer as an array of bytes.

## Members

### `IUnknown`

## Remarks

The client creates an [IBuffer](https://learn.microsoft.com/uwp/api/Windows.Storage.Streams.IBuffer) object, and the buffer is provided by the [Buffer](https://learn.microsoft.com/windows/win32/api/robuffer/nf-robuffer-ibufferbyteaccess-buffer) method.

When you implement the **IBuffer** interface, you must implement the **IBufferByteAccess** interface.

## See also