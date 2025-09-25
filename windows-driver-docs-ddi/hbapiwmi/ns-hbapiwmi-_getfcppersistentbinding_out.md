# _GetFcpPersistentBinding_OUT structure

## Description

The GetFcpPersistentBinding_OUT structure is used to report the output parameter data of the [GetFcpPersistentBinding](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcppersistentbinding) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see HBA_STATUS.

### `TotalEntryCount`

Indicates the total number of persistent bindings retrieved by the [GetFcpPersistentBinding](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcppersistentbinding) WMI method.

### `OutEntryCount`

Indicates the total number of mappings retrieved by the [GetFcpTargetMapping](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcptargetmapping) WMI method. This value will be less than or equal to **TotalEntryCount**.

### `Entry`

Contains an array of structures of type HBAFCPBindingEntry that describe an HBA's bindings between operating system and fibre channel protocol (FCP) identifiers.

## Remarks

The [GetFcpPersistentBinding](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcppersistentbinding) WMI method retrieves the bindings between SCSI and fibre channel protocol (FCP) identifiers for the logical units.

The WMI tool suite generates a declaration of the GetFcpPersistentBinding_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetFcpPersistentBinding](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcppersistentbinding)