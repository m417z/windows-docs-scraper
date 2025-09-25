# WdmlibIoGetAffinityInterrupt function

## Description

The **WdmlibIoGetAffinityInterrupt** function gets the group affinity of an interrupt object.

## Parameters

### `InterruptObject` [in]

A pointer to an interrupt object. This parameter points to a [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that represents a registration by a driver to receive device interrupts. The structure is opaque. The caller obtained this pointer value in a previous call to the [WdmlibIoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibioconnectinterruptex) or [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) routine.

### `GroupAffinity` [out]

A pointer to a caller-allocated buffer into which the routine writes a [GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) structure that specifies the group affinity of the interrupt object that *InterruptObject* points to. This buffer must be large enough to contain the structure.

## Return value

**WdmlibIoGetAffinityInterrupt** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *InterruptObject* parameter does not point to a valid interrupt object. |

## Remarks

A kernel-mode driver calls this routine to get the set of logical processors on which the driver's registered interrupt service routine (ISR) can receive device interrupts. This set of processors is described by a **GROUP_AFFINITY** structure, which specifies a group number and an affinity mask. All the processors that are assigned to a particular ISR registration must belong to the same group.

The driver registered the ISR in a previous call to the [WdmlibIoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibioconnectinterruptex) or **IoConnectInterrupt** routine.

In Windows 7, [WdmlibIoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibioconnectinterruptex) and **IoConnectInterrupt** assign device interrupts only to logical processors in group 0. This is by default. A driver can specify a different interrupt affinity for its device in an INF file or in its response to an [IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) request. For more information about how to change the interrupt affinity, see the [Supporting Systems That Have More Than 64 Processors](https://go.microsoft.com/fwlink/p/?linkid=147914) white paper on the WHDC website.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)

[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements)

[IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[WdmlibIoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/iointex/nf-iointex-wdmlibioconnectinterruptex)