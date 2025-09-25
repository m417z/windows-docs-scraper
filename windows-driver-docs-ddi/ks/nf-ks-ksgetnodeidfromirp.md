# KsGetNodeIdFromIrp function

## Description

The **KsGetNodeIdFromIrp** function returns the node ID of the node to which *Irp* was submitted.

## Parameters

### `Irp` [in]

A pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure for which to determine the associated node ID. This IRP must have been sent to a file object corresponding to a filter, pin, or node.

## Return value

**KsGetNodeIdFromIrp** returns the ID of the node to which *Irp* was submitted. If *Irp* was instead submitted directly to the filter, it returns KSFILTER_NODE.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[KsAddIrpToCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddirptocancelablequeue)

[KsDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdispatchirp)

[KsForwardIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksforwardirp)