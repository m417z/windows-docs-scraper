# CM_Enable_DevNode function

## Description

The **CM_Enable_DevNode** function enables a device.

## Parameters

### `dnDevInst` [in]

Device instance handle that is bound to the local machine.

### `ulFlags` [in]

Reserved. Must be set to zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## See also

[CM_Disable_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_disable_devnode)

[DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)