# KsFilterFactoryGetNextSiblingFilterFactory function

## Description

The **KsFilterFactoryGetNextSiblingFilterFactory** function returns the next filter factory belonging to the parent device of *FilterFactory*.

## Parameters

### `FilterFactory` [in]

A pointer to the [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) for which to return the next filter factory of its parent device.

## Return value

**KsFilterFactoryGetNextSiblingFilterFactory** returns a pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure that represents the next sibling filter factory of *FilterFactory*. If no such filter factory exists, **NULL** is returned.

## Remarks

This call is an inline function call to [KsGetNextSibling](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetnextsibling). Note that the object hierarchy is guaranteed to be stable only while the appropriate mutex is held, in this case the device mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KsDeviceGetFirstChildFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicegetfirstchildfilterfactory)

[KsGetNextSibling](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetnextsibling)