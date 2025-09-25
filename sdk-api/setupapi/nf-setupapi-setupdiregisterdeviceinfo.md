# SetupDiRegisterDeviceInfo function

## Description

The
**SetupDiRegisterDeviceInfo** function is the default handler for the [DIF_REGISTERDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-registerdevice) request.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains a device information element that represents the device to register. The device information set must not contain any remote elements.

### `DeviceInfoData` [in, out]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specifies the device information element in *DeviceInfoSet*. This is an IN-OUT parameter because *DeviceInfoData.***DevInst** might be updated with a new handle value upon return.

### `Flags` [in]

A flag value that controls how the device is registered, which can be zero or the following value:

#### SPRDI_FIND_DUPS

Search for a previously-existing [device instance](https://learn.microsoft.com/windows-hardware/drivers/) that corresponds to the device that is represented by *DeviceInfoData*. If this flag is not specified, the device instance is registered regardless of whether a device instance already exists for it.

If the caller supplies *CompareProc*, the caller must also set this flag.

### `CompareProc` [in, optional]

A pointer to a comparison callback function to use in duplicate detection. This parameter is optional and can be **NULL**. If this parameter is specified, the callback function is called for each device instance that is of the same class as the device instance that is being registered. The prototype of the callback function is as follows:

```
typedef  DWORD (CALLBACK* PSP_DETSIG_CMPPROC) (
    IN HDEVINFO  DeviceInfoSet,
    IN PSP_DEVINFO_DATA  NewDeviceData,
    IN PSP_DEVINFO_DATA  ExistingDeviceData,
    IN PVOID  CompareContextOPTIONAL
    );
```

The compare function must return ERROR_DUPLICATE_FOUND if it finds that the two devices are duplicates. Otherwise, it should return NO_ERROR. If some other error is encountered, the callback function should return the appropriate ERROR_* code to indicate the failure.

If *CompareProc* is not specified and duplication detection is requested, a default comparison behavior is used. The default is to compare the new device's detect signature with the detect signature of all other devices in the class. The detect signature is contained in the class-specific resource descriptor of the device's boot log configuration.

### `CompareContext` [in, optional]

A pointer to a caller-supplied context buffer that is passed into the callback function. This parameter is ignored if *CompareProc* is not specified.

### `DupDeviceInfoData` [out, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure to receive information about a duplicate device instance, if any, discovered as a result of attempting to register this device. This parameter is optional and can be **NULL**. If this parameter is specified, the caller must set *DupDeviceInfoData.***cbSize** to **sizeof**(SP_DEVINFO_DATA). This will be filled in if the function returns **FALSE**, and [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_DUPLICATE_FOUND. This device information element is added as a member of the specified *DeviceInfoSet*, if not already a member. If *DupDeviceInfoData* is not specified, the duplicate is not added to the device information set.

If you call this function when handling a [DIF_REGISTERDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-registerdevice) request, the *DupDeviceInfoData* parameter must be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiRegisterDeviceInfo** is primarily designed to register a non-PnP device with the [Plug and Play (PnP) manager](https://learn.microsoft.com/windows-hardware/drivers/install/pnp-manager) on a local computer. Although **SetupDiRegisterDeviceInfo** will not fail if the device information set is for a remote computer, the result is of limited use because the device information set cannot subsequently be used with DIF_*Xxx* installation requests or **SetupDi***Xxx* functions that do not support operations on a remote computer. For example, calling **SetupDiCreateDevRegKey** to execute an INF section for a newly registered device on a remote computer will fail.

**Note** Only a class installer should call **SetupDiRegisterDeviceInfo** and only in those situations where the class installer must perform device registration operations after **SetupDiRegisterDeviceInfo** completes the default device registration operation. In such situations, the class installer must directly call **SetupDiRegisterDeviceInfo** when the installer processes a DIF_REGISTERDEVICE request. For more information about calling the default handler, see [Calling Default DIF Code Handlers](https://learn.microsoft.com/windows-hardware/drivers/install/calling-the-default-dif-code-handlers).

After registering a device information element, the caller should update any stored copies of the **DevInst** handle associated with this device. This is necessary because the handle value might have changed during registration. The caller does not have to retrieve the SP_DEVINFO_DATA structure again because the **DevInst** field of the structure is updated to reflect the current value of the handle.

Do not directly call this function for PnP device instances. PnP device instances are automatically registered by the operating system. However, you must register non-PnP device instances in one of the following ways:

1. If your installation application uses a [DIF_DETECT](https://learn.microsoft.com/windows-hardware/drivers/install/dif-detect) request to successfully detect a device, it should also use a DIF_REGISTERDEVICE request to register the device instance. The request should be handled in the default manner. (By default, [SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller) first calls the class installer and class co-installers to do duplicate detection and register the device instance. If these installers do not register the device instance, **SetupDiCallClassInstaller** calls **SetupDiRegisterDeviceInfo** to do duplicate detection and register the device instance.)
2. If your installation application creates a device instance (for example, by calling [SetupDiCreateDeviceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinfoa)) but does not do duplicate detection, your installation application should use a DIF_REGISTERDEVICE request to register the device instance. The request should be handled in the default manner as described earlier.
3. If your installation application creates a new device and does duplicate detection, your installation application should use a DIF_REGISTERDEVICE request but should prevent **SetupDiCallClassInstaller** from calling **SetupDiRegisterDeviceInfo**. To prevent **SetupDiCallClassInstaller** from calling **SetupDiRegisterDeviceInfo**, set the DI_NODI_DEFAULTACTION flag in the **Flags** member of the SP_DEVINSTALL_PARAMS structure for the device instance.

   If **SetupDiCallClassInstaller** returns **TRUE** for the DIF_REGISTERDEVICE request, the class installer or class co-installers registered the device instance. In this case, the installation application can continue to install the device.

   If **SetupDiCallClassInstaller** returns **FALSE** for the DIF_REGISTERDEVICE request, the class installer or class co-installers did not register the device instance. In this case, the installation application should do one of the following, depending on the last error that [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns for the request:

   * If the last error is ERROR_DI_DO_DEFAULT, the installation application can directly call **SetupDiRegisterDeviceInfo** and supply a *CompareProc* to do duplicate detection. If this call is successful and no duplicates are found, device installation can continue. If a duplicate is found, **SetupDiRegisterDeviceInfo** returns **FALSE**, and the installation application must terminate device installation.
   * If the last error is not ERROR_DI_DO_DEFAULT, the installation application must terminate device installation.The caller of **SetupDiRegisterDeviceInfo** must be a member of the Administrators group.

## See also

[DIF_REGISTERDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-registerdevice)

[SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data)

[SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a)