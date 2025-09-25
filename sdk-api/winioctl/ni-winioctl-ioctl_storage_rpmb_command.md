## Description

This IOCTL sends an RPMB command to the underlying storage device.

## Parameters

### Input buffer

An array of STORAGE_RPMB_DATA_FRAME structures.

### Input buffer length

A multiple of sizeof(STORAGE_RPMB_DATA_FRAME). InputBufferLength / sizeof(STORAGE_RPMB_DATA_FRAME) indicates the number of input frames.

### Output buffer

An array of STORAGE_RPMB_DATA_FRAME structures.

### Output buffer length

A multiple of sizeof(STORAGE_RPMB_DATA_FRAME). The number of frames included can be calculated by OutputBufferLength / sizeof(STORAGE_RPMB_DATA_FRAME)

### Input/output buffer

### Input/output buffer length

### Status block

## Remarks

## See also