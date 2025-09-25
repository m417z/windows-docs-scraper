# _GetFcpTargetMapping_OUT structure

## Description

The GetFcpTargetMapping_OUT structure is used to report the output parameter data of the [GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `TotalEntryCount`

Indicates the total number of persistent bindings associated with the HBA..

### `OutEntryCount`

Indicates the total number of mappings retrieved by the [GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping) WMI method. This value will be less than or equal to **TotalEntryCount**.

### `Entry`

Contains an array of structures of type [HBAFCPScsiEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpscsientry) that describe an HBA's bindings between operating system and fibre channel protocol (FCP) identifiers.

## Remarks

The [GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping) WMI method reports mappings between the information that uniquely identifies a set of logical units for the operating system and the fibre channel protocol (FCP) identifiers for these logical units.

The WMI tool suite generates a declaration of the GetFcpTargetMapping_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping)

[HBAFCPScsiEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpscsientry)

[HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class)