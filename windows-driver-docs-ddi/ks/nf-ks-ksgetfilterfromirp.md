# KsGetFilterFromIrp function

## Description

The **KsGetFilterFromIrp** function returns the AVStream filter object associated with a given IRP.

## Parameters

### `Irp` [in]

A pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure for which to return the associated filter.

## Return value

**KsGetFilterFromIrp** returns either a pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure associated with *Irp* or **NULL**. **NULL** indicates that *Irp* is not associated with an AVStream object.

## Remarks

**KsGetFilterFromIrp** is valid for filters, pins, and nodes.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[KsGetPinFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetpinfromirp)