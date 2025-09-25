# IDDCX_FRAME_STATISTICS_STEP_TYPE enumeration

## Description

A **IDDCX_FRAME_STATISTICS_STEP_TYPE** value defines the type of frame processing step.

## Constants

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_UNINITIALIZED:0`

Indicates that an **IDDCX_FRAME_STATISTICS_STEP_TYPE** variable has not yet been assigned a meaningful value.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_COLOR_CONVERT_START:0x1`

Marks the start of a color convert operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_COLOR_CONVERT_END:0x2`

Marks the end of a color convert operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_ENCODE_START:0x3`

Marks the start of a encode operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_ENCODE_END:0x4`

Marks the end of a encode operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_ENCRYPT_START:0x5`

Marks the start of an encrypt operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_ENCRYPT_END:0x6`

Marks the end of an encrypt operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_MUX_START:0x7`

Marks the start of a mux'ing operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_MUX_END:0x8`

Marks the end of a mux'ing operation.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_1:0x100`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_2:0x101`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_3:0x102`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_4:0x103`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_5:0x104`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_6:0x105`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_7:0x106`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_8:0x107`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_9:0x108`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_10:0x109`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_256:0x1FF`

Driver-defined processing step point. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_START_INTERVAL_1:0x200`

Driver-defined processing step start interval. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_END_INTERVAL_1:0x300`

Driver-defined processing step end interval. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_START_INTERVAL_2:0x201`

Driver-defined processing step start interval. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_END_INTERVAL_2:0x301`

Driver-defined processing step end interval. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_START_INTERVAL_3:0x202`

Driver-defined processing step start interval. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_END_INTERVAL_3:0x302`

Driver-defined processing step end interval. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_START_INTERVAL_256:0x2FF`

Driver-defined processing step start interval. See Remarks.

### `IDDCX_FRAME_STATISTICS_STEP_TYPE_DRIVER_DEFINED_END_INTERVAL_256:0x3FF`

Driver-defined processing step end interval. See Remarks.

## Remarks

For driver-defined processing step points, there are 256 single point events that a driver can use, where each event records a single QPC time. Valid driver values are 0x100-0x1FF.

For driver-defined processing step intervals, there are 256 different intervals, each with a defined start and end point. It is invalid to report either start or end without the other or for the start step to have a QPC time after the QPC time in the end step. Valid start step values are 0x200 - 0x2FFF. Valid end step values are 0x300 - 0x3FFF.

## See also

[**IDDCX_FRAME_STATISTICS_STEP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_frame_statistics_step)