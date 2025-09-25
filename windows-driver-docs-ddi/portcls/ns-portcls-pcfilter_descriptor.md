# PCFILTER_DESCRIPTOR structure

## Description

The **PCFILTER_DESCRIPTOR** structure describes a miniport driver's implementation of a filter. The structure specifies the filter's pins, nodes, connections, and properties.

## Members

### `Version`

Reserved. Initialize to zero.

### `AutomationTable`

Pointer to the automation table. This is a structure of type [PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table). The automation table specifies the handlers for the properties of the filter instance.

### `PinSize`

Specifies the size in bytes of each element in the **Pins** array. This value should be a multiple of eight and should be at least **sizeof**([PCPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcpin_descriptor)). Larger values allow client-specific descriptor information to be appended to pin descriptors.

### `PinCount`

Specifies the number of pin descriptors in the **Pins** array.

### `Pins`

Pointer to the array of pin descriptors. Each array element is a [PCPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcpin_descriptor) structure.

### `NodeSize`

Specifies the size in bytes of each element in the **Nodes** array. This value should be a multiple of eight and should be at least **sizeof**([PCNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcnode_descriptor)). Larger values allow client-specific descriptor information to be appended to node descriptors.

### `NodeCount`

Specifies the number of node descriptors in the **Nodes** array.

### `Nodes`

Pointer to the array of node descriptors. Each array element is a [PCNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcnode_descriptor) structure.

### `ConnectionCount`

Specifies the number of connections in the **Connections** array.

### `Connections`

Pointer to the array of connections descriptors. Each array element is a [PCCONNECTION_DESCRIPTOR](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537688(v=vs.85)) structure.

### `CategoryCount`

Specifies the number of GUIDs in the **Categories** array.

### `Categories`

Pointer to the array of GUIDs that specifies the categories that the object belongs to. See the discussion of topology categories in [Installing Device Interfaces for an Audio Adapter](https://learn.microsoft.com/windows-hardware/drivers/audio/installing-device-interfaces-for-an-audio-adapter).

## Remarks

A port driver obtains the miniport driver's filter descriptor by calling the [IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription) method. The filter descriptor is a **PCFILTER_DESCRIPTOR** structure describing the miniport driver's pins, nodes, connections, and properties. For more information, see [Filter, Pin, and Node Properties](https://learn.microsoft.com/windows-hardware/drivers/audio/filter--pin--and-node-properties).

## See also

[IMiniport::GetDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-getdescription)

[PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table)

[PCCONNECTION_DESCRIPTOR](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537688(v=vs.85))

[PCNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcnode_descriptor)

[PCPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcpin_descriptor)