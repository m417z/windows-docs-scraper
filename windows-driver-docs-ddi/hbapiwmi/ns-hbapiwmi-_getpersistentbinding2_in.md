# _GetPersistentBinding2_IN structure

## Description

The GetPersistentBinding2_IN structure is used to deliver input parameter data to the [GetPersistentBinding2](https://learn.microsoft.com/windows-hardware/drivers/storage/getpersistentbinding2) WMI method.

## Members

### `PortWWN`

Contains a worldwide name that indicates the port whose persistent bindings are to be retrieved.

### `InEntryCount`

Indicates the number of binding entries that the WMI provider can report.

## Remarks

The WMI tool suite generates a declaration of the GetPersistentBinding2_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetPersistentBinding2](https://learn.microsoft.com/windows-hardware/drivers/storage/getpersistentbinding2)