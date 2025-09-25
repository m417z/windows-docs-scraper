# _DXGKARG_SETCONTEXTSCHEDULINGPROPERTIES structure

## Description

Contains arguments used in the [DxgkddiSetContextSchedulingProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setcontextschedulingproperties) callback function.

## Members

### `hContext`

The hardware context to change the priority band of.

### `priorityBand`

The priority band value assigned to this context. Assigning a context to focus and realtime priority bands requires the calling process to have SE_INC_BASE_PRIORITY_NAME privilege.

### `realtimeBandPriorityLevel`

When the context belongs to the realtime scheduling priority band, this value indicates the priority level (0...31) within the realtime band. For all other bands, this value is ignored.

### `inProcessPriority`

The process wide priority value, relative to other contexts of the same priority within the same process. Values range from -7 to +7. The default in process priority value is zero.

### `quantum`

The context quantum value in 100ns units, relative to other contexts of the same priority within the same process.

### `gracePeriodSamePriority`

The grace period value in 100ns units when this context preempts another context of the same priority within the same process.

### `gracePeriodLowerPriority`

The grace period value in 100ns units when this context preempts another context of a lower priority within the same process. **gracePeriodLowerPriority** is typically smaller than **gracePeriodSamePriority**.

## See also

[DxgkddiSetContextSchedulingProperties](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setcontextschedulingproperties)