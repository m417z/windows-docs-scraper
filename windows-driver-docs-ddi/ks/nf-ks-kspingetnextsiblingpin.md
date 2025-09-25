# KsPinGetNextSiblingPin function

## Description

The **KsPinGetNextSiblingPin** function returns the next instantiated pin of the same type and on the same filter as *Pin*.

## Parameters

### `Pin` [in]

A pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which to find the next instantiated sibling pin.

## Return value

**KsPinGetNextSiblingPin** returns a pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure representing the next instantiated sibling pin of *Pin*. If no such pin exists, returns **NULL**.

## Remarks

**KsPinGetNextSiblingPin** is an inline function call to [KsGetNextSibling](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetnextsibling). Note that the object hierarchy is only stable while the appropriate mutex is held, in this case the filter control mutex. For more information, see [Mutexes in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/mutexes-in-avstream).

## See also

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsFilterGetFirstChildPin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfiltergetfirstchildpin)

[KsGetNextSibling](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgetnextsibling)