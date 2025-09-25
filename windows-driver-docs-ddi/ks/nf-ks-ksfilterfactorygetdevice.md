# KsFilterFactoryGetDevice function

## Description

The **KsFilterFactoryGetDevice** function returns the AVStream device to which *FilterFactory* belongs.

## Parameters

### `FilterFactory` [in]

A pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure for which to find the corresponding AVStream device.

## Return value

Returns a pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the AVStream device to which *FilterFactory* belongs.

## Remarks

This call is an inline function call to [KsGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevice).

For more information about the AVStream object hierarchy, see [AVStream Overview](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-overview).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KsGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetdevice)