# KsFilterGetDevice function

## Description

The **KsFilterGetDevice** function returns the AVStream device to which *Filter* belongs.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to find the owning AVStream device.

## Return value

**KsFilterGetDevice** returns a pointer to the AVStream [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure to which *Filter* belongs.

## Remarks

This call is an inline function call to [KsGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevice).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KsGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevice)