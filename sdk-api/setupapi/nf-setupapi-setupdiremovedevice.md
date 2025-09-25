# SetupDiRemoveDevice function

## Description

The **SetupDiRemoveDevice** function is the default handler for the [DIF_REMOVE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-remove) installation request.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for the local system that contains a device information element that represents the device to remove.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This is an IN-OUT parameter because *DeviceInfoSet*.**DevInst** might be updated with a new handle value upon return. If this is a global removal or the last hardware profile-specific removal, all traces of the device instance are deleted from the registry and the handle will be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved by a call to **GetLastError**.

## Remarks

**SetupDiRemoveDevice** removes the device from the system. It deletes the device's hardware and software registry keys and any hardware-profile-specific registry keys (configuration-specific registry keys). This function dynamically stops the device if its **DevInst** is active and this is a global removal or the last configuration-specific removal. If the device cannot be dynamically stopped, flags are set in the Install Parameter block of the device information set that eventually cause the user to be prompted to restart the computer.

Device removal is either global to all hardware profiles or specific to one hardware profile as specified by the **Scope** member of the [SP_REMOVEDEVICE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_removedevice_params) structure that supplies the class installation parameters for the DIF_REMOVE request. Configuration-specific removal is only appropriate for root-enumerated devices and should only be requested by system code.

The caller of **SetupDiRemoveDevice** must be a member of the Administrators group.

**Note** Only a [class installer](https://learn.microsoft.com/windows-hardware/drivers/) should call **SetupDiRemoveDevice**  and only in those situations where the class installer must perform device removal operations after **SetupDiRemoveDevice**  completes the default device removal operation. In such situations, the class installer must directly call **SetupDiRemoveDevice** when the installer processes a DIF_REMOVE request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

## See also

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SP_REMOVEDEVICE_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_removedevice_params)