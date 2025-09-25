# _SetFC3MgmtInfo_IN structure

## Description

The SetFC3MgmtInfo_IN structure is used to deliver input parameter data to the [SetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/setfc3mgmtinfo) WMI method.

## Members

### `MgmtInfo`

Contains a structure of type [HBAFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafc3mgmtinfo) that holds FC3 management information that will be used to configure the fibre channel adapter.

## Remarks

The WMI tool suite generates a declaration of the SetFC3MgmtInfo_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/setfc3mgmtinfo)