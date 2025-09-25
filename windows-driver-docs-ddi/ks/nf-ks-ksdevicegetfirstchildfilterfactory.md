# KsDeviceGetFirstChildFilterFactory function

## Description

The **KsDeviceGetFirstChildFilterFactory** function returns the first child filter factory belonging to a given AVStream device.

## Parameters

### `Device` [in]

A pointer to a [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) structure representing the AVStream device for which to find the first child filter factory.

## Return value

Returns a pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure representing the first child filter factory of *Device*. If there are no filter factories registered on *Device*, **NULL** is returned.

## Remarks

This call is an inline function call to [KsGetFirstChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfirstchild). Note that the object hierarchy is only guaranteed stable while the appropriate mutex is held, in this case the device mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

For a graphical representation of AVStream parent/child relationships, see the diagram in [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KsFilterFactoryGetNextSiblingFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetnextsiblingfilterfactory)

[KsGetFirstChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfirstchild)