# KsFilterFactoryGetParentDevice function

## Description

The **KsFilterFactoryGetParentDevice** function returns the parent device of the given filter factory.

## Parameters

### `FilterFactory` [in]

A pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure for which to return the parent device.

## Return value

**KsFilterFactoryGetParentDevice** returns a pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the parent device of the filter factory. This is the AVStream device to which the filter factory belongs.

## Remarks

This call is an inline function call to [KsGetParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetparent). Note that the object hierarchy is guaranteed to be stable only while the appropriate mutex is held, in this case the device mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KsGetParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetparent)