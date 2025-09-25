# PCNODE_DESCRIPTOR structure

## Description

The **PCNODE_DESCRIPTOR** structure describes a node in the filter that a topology miniport driver implements.

## Members

### `Flags`

Set to zero. No flag bits are currently defined.

### `AutomationTable`

Pointer to the automation table, which is a structure of type [PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table). This member can be set to **NULL** to indicate no automation support. The automation table specifies the handlers for the properties and events belonging to the node instance.

### `Type`

Specifies the node type. This member is a pointer to a GUID that uniquely identifies the node type. See the list of node-type GUIDs in [Audio Topology Nodes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-topology-nodes).

### `Name`

Pointer to a GUID that represents the name of this topology node. This GUID is specified in a [KSPROPERTY_TOPOLOGY_NAME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-topology-name)get-property request to obtain the corresponding name string for the node. This pointer can be set to **NULL** to indicate that the GUID in the **Type** member should be used to determine the node name.

## Remarks

If a filter contains only a single node of the type specified by the **Type** member, then the **Name** member can be specified as **NULL** because the **Type** value is sufficient to uniquely identify the node within the filter. If the filter contains two or more nodes of the same type, the **Name** members for those nodes must be non-**NULL**.

For example, if a filter contains a single SUM node, the **Type** member for that node points to GUID value [KSNODETYPE_SUM](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-sum), and the **Name** member is set to **NULL**. When queried for the name of that node, the [KSPROPERTY_TOPOLOGY_NAME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-topology-name) property, after determining that the node's **Name** value is **NULL**, retrieves the name string from the registry entry for the KSNODETYPE_SUM GUID. However, the same filter might contain several volume nodes, in which case the **Type** values for these nodes all point to the same GUID value, [KSNODETYPE_VOLUME](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-volume), and the **Name** value must uniquely identify each of the volume nodes. The **Name** value for the wave-input volume control node, for example, should point to GUID value KSAUDFNAME_WAVE_IN_VOLUME (defined in ksmedia.h). The registry entry for this GUID contains the name string that the KSPROPERTY_TOPOLOGY_NAME property retrieves for the node.

The [PCFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcfilter_descriptor) structure contains a pointer to an array of **PCNODE_DESCRIPTOR** structures.

For a simple code example that shows how the **PCNODE_DESCRIPTOR** structure is used, see [Exposing Filter Topology](https://learn.microsoft.com/windows-hardware/drivers/audio/exposing-filter-topology).

## See also

[KSPROPERTY_TOPOLOGY_NAME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-topology-name)

[PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table)

[PCFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcfilter_descriptor)