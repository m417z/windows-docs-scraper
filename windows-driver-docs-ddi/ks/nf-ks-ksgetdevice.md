# KsGetDevice function

## Description

The **KsGetDevice** function returns the AVStream device structure to which *Object* belongs.

## Parameters

### `Object` [in]

The object to query for the device to which it belongs.

## Return value

**KsGetDevice** returns a pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure that is the AVStream device to which *Object* belongs.

## Remarks

*Object* should be one of: PKSPIN, PKSFILTER, or PKSFILTERFACTORY. Callers must perform appropriate typecasting to PVOID.

Minidrivers typically do not call this function directly. There are a number of functions that perform inline calls to **KsGetDevice** and that perform typecasting automatically: [KsFilterFactoryGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetdevice), [KsFilterGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetdevice), and [KsPinGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetdevice).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsFilterFactoryGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetdevice)

[KsFilterGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetdevice)

[KsPinGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetdevice)