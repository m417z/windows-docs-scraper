# _DXGKARG_SETVIDPNSOURCEADDRESS structure

## Description

The DXGKARG_SETVIDPNSOURCEADDRESS structure contains arguments for the [DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85)) function.

## Members

### `VidPnSourceId`

An integer that identifies a video present source on the display adapter.

### `PrimarySegment`

The identifier of the segment that contains the source's primary surface.

### `PrimaryAddress`

The address, within the segment identified by *PrimarySegment*, of the source's primary surface.

### `hAllocation` [in]

If non-NULL, a handle that the display miniport driver assigned to the allocation and returned from its call to the [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function. The driver must reprogram graphics hardware according to the specific private properties of the allocation, which include but are not limited to pitch size, swizzle format, and so on.

### `ContextCount` [in]

The number of contexts in the array that the **Context** member specifies.

### `Context` [in]

An array of handles to the contexts that contributed to a display operation.

### `Flags` [in]

A [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure that identifies the type of display operation to perform.

### `Duration`

The length of time, in units of 100 nanoseconds, between when the current present operation flips to the screen and the next vertical blanking interrupt occurs.

If zero, the refresh rate should be the default rate based on the current mode.

Must be supported by WDDM 1.3 and later drivers. Available starting with Windows 8.1.

### `PrimaryData`

### `DriverPrivateDataSize`

### `pDriverPrivateData`

## Remarks

For display mode-switch operations, the **ContextCount** member is always set to 0 and the content of the **Context** array is undefined. When a flip operation is performed, **ContextCount** is set to the number of contexts that contributed to the flip. If a flip operation is broadcast to three contexts, **ContextCount** is set to 4 (that is, the original context plus three broadcast contexts). The **Context** array contains the driver context handles for the contexts that contributed to the flip operation.

## See also

[DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85))