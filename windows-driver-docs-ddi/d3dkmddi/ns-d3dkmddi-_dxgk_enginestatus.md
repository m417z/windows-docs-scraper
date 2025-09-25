# _DXGK_ENGINESTATUS structure

## Description

Indicates the progress of a node within an active physical display adapter (engine) specified by a [DXGKARG_QUERYENGINESTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryenginestatus) structure.

## Members

### `Responsive`

The display miniport driver must set this member to a value of 1 if the node and physical adapter are making progress in operations, or to 0 if the node and physical adapter are not responding to queries to report progress.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A 32-bit value that specifies the progress of the physical adapter.

## See also

[DXGKARG_QUERYENGINESTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryenginestatus)