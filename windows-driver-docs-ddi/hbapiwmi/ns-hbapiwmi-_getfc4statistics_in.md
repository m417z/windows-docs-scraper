# _GetFC4Statistics_IN structure

## Description

The GetFC4Statistics_IN structure is used to pass input parameter data to the [GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics) WMI method.

## Members

### `PortWWN`

Contains the worldwide name for the local port of type Nx_Port whose traffic statistics are to be reported.

### `FC4Type`

Contains a value that indicates the type FC-4 protocol. For an explanation of FC4 types, see the T11 committee's *Fibre Channel Generic Services - 4* specification.

## Remarks

The method [GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics) queries an HBA and port of type Nx_Port for traffic statistics associated with the indicated FC-4 protocol.

The WMI tool suite generates a declaration of the GetFC4Statistics_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

For a definition of Nx_Port, see the T11 committee's specification for *Fibre Channel HBA API* (FC-HBA).

## See also

[GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics)