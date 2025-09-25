# _MS_SMHBA_FC_Port structure

## Description

The MS_SMHBA_FC_Port structure is used to report the FC port information.

## Members

### `NodeWWN`

A 64-bit world-wide name (WWN) that uniquely identifies the fibre channel node that is associated with PortWWN. For more information about worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `PortWWN`

A 64-bit world-wide name (WWN) that uniquely identifies the fibre channel port. For more information about worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `FcId`

The current fibre channel address of PortWWN. The high order byte of this member contains the first byte of the address. Successively lower order bytes of this member contain successively lower bytes of the address. The lowest order byte of this member must be zero.

### `PortSupportedClassofService`

The class of service that is supported by PortWWN. For a list of the different classes of service and the values that must be assigned to this member for each class, see the ANSI standard for Fibre Channel Generic Services 4th Generation (FC-GS-4).

### `PortSupportedFc4Types`

The FC-4 types that are supported by PortWWN. For more information about FC-4 types, see the ANSI standard for Fibre Channel Generic Services 4th Generation (FC-GS-4).

### `PortActiveFc4Types`

The FC-4 types that are currently available on PortWWN. For more information about FC-4 types, see the ANSI standard for Fibre Channel Generic Services 4th Generation (FC-GS-4).

### `FabricName`

The name identifier for the fabric to which PortWWN is attached.

### `NumberofDiscoveredPorts`

The number of ports that are visible to PortWWN. For more information about the types of ports that this number takes into consideration, see the T11 committee's specification for *Fibre Channel HBA API (FC-HBA).*

### `NumberofPhys`

The number of physical fibre channel ports.

### `PortSymbolicName`

An ASCII string that is less than or equal to 256 bytes in length and that indicates the symbolic name for the fibre channel node.