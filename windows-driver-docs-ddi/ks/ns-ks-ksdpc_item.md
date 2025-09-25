# KSDPC_ITEM structure

## Description

The KSDPC_ITEM structure is used to store information related to any internal DPCs that might be used to generate event notification from a raised IRQL.

## Members

### `Dpc`

Specifies a [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that is queued to perform notifications that cannot occur at raised IRQL.

### `ReferenceCount`

Specifies whether pending DPCs will reference this structure. This is initially set to 1 when the event structure is created, and decremented when the event structure is destroyed. If the reference count is nonzero at that time, then the last DPC to run frees the structure rather than the event disable call.

### `AccessLock`

This lock is used to synchronize deletion of an event item with any DPC that might be running.

## Remarks

KSDPC_ITEM uses a reference counting scheme to determine when to free the structure.

## See also

[KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)