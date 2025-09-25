# IKsPin::KsQueryInterfaces

## Description

The **KsQueryInterfaces** method retrieves interfaces that a pin supports.

## Parameters

### `InterfaceList` [out]

Pointer to a buffer that receives a pointer to a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) structure, followed by a sequence of [KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure) structures that describe interface types. The KSMULTIPLE_ITEM structure is a header that describes the size of the buffer and the number of entries in the list that follows the header.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The returned interfaces are ordered by preference.

## See also

[KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item)

[KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure)