# _D3DKMT_POLLDISPLAYCHILDREN structure

## Description

The D3DKMT_POLLDISPLAYCHILDREN structure describes parameters for querying for connectivity status of all child devices of the given display adapter.

## Members

### `hAdapter` [in]

A D3DKMT_HANDLE data type that represents the kernel-mode handle to the graphics adapter to query for connectivity status of child devices.

### `NonDestructiveOnly` [in]

A UINT value that specifies whether the call to the [D3DKMTPollDisplayChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtpolldisplaychildren) function should be only nondestructive. A nonzero value indicates only a nondestructive call; a zero value indicates the call can be destructive (that is, the call can cause visual artifacts on the screen).

### `SynchronousPolling` [in]

Supported beginning with Windows 7 operating system.

A UINT value that specifies whether the connectivity status of all child devices is reported within 1 second of the call to [D3DKMTPollDisplayChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtpolldisplaychildren). If set to a nonzero value, connectivity status is reported within 1 second. Otherwise, there is no time limit on when the display miniport can complete and report the polling.

If the display miniport driver needs to poll child devices after receiving notice of an ACPI event, the runtime should set **SynchronousPolling** to a nonzero value.

### `DisableModeReset` [in]

Supported beginning with Windows 7 operating system.

A UINT value that specifies whether any reactions of the display miniport driver to discoveries of new child devices are disabled during the polling interval. If set to a nonzero value, such reactions of the driver are disabled during the polling interval. In this case, set the **SynchronousPolling**parameter when setting **DisableModeReset**. Otherwise, normal reactions of the driver to discoveries of new child devices are allowed.

### `PollAllAdapters` [in]

Supported beginning with Windows 7 operating system.

A UINT value that specifies whether all child devices are polled. If set to a nonzero value, all child devices are polled. Otherwise, only the child devices that are on the specified adapter are discovered in the polling.

### `PollInterruptible` [in]

Supported beginning with Windows 7 operating system.

A UINT value that specifies whether child devices that are aware of hot-plug detection (HPD) are polled. If set to a nonzero value, HPD-aware child devices are polled. Otherwise, HPD-aware child devices might not be discovered in the polling.

HPD-aware devices are those for which, in a call to [DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations), the **ChildRelations**.**ChildCapabilities**.**HpdAwareness** member has a value not equal to HpdAwarenessUninitialized or HpdAwarenessNone.

For more information on HPD-aware devices, see [Monitor Hot Plug Detection](https://learn.microsoft.com/windows-hardware/drivers/display/monitor-hot-plug-detection).

### `Reserved` [in]

Supported beginning with Windows 7 operating system.

This member is reserved and should be set to zero. Setting this member is equivalent to setting the remaining 26 bits (0xFFFFFFC0) of a 32-bit value to zeros.

## See also

[D3DKMTPollDisplayChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtpolldisplaychildren)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)