# IoWMIDeviceObjectToProviderId function

## Description

The **IoWMIDeviceObjectToProviderId** routine translates the specified device object into the corresponding WMI Provider ID.

## Parameters

### `DeviceObject` [in]

Pointer to a device object.

## Return value

**IoWMIDeviceObjectToProviderId** returns the WMI Provider ID associated with the specified device object.

## Remarks

**IoWMIDeviceObjectToProviderId** should be used when filling in the **ProviderId** member of the [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure in those cases when the **WNODEHEADER** structure is being initialized as part of a [WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item) or [WNODE_EVENT_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_reference) structure. (If the **WNODE_HEADER** is being used for other purposes, *ProviderId* is reserved.)

When running on a 32-bit operating system, the provider ID and the device object are identical. When running on a 64-bit operating system, **IoWMIDeviceObjectToProviderId** will convert the 64-bit device object to a 32-bit provider ID.

## See also

[WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)

[WNODE_EVENT_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_reference)

[WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header)