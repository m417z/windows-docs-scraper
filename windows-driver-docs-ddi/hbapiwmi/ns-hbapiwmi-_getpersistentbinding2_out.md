# _GetPersistentBinding2_OUT structure

## Description

The GetBindingSupport_OUT structure is used to report the output parameter data of the [GetPersistentBinding2](https://learn.microsoft.com/windows-hardware/drivers/storage/getpersistentbinding2) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `TotalEntryCount`

Indicates the number of binding entries that the WMI provider can report.

### `OutEntryCount`

Indicates the total number of persistent bindings retrieved by the GetPersistentBinding2 method.

### `Bindings`

Contains an array of structures of type [HBAFCPBindingEntry2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry2) that describe an HBA's bindings between operating system and fibre channel protocol (FCP) identifiers.

## Remarks

The WMI tool suite generates a declaration of the GetPersistentBinding2_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetPersistentBinding2](https://learn.microsoft.com/windows-hardware/drivers/storage/getpersistentbinding2)