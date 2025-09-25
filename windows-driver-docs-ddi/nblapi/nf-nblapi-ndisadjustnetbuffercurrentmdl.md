# NdisAdjustNetBufferCurrentMdl function

## Description

The
**NdisAdjustNetBufferCurrentMdl** function updates a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure based on the current data
offset.

## Parameters

### `NetBuffer` [in]

A pointer to a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Remarks

The
**NdisAdjustNetBufferCurrentMdl** function recalculates and sets the
**CurrentMdl** and
**CurrentMdlOffset** members of a
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure based on the
**DataOffset** member of the NET_BUFFER structure.

Callers of
**NdisAdjustNetBufferCurrentMdl** can run at any IRQL, but typically run at IRQL <=
DISPATCH_LEVEL.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)