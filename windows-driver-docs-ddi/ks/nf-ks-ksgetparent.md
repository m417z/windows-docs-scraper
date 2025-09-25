# KsGetParent function

## Description

The **KsGetParent** function acquires the parent of the given object.

## Parameters

### `Object` [in]

A pointer to the AVStream object for which to find the parent. Must be a pointer to one of the following types: [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice), [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory), [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter), or [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin). Callers must manually typecast the object to a PVOID.

## Return value

**KsGetParent** returns the parent of *Object* as a PVOID. Callers must manually cast this return value to whatever the type of the parent of *Object* is.

## Remarks

For a graphical representation of AVStream parent/child relationships, see the diagram in [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy).

The object hierarchy is only guaranteed stable while the appropriate mutex is held, in this case the device mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

Minidrivers rarely use this function directly. Callers of **KsGetParent** must manually perform typecasts to and from PVOID. There are a number of inline versions that do the casting for you: [KsFilterFactoryGetParentDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetparentdevice), [KsFilterGetParentFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetparentfilterfactory), and [KsPinGetParentFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetparentfilter).

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsFilterFactoryGetParentDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetparentdevice)

[KsFilterGetParentFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetparentfilterfactory)

[KsPinGetParentFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetparentfilter)