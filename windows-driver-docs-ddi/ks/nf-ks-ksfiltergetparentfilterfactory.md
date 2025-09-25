# KsFilterGetParentFilterFactory function

## Description

The **KsFilterGetParentFilterFactory** function returns the parent filter factory of the given filter.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to return the parent filter factory.

## Return value

**KsFilterGetParentFilterFactory** returns a pointer to the parent [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure of *Filter.* This is the AVStream filter factory from which *Filter* was created.

## Remarks

This call is an inline function call to [KsGetParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetparent). Note that the object hierarchy is only guaranteed stable while the appropriate mutex is held, in this case the device mutex. For more information about mutexes, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KsGetParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetparent)