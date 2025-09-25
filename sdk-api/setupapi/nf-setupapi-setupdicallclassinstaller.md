# SetupDiCallClassInstaller function

## Description

The **SetupDiCallClassInstaller** function calls the appropriate class installer, and any registered co-installers, with the specified installation request (DIF code).

## Parameters

### `InstallFunction` [in]

The device installation request (DIF request) to pass to the co-installers and class installer. DIF codes have the format **DIF_*XXX*** and are defined in Setupapi.h. See [Device Installation Function Codes](https://learn.microsoft.com/windows-hardware/drivers/install/handling-dif-codes) for more information.

**Note** For certain DIF requests, the caller must be a member of the Administrators group. For such DIF requests, this requirement is listed on the reference page for the associated default handler.

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for the local computer. This set contains a device installation element which represents the device for which to perform the specified installation function.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in the *DeviceInfoSet* that represents the device for which to perform the specified installation function. This parameter is optional and can be set to **NULL**. If this parameter is specified, **SetupDiCallClassInstaller** performs the specified function on the *DeviceInfoData* element. If *DeviceInfoData* is **NULL**, **SetupDiCallClassInstaller** calls the installers for the setup class that is associated with *DeviceInfoSet*.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by making a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

When GetLastError returns **ERROR_IN_WOW64**, this means that the calling application is a 32-bit application attempting to execute in a 64-bit environment, which is not allowed.

## Remarks

**SetupDiCallClassInstaller** calls the class installer and any co-installers that are registered for a device or a [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes). This function loads the installers if they are not yet loaded. The function also calls the default handler for the DIF request, if there is a default handler and if the installers return a status indicating that the default handler should be called.

[Device installation applications](https://learn.microsoft.com/windows-hardware/drivers/) call this function with a variety of [device installation function codes](https://learn.microsoft.com/windows-hardware/drivers/install/handling-dif-codes) (DIF codes). The function ensures that all the appropriate installers and default handlers are called, in the correct order, for a given DIF request. For more information, see [Handling DIF Codes](https://learn.microsoft.com/windows-hardware/drivers/install/handling-dif-codes).

After **SetupDiCallClassInstaller** returns **TRUE**, the device installation application must call [SetupDiGetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstallparamsa) to obtain an [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure. If the structure's **DI_NEEDREBOOT** or **DI_NEEDRESTART** flag is set, the caller must prompt the user to restart the system. For example, the caller can do this by calling [SetupPromptReboot](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptreboot).

However, be aware that a device installation application should request a system restart one time at most. Therefore, any device installation application that creates multiple calls to **SetupDiCallClassInstaller** and [SetupDiGetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstallparamsa) should save the **DI_NEEDREBOOT** and **DI_NEEDRESTART** flags after each call. However, it should prompt the user only after the last call returns.

In response to a DIF code supplied by **SetupDiCallClassInstaller**, class installers and co-installers might perform operations that require the system to be restarted. In such situations, the installer or co-installer should do the following:

1. Call [SetupDiGetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstallparamsa) to obtain the [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure.
2. Set the **DI_NEEDREBOOT** or **DI_NEEDRESTART** flag in the structure's *Flags* member.
3. Call [SetupDiSetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceinstallparamsa), supplying the updated [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure, to save the revised *Flags* member.

After **SetupDiCallClassInstaller** returns, the device installation application that called it should call [SetupDiGetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdeviceinstallparamsa), check the flags, and request a restart if necessary.

The device information set specified by *DeviceInfoSet* must only contain elements for devices on the local computer.

For information about the design and operation of co-installers, see [Writing a Co-installer](https://learn.microsoft.com/windows-hardware/drivers/install/writing-a-co-installer).

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)