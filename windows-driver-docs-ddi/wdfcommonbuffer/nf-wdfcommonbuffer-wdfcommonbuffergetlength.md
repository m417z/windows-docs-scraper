# WdfCommonBufferGetLength function

## Description

[Applies to KMDF only]

The **WdfCommonBufferGetLength** method returns the length of a specified common buffer.

## Parameters

### `CommonBuffer` [in]

A handle to a common buffer object that the driver obtained by a previous call to [WdfCommonBufferCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreate).

## Return value

**WdfCommonBufferGetLength** returns the length, in bytes, of the buffer that is associated with the common buffer that the *CommonBuffer* parameter specifies.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about common buffers, see [Using Common Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-common-buffers)

#### Examples

The following code example obtains the length of a specified common buffer.

```cpp
size_t bufferLength;

bufferLength = WdfCommonBufferGetLength(DevExt->CommonBuffer);
```

## See also

[WdfCommonBufferCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreate)