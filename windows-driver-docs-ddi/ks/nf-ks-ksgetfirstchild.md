# KsGetFirstChild function

## Description

The **KsGetFirstChild** function returns the first AVStream child object of *Object*.

## Parameters

### `Object` [in]

The object for which to find the first AVStream child object.

## Return value

**KsGetFirstChild** returns the first AVStream child object of *Object*. If no such child object exists, it returns **NULL**.

## Remarks

To see the hierarchical organization of AVStream objects, see [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy).

Minidrivers rarely call this function directly. Those that do must manually perform typecasts to and from PVOID. There are a number of functions that are inline calls to **KsGetFirstChild** and perform typecasts for you: [KsDeviceGetFirstChildFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicegetfirstchildfilterfactory) and [KsFilterFactoryGetFirstChildFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetfirstchildfilter). Note that the object hierarchy is only guaranteed stable while the appropriate mutex is held, in this case the device mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KsDeviceGetFirstChildFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdevicegetfirstchildfilterfactory)

[KsFilterFactoryGetFirstChildFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetfirstchildfilter)

[KsFilterGetFirstChildPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetfirstchildpin)

[KsGetParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetparent)