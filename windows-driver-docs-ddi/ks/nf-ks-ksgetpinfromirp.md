# KsGetPinFromIrp function

## Description

The **KsGetPinFromIrp** function returns the AVStream pin object associated with the given IRP.

## Parameters

### `Irp` [in]

A pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) for which to return the associated pin.

## Return value

**KsGetPinFromIrp** returns a pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure associated with the given IRP or **NULL**. **NULL** indicates that either the IRP is not associated with an AVStream object or that it is associated with a filter or a topology node.

## Remarks

Currently, IRPs associated with topology nodes cannot be queried for associated pins. This may change in a future revision of AVStream.

## See also

[KsAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquirecontrol)

[KsFilterAcquireControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilteracquirecontrol)

[KsFilterReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterreleasecontrol)

[KsGetFilterFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfilterfromirp)

[KsGetNodeIdFromIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetnodeidfromirp)

[KsReleaseControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreleasecontrol)