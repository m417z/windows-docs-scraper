# CM_Disable_DevNode function

## Description

The **CM_Disable_DevNode** function disables a device.

## Parameters

### `dnDevInst` [in]

Device instance handle that is bound to the local machine.

### `ulFlags` [in]

Disable flags:

#### CM_DISABLE_UI_NOT_OK

Do not display any interface to the user if the attempt to disable the device fails.

#### CM_DISABLE_PERSIST (Windows 10 and later versions of Windows)

Disables the device across reboots.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

By default, **CM_Disable_DevNode** disables a device at one time, but after reboot the device is enabled again. Starting in Windows 10, you can specify the **CM_DISABLE_PERSIST** flag to disable the device across reboots.

## See also

[CM_Enable_DevNode](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_enable_devnode)

[DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)