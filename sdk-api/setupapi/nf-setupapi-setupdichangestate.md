# SetupDiChangeState function

## Description

The **SetupDiChangeState** function is the default handler for the [DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange) installation request.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for the local computer. This set contains a device information element that represents the device whose state is to be changed.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This is an IN-OUT parameter because *DeviceInfoData.***DevInst** might be updated with a new handle value upon return.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiChangeState** changes the state of an installed device.

The caller of **SetupDiChangeState** must be a member of the Administrators group.

**Note** Only a class installer should call **SetupDiChangeState** and only in those situations where the class installer must perform property change operations after **SetupDiChangeState** completes the default property change operation. In such situations, the class installer must directly call **SetupDiChangeState** when the installer processes a DIF_PROPERTYCHANGE request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

Callers of **SetupDiChangeState** must specify a DICS_*XXX* flag in the [SP_PROPCHANGE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_propchange_params) for the device element that indicates the type of state change to perform on the device. Callers of this function must set the appropriate fields in the SP_PROPCHANGE_PARAMS and call [SetupDiSetClassInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassinstallparamsa) before calling this function.

If you specify the DICS_FLAG_CONFIGSPECIFIC flag in the SP_PROPCHANGE_PARAMS then you must fill in the **HwProfile** field. A value of zero for **HwProfile** indicates the current profile.

To enable/disable a device in the current hardware profile, set the DICS_FLAG_CONFIGSPECIFIC flag in the SP_PROPCHANGE_PARAMS. To enable/disable a device globally, such as in both the docked and undocked hardware profiles, set the DICS_FLAG_GLOBAL flag.

This function does the following:

Callers of this function should not specify DICS_STOP or DICS_START in the SP_PROPCHANGE_PARAMS. Use DICS_PROPCHANGE to stop and restart a device to cause changes in the device's configuration to take effect.

If DI_DONOTCALLCONFIGMG is set for a device, you should not call **SetupDiChangeState** for the device but should instead set the DI_NEEDREBOOT flag.

## See also

[DIF_PROPERTYCHANGE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-propertychange)

[SP_PROPCHANGE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_propchange_params)

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)