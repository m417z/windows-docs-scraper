# _HBAFCPID structure

## Description

The HBAFCPID structure contains information that uniquely identifies a logical unit on a fibre channel network.

## Members

### `Fcid`

Contains the identifier that indicates which port is to be queried for information about the logical unit. For a discussion of the values that this member have, see the T11 committee's *Fibre Channel HBA API* specification.

### `NodeWWN`

Contains the 64 bit world-wide name (WWN) of the node (machine) to which the logical unit is connected. If an HBA has multiple ports and is associated with more than one node, this member will contain a name chosen from among the names of the associated nodes. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `PortWWN`

Contains the 64 bit world-wide name of the port to be queried for information about the logical unit. For a discussion of worldwide names, see the T11 committee's *Fibre Channel HBA API* specification.

### `FcpLun`

Contains a 64-bit fibre channel protocol (FCP) number for the logical unit.

## Remarks

The WMI tool suite generates a declaration for this structure in *hbapiwm.h* after compiling the [HBAFCPID WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/hbafcpid-wmi-class).

For more information about the fibre channel protocol (FCP), see the T11 committee's *dpANS Fibre Channel Protocol for SCSI* and *Fibre Channel HBA API* specifications.

## See also

[HBAFCPBindingEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry)

[HBA_FcpId](https://learn.microsoft.com/previous-versions/ff556062(v=vs.85))