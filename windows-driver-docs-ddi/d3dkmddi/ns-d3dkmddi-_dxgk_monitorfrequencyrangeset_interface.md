# _DXGK_MONITORFREQUENCYRANGESET_INTERFACE structure

## Description

The DXGK_MONITORFREQUENCYRANGESET_INTERFACE structure contains pointers to functions that belong to the [Monitor Frequency Range Set interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/), which is implemented by the video present network (VidPN) manager.

## Members

### `pfnGetNumFrequencyRanges`

A pointer to the [pfnGetNumFrequencyRanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_getnumfrequencyranges) function.

### `pfnAcquireFirstFrequencyRangeInfo`

A pointer to the [pfnAcquireFirstFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_acquirefirstfrequencyrangeinfo) function.

### `pfnAcquireNextFrequencyRangeInfo`

A pointer to the [pfnAcquireNextFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_acquirenextfrequencyrangeinfo) function.

### `pfnReleaseFrequencyRangeInfo`

A pointer to the [pfnReleaseFrequencyRangeInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitorfrequencyrangeset_releasefrequencyrangeinfo) function.