# _KSNODE_DESCRIPTOR structure

## Description

The KSNODE_DESCRIPTOR structure describes a topology node within a filter.

## Members

### `AutomationTable`

A pointer to a [KSAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_) structure for this topology node. The automation table contains the properties, methods, and events supported by this topology node.

### `Type`

A pointer to a GUID defining the topology node.

### `Name`

A pointer to a GUID that represents the name of this topology node. This is used to return information about a [KSPROPERTY_TOPOLOGY_NAME](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-topology-name) query.

### `Alignment`

## See also

[KSFILTER_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)