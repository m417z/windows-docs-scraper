# tagWNODE_EVENT_REFERENCE structure

## Description

The **WNODE_EVENT_REFERENCE** structure contains information that WMI can use to query for an event that exceeds the event size limit set in the registry.

## Members

### `WnodeHeader`

Is a [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure that contains information common to all **WNODE_*XXX*** structures, such as the buffer size, the provider ID, the GUID that represents a data block associated with a request, and flags that provide information about the **WNODE_*XXX*** data being passed or returned.

### `TargetGuid`

Indicates the GUID that represents the event to query.

### `TargetDataBlockSize`

Indicates the size of the event.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.TargetInstanceIndex`

Indicates the index into the driver's list of static instance names for the event. This member is valid only if the event block was registered with static instance names and WNODE_FLAGS_STATIC_INSTANCE_NAMES is set in **WnodeHeader.Flags**.

### `DUMMYUNIONNAME.TargetInstanceName`

Indicates the dynamic instance name of the event as a counted Unicode string. This member is valid only if WNODE_FLAGS_STATIC_INSTANCE_NAMES is clear in **WnodeHeader.Flags** and the event block was registered with dynamic instance names.

## Remarks

If the amount of data for an event exceeds the maximum size set in the registry, a driver can generate a **WNODE_EVENT_REFERENCE** that specifies a [WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item) that WMI can query to obtain the event. For more information about defining and generating WMI events, see [Implementing WMI](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-wmi).

The **ProviderId** member of the [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure for use in a **WNODE_EVENT_REFERENCE** structure should be initialized using [IoWMIDeviceObjectToProviderId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmideviceobjecttoproviderid).

## See also

[IoWMIDeviceObjectToProviderId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmideviceobjecttoproviderid)

[WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)

[WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header)