# _HBAFC3MgmtInfo structure

## Description

The HBAFC3MgmtInfo structure is used to report FC3 management information associated with a fibre channel adapter.

## Members

### `UniqueAdapterId`

Contains a unique identifier for the adapter.

### `wwn`

Contains a worldwide name for the adapter, as described in the T11 committee's *Fibre Channel HBA API* specification.

### `unittype`

Describes the type of HBA, as described in the T11 committee's *Fibre Channel HBA API* specification.

### `PortId`

Contains a value corresponding to the physical port number field of the specific identification data as described in the T11 committee's *Fibre Channel HBA API* specification.

### `NumberOfAttachedNodes`

Contains the number of nodes attached to the topology as described in the T11 committee's *Fibre Channel HBA API* specification.

### `IPVersion`

Contains the concatenated node management and IP version fields of the specific identification data as described in the T11 committee's *Fibre Channel HBA API* specification.

### `UDPPort`

Indicates the value of the UDP/TCP port number field of the specific identification data as described in the T11 committee's *Fibre Channel HBA API* specification.

### `IPAddress`

Indicates the value of the IP address field of the specific identification data as described in the T11 committee's *Fibre Channel HBA API* specification.

### `reserved`

Reserved.

### `TopologyDiscoveryFlags`

Indicates the value of the vendor specific field in word 12 of the specific identification data as described in the T11 committee's *Fibre Channel HBA API* specification.

### `reserved1`

Reserved.

## Remarks

FC-3 refers to the common services layer of the fibre channel protocol. It defines a set of services which are common across multiple ports of a node. For an explanation of the common services layer, see the T11 committee's *Fibre Channel HBA API* specification.

The WMI tool suite generates a declaration of this structure automatically when it compiles the **HBAFC3MgmtInfo** WMI Class in *hbaapi.mof*.

## See also

[GetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc3mgmtinfo)