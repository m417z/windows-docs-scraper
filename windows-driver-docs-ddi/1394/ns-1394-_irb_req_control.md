# _IRB_REQ_CONTROL structure

## Description

This structure contains the fields necessary for the 1394 bus driver to carry out a control request.

## Members

### `ulIoControlCode`

Specifies the control code used in this request. Vendors should make these control codes unique, so that they do not overlap.

### `pInBuffer`

Points to an MDL that describes the input buffer. The input buffer contains user-defined information.

### `ulInBufferLength`

Specifies the length of the input buffer.

### `pOutBuffer`

Points to an MDL that describes the output buffer. The output buffer contains user-defined information.

### `ulOutBufferLength`

Specifies the length of the output buffer.

### `BytesReturned`

Specifies the number of bytes returned.