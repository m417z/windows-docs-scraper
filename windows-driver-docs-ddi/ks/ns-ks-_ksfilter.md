# _KSFILTER structure

## Description

The KSFILTER structure describes an instantiated filter.

## Members

### `Descriptor`

A pointer to a [KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) structure that describes the characteristics of this particular filter.

### `Bag`

This member specifies the KSOBJECT_BAG (equivalent to type PVOID) associated with this filter instance. [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags) are structures used to associate dynamic memory with a specific AVStream object. Anything in the filter object bag is automatically cleaned up when the filter is deleted.

### `Context`

A pointer that is used by the client to associate context information with the specific filter instance. Typically, such context information is associated in the filter's **Create** member as defined in the KSFILTER_DISPATCH table for this filter instance. Any dynamically allocated context information should be placed in the object bag with [KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag). **Context** is initialized to the value of the **Context** member of the parent [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) at the time the filter is created. See [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy).

## Remarks

Drivers implementing software filters typically associate filter state with the KSFILTER structure. Software filters usually process data within the callback specified by the **Process** member of the corresponding [KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch) structure.

Hardware filters typically do not use KSFILTER because the focus of the hardware driver is the platform transition: the movement of data between the host and the external hardware. This transition is typically handled by code associated with an AVStream queue object.

Also see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags).

## See also

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest)