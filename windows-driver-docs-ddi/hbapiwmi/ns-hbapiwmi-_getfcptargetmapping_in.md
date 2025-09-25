# _GetFcpTargetMapping_IN structure

## Description

The GetFcpTargetMapping_IN structure is used to report the output parameter data of the [GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping) WMI method to the WMI client.

## Members

### `HbaPortWWN`

Contains a worldwide name for the port whose table of mappings is to be retrieved.

### `InEntryCount`

Indicates the total number of persistent bindings associated with the HBA.

## Remarks

The [GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping) WMI method queries a WMI provider for mappings between the information that uniquely identifies a set of logical units for the operating system and the fibre channel protocol (FCP) identifiers for the logical units.

The WMI tool suite generates a declaration of the GetFcpTargetMapping_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping)

[MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class)