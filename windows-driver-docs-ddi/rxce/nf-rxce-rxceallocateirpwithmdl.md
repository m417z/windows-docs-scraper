# RxCeAllocateIrpWithMDL function

## Description

**RxCeAllocateIrpWithMDL** allocates an IRP and associates it with an existing memory descriptor list.

## Parameters

### `StackSize` [in]

The stack size to allocate for the IRP.

### `ChargeQuota` [in]

This parameter should be set to **FALSE** by intermediate drivers. This can be set to **TRUE** only by highest-level drivers that are called in the context of the thread that originates the I/O request for which the driver is allocating another IRP.

### `Buffer` [in]

A pointer to the buffer that contains the memory descriptor list to be associated with this IRP.

## Return value

**RxCeAllocateIrpWithMDL** returns a pointer to the IRP on success or a **NULL** pointer on error.

## Remarks

The goal of **RxCeAllocateIrpWithMDL** is to allow easier debugging of IRPs that are issued to other components and then stall. IRPs issued using **RxCeAllocateIrpWithMDL** are queued to a global list of IRPs maintained by RDBSS. Thus, when an RX_CONTEXT is waiting for a send completion, it is possible to walk the global list to find the IRP that is waiting in the transport.

An IRP allocated with an associated memory descriptor list allocated with **RxCeAllocateIrpWithMDL** should be freed when the IRP is completed using **RxCeFreeIrp**.

**IoAllocateIrp** automatically initializes the IRP's members and inserts the IRP into a global list of IRPs maintained by RDBSS. If memory for the MDL to be associated with the IRP cannot be allocated, then the IRP that was created is freed and **RxCeAllocateIrpWithMDL** returns a **NULL** pointer indicating failure.

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[RxCeFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcefreeirp)