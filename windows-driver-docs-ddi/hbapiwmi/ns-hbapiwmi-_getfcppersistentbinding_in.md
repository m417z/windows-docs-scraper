# _GetFcpPersistentBinding_IN structure

## Description

The GetFcpPersistentBinding_IN structure is used to pass input parameter data to the [GetFcpPersistentBinding](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcppersistentbinding) WMI method

## Members

### `InEntryCount`

Indicates the number of binding entries that will fit in the buffer that the WMI client provides when it calls the [GetFcpPersistentBinding](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcppersistentbinding) WMI method.

## Remarks

The WMI tool suite generates a declaration of the GetFcpPersistentBinding_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetFcpPersistentBinding](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcppersistentbinding)

[MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class)