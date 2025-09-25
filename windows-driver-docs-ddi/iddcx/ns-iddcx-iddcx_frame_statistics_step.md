# IDDCX_FRAME_STATISTICS_STEP structure

## Description

The **IDDCX_FRAME_STATISTICS_STEP** structure provides information about the frame processing step being used by the driver.

## Members

### `Size`

Total size of this structure, in bytes.

### `Type`

A [**IDDCX_FRAME_STATISTICS_STEP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_frame_statistics_step_type) value that specifies the type of frame processing step.

### `QpcTime`

Specifies the system QPC time of the step.

### `Data`

When driver-defined processing part is used, then the driver can store additional data here.

## See also

[**IDDCX_FRAME_STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_frame_statistics)