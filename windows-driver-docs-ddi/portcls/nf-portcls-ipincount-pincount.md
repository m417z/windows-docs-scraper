# IPinCount::PinCount

## Description

The `PinCount` method queries the miniport driver for its pin count.

## Parameters

### `PinId` [in]

Specifies the pin ID. If a filter contains *n* pin factories, valid pin IDs range from 0 to *n*-1.

### `FilterNecessary` [in, out]

Specifies the minimum number of pins that the pin factory should instantiate before the filter can perform I/O operations.

### `FilterCurrent` [in, out]

Specifies the current number of pin instances. This number counts the pins that the pin factory has already instantiated on the filter.

### `FilterPossible` [in, out]

Specifies the maximum number of pins that the pin factory can instantiate on the filter. Set to KSINSTANCE_INDETERMINATE if there is no maximum.

### `GlobalCurrent` [in, out]

Specifies the current number of pins that the pin factory has instantiated on the driver.

### `GlobalPossible` [in, out]

Specifies the maximum number of pins that the pin factory can instantiate on the driver. Set to KSINSTANCE_INDETERMINATE if there is no maximum.

## Remarks

The `PinCount` call has two purposes:

* To let the miniport driver know the current pin counts.
* To give the miniport driver an opportunity to alter the current pin counts.

*FilterNecessary*, *FilterCurrent*, *FilterPossible*, *GlobalCurrent*, and *GlobalPossible* are all IN+OUT parameters that point to values in the miniport driver's filter description. During the *PinCount* call, the miniport driver can examine these values and has the option of editing the values in order to more accurately indicate how many additional pins can be created from the remaining resources.

*FilterCurrent* and *FilterPossible* specify the per-filter values for the pin factory specified by *PinId*.

*GlobalCurrent* and *GlobalPossible* specify the total values for the pin factory over all instances of the filter.

Miniport drivers typically do not need to change the *FilterNecessary* parameter, but it is included for the sake of completeness.

During the [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init) call, the port driver calls the miniport driver's [IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription) method to obtain a pointer to the filter descriptor, which includes the miniport driver's pin-descriptor array (see [PCPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcpin_descriptor)). Thereafter, the port driver accesses the pin descriptors to respond to queries for pin properties.

If the miniport driver supports the **IPinCount** interface, the port driver calls `PinCount` to give the miniport driver an opportunity to update the pin counts before replying to a pin-property request. If the miniport driver does not support **IPinCount**, the port driver simply uses the static pin-count limits in the pin-descriptor array.

The port driver calls the `PinCount` method when it receives one of the following KS property requests:

[KSPROPERTY_PIN_CINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-cinstances)

[KSPROPERTY_PIN_GLOBALCINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-globalcinstances)

[KSPROPERTY_PIN_NECESSARYINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-necessaryinstances)

PortCls also calls the `PinCount` method each time a new stream is created.

Miniport drivers must not explicitly cause streams to be created or destroyed from within the `PinCount` method. Miniport drivers are not otherwise restricted in what they can do during this call.

The `PinCount` method is called at IRQL PASSIVE_LEVEL. The code for this method must reside in paged memory.

## See also

[IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription)

[IPinCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-ipincount)

[IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init)

[KSPROPERTY_PIN_CINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-cinstances)

[KSPROPERTY_PIN_GLOBALCINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-globalcinstances)

[KSPROPERTY_PIN_NECESSARYINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-necessaryinstances)

[PCPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcpin_descriptor)