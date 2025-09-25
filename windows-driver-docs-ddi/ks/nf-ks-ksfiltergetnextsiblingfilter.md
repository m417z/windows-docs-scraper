# KsFilterGetNextSiblingFilter function

## Description

The **KsFilterGetNextSiblingFilter** function returns the next instantiated filter belonging to the parent filter factory of *Filter*.

## Parameters

### `Filter` [in]

A pointer to the [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure for which to find the next sibling filter.

## Return value

**KsFilterGetNextSiblingFilter** returns a pointer to the next sibling [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure of *Filter*. If no such instantiated filter exists, it returns **NULL**.

## Remarks

This call is an inline function call to [KsGetNextSibling](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetnextsibling). Note that the object hierarchy is only guaranteed stable while the appropriate mutex is held, in this case the device mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KsFilterFactoryGetFirstChildFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetfirstchildfilter)

[KsGetNextSibling](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetnextsibling)