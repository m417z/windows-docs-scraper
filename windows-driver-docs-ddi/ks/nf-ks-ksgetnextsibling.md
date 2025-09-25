# KsGetNextSibling function

## Description

The **KsGetNextSibling** function returns the next sibling of a given object.

## Parameters

### `Object` [in]

The object for which to find the next sibling.

## Return value

**KsGetNextSibling** returns the next sibling object of *Object*. If no such sibling object exists, it returns **NULL**.

## Remarks

If *Object* is a filter factory, **KsGetNextSibling** returns the next filter factory belonging to the parent device, and so on. Callers must perform appropriate typecasting to and from PVOID.

The object hierarchy is guaranteed stable only while the appropriate mutex is held, in this case the device mutex. For more information, see [AVStream Overview](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-overview) and [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

Minidrivers rarely call **KsGetNextSibling** directly. There are a number of functions that are inline calls to **KsGetNextSibling** and that perform the typecasting for you: [KsFilterFactoryGetNextSiblingFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetnextsiblingfilterfactory), [KsFilterGetNextSiblingFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetnextsiblingfilter), and [KsPinGetNextSiblingPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetnextsiblingpin).

## See also

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsFilterFactoryGetNextSiblingFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorygetnextsiblingfilterfactory)

[KsFilterGetNextSiblingFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetnextsiblingfilter)

[KsPinGetNextSiblingPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingetnextsiblingpin)