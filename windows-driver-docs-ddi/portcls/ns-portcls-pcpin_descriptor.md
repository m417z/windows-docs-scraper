# PCPIN_DESCRIPTOR structure

## Description

The **PCPIN_DESCRIPTOR** structure describes a pin factory.

## Members

### `MaxGlobalInstanceCount`

Specifies the global maximum number of times that this pin type can be instantiated. The global maximum counts the number of pin instances that the adapter driver can support across all instances of the filter. The count can be set to zero to indicate that the pin cannot be instantiated. A value of ULONG(-1) indicates the pin can be instantiated any number of times. Any other value indicates a specific number of times that the pin can be instantiated.

### `MaxFilterInstanceCount`

Specifies the maximum number times that the pin can be instantiated on a single instance of the filter. The count can be set to zero to indicate that the pin cannot be instantiated. A value of ULONG(-1) indicates the pin can be instantiated any number of times. Any other value indicates a specific number of times that the pin can be instantiated.

### `MinFilterInstanceCount`

Specifies the minimum number of times that the pin needs to be instantiated on an instance of the filter. This member is a definite lower bound on the number of instances of a pin that must exist in order for a filter to be able to function.

### `AutomationTable`

Pointer to the automation table. This member is a pointer to a structure of type [PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table). The pointer can be **NULL** to indicate that no automation is supported. The automation table specifies the handlers for the properties and events belonging to the pin instance.

### `KsPinDescriptor`

Describes the pin factory. This member is a structure of type [KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor). A pin factory can have zero interfaces and zero mediums. The list of interfaces is ignored in all cases. The standard-medium list will default to a list containing only device I/O (KSMEDIUM_STANDARD_DEVIO).

## Remarks

This structure is used to describe each of the pin factories that a miniport driver implements. The driver's [PCFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcfilter_descriptor) structure contains a pointer to an array of **PCPIN_DESCRIPTOR** structures. The number of elements in the array is equal to the number of pin factories in the filter.

The **MaxGlobalInstanceCount**, **MaxFilterInstanceCount**, and **MinFilterInstanceCount** members are maximum and minimum counts that describe the pin's resource restrictions and functional requirements. An autoinitialized **PCPIN_DESCRIPTOR** array can present only a static estimate of the available pin resources. The [IPinCount::PinCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-ipincount-pincount) method provides a means for the driver to revise its list of available pin resources dynamically as pins are allocated and freed.

The **MaxGlobalInstanceCount** value is similar in meaning to:

* The [PinCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-ipincount-pincount) method's *GlobalPossible* call parameter.
* The [KSPROPERTY_PIN_GLOBALCINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-globalcinstances) property value (the KSPIN_CINSTANCES structure's **PossibleCount** member).

The **MaxFilterInstanceCount** value is similar in meaning to:

* The [PinCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-ipincount-pincount) method's *FilterPossible* call parameter.
* The [KSPROPERTY_PIN_CINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-cinstances) property value (the KSPIN_CINSTANCES structure's **PossibleCount** member).

The **MinFilterInstanceCount** value is similar in meaning to:

* The [PinCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-ipincount-pincount) method's *FilterNecessary* call parameter.
* The [KSPROPERTY_PIN_NECESSARYINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-necessaryinstances) property value.

When describing a bridge pin (see [Audio Filter Graphs](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-filter-graphs)), set **MaxGlobalInstanceCount**, **MaxFilterInstanceCount**, and **MinFilterInstanceCount** to zero, and set **AutomationTable** to **NULL**.

For a simple code example that shows how the **PCPIN_DESCRIPTOR** structure is used, see [Exposing Filter Topology](https://learn.microsoft.com/windows-hardware/drivers/audio/exposing-filter-topology).

For more information, see [Pin Factories](https://learn.microsoft.com/windows-hardware/drivers/audio/pin-factories).

## See also

[IPinCount::PinCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-ipincount-pincount)

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)

[KSPROPERTY_PIN_CINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-cinstances)

[KSPROPERTY_PIN_GLOBALCINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-globalcinstances)

[KSPROPERTY_PIN_NECESSARYINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-necessaryinstances)

[PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table)