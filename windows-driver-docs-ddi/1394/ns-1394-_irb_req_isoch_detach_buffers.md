# _IRB_REQ_ISOCH_DETACH_BUFFERS structure

## Description

This structure contains the fields required to carry out a IsochDetachBuffers request.

## Members

### `hResource`

Specifies the resource handle to detach buffers from.

### `nNumberOfDescriptors`

Specifies the number of elements in the **pIsochDescriptor** array.

### `pIsochDescriptor`

Points to an array of ISOCH_DESCRIPTOR structures that describe the buffers to be detached. The device driver should use the same ISOCH_DESCRIPTOR structure for a buffer that it used to attach the buffer.