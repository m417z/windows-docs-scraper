# KsFilterFactoryGetFirstChildFilter function

## Description

The **KsFilterFactoryGetFirstChildFilter** function returns the first instantiated filter created by *FilterFactory*.

## Parameters

### `FilterFactory` [in]

A pointer to the [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure for which to find the first instantiated child filter.

## Return value

**KsFilterFactoryGetFirstChildFilter** returns a pointer to the first instantiated [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure created by *FilterFactory*. If there are no instantiated filters created by *FilterFactory*, **NULL** is returned.

## Remarks

This call is an inline function call to [KsGetFirstChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfirstchild). Note that the object hierarchy is guaranteed to be stable only while the appropriate mutex is held, in this case the device mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KsFilterGetNextSiblingFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetnextsiblingfilter)

[KsGetFirstChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetfirstchild)