# KsGetObjectTypeFromIrp function

## Description

The **KsGetObjectTypeFromIrp** function returns the AVStream object type that is associated with a given IRP.

## Parameters

### `Irp` [in]

A pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure for which to find the associated AVStream object type.

## Return value

**KsGetObjectTypeFromIrp** returns the type of AVStream object associated with the given IRP as a [KSOBJECTTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksobjecttype) enumeration. This is one of the following: **KsObjectTypeDevice**, **KsObjectTypeFilterFactory**, **KsObjectTypeFilter**, **KsObjectTypePin**.

## Remarks

The **KsGetObjectTypeFromIrp** function does not check that the I/O request packet (IRP) is associated with a KS object. If it is not, this may result in a memory access error. Driver developers should consider using structured exception handling to catch a possible exception.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[KsAddIrpToCancelableQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksaddirptocancelablequeue)

[KsDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdispatchirp)

[KsForwardIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksforwardirp)