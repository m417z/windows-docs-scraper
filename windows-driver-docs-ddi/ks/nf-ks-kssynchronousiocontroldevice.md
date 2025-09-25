# KsSynchronousIoControlDevice function

## Description

The **KsSynchronousIoControlDevice** function performs a synchronous device I/O control on the target device object. It waits in a nonalertable state until the I/O completes. This function can only be called at PASSIVE_LEVEL.

## Parameters

### `FileObject` [in]

Indicates the file object to fill in the first stack location with.

### `RequestorMode`

Indicates the processor mode to place in the IRP if one needs to be generated.

### `IoControl` [in]

Specifies the I/O control to send.

### `InBuffer` [in]

Points to the device input buffer.

### `InSize` [in]

Specifies the size in bytes of the device input buffer.

### `OutBuffer` [out]

Points to the device output buffer.

### `OutSize` [in]

Specifies the size in bytes of the device output buffer.

### `BytesReturned` [out]

Points to the place in which to put the number of bytes returned.

## Return value

**KsSynchronousIoControlDevice** returns the result of the device I/O control.