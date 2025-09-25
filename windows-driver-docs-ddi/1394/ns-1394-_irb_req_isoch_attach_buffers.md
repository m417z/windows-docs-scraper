# _IRB_REQ_ISOCH_ATTACH_BUFFERS structure

## Description

This structure contains the fields required for the 1394 bus driver to carry out an IsochAttachBuffers request.

## Members

### `hResource`

Specifies the resource handle to attach buffers to.

### `nNumberOfDescriptors`

Specifies the number of elements in the **pIsochDescriptor** array.

### `pIsochDescriptor`

Points to an array of ISOCH_DESCRIPTOR structures that describe the buffers to be attached, and the parameters that specify how each buffer is to be used.