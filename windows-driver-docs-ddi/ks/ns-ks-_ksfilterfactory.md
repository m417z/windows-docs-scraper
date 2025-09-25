# _KSFILTERFACTORY structure

## Description

The KSFILTERFACTORY structure represents a filter factory.

## Members

### `FilterDescriptor`

A pointer to a [KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor) structure that describes the characteristics of filters created by this factory.

### `Bag`

This member specifies the KSOBJECT_BAG (equivalent to type PVOID) associated with this filter factory. Object bags are structures used to associate dynamic memory with a specific AVStream object. Anything in the filter factory object bag is automatically cleaned up when the filter factory is deleted. See the conceptual section on [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags) for more information.

### `Context`

A pointer to a memory address that the client may use to associate context information with the filter factory. AVStream does not use this member in any way. Note that any dynamic memory associated with the filter factory should be placed in the object bag with **KsAddItemToObjectBag**. **Context** is initialized to the value of the **Context** member of the parent [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) at the time the factory is created. See [AVStream Object Hierarchy](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-object-hierarchy).

## Remarks

A filter factory explicitly represents a device's ability to instantiate a given type of filter as described by a filter descriptor.

Drivers for hardware typically use this structure to manage a particular function of the hardware that is exposed as a type of filter. Software filters generally do not need to manage the device at this level.

Filter factory objects are created in two ways. They can be created during the AddDevice processing as indicated by the device descriptor's list of filter descriptors. They can also be created explicitly by the client in a call to [KsCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatefilterfactory). The client may create filter factories at any time, but this is typically done during the processing of the PnP start IRP when an evaluation of assigned resources indicates what types of filters must be exposed by the device.

For the purposes of synchronization, the lifetime of filter factories created implicitly is defined as the interval starting when the client's device create dispatch function is (or would be) called and ending after the client's device PnP remove dispatch function is (or would be) called. The lifetime of filter factories created explicitly by calling [KsCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatefilterfactory) starts immediately after that call returns.

Also see [Object Bags](https://learn.microsoft.com/windows-hardware/drivers/stream/object-bags).

## See also

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KsAddItemToObjectBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksadditemtoobjectbag)

[KsCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatefilterfactory)