# _MS_SMHBA_SAS_Port structure

## Description

The MS_SMHBA_SAS_Port structure is used to report the SAS port information.

## Members

### `PortProtocol`

The protocols that are supported by this SAS port.

### `LocalSASAddress`

The Port_Identifier of this SAS port

### `AttachedSASAddress`

The SAS address of the entity that is at the opposite end of the SAS link from this local SAS port.

### `NumberofDiscoveredPorts`

The number of end ports that are visible to the local SAS port. The discovered ports might also include SMP ports that are contained within SAS expander devices.

### `NumberofPhys`

The number of physical ports that are associated with this SAS port. If the value is more than one, this SAS port is considered to be a wide port.