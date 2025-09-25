# WdfPreDeviceInstallEx function

## Description

[Applies to KMDF only]

The co-installer's **WdfPreDeviceInstallEx** function performs any operations that the co-installer might require before a non-Plug and Play (PnP) driver's installer creates the driver's kernel-mode service.

## Parameters

### `InfPath` [in]

A pointer to a null-terminated wide-character string that contains the directory path to the driver's INF file. The driver's installer can obtain this string by calling **GetCurrentDirectory**, which is described in the Microsoft Windows SDK.

### `InfSectionName` [in, optional]

A pointer to a null-terminated wide-character string that contains the *Wdf-install-section* name in the driver's INF file. For more information about this name, see [Using the KMDF Co-installer](https://learn.microsoft.com/windows-hardware/drivers/wdf/installing-the-framework-s-co-installer). If this pointer is **NULL**, the co-installer uses **WdfSection** for the name.

### `ClientOptions` [in]

A pointer to a caller-allocated [WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options)-typed structure that contains driver-specified installation options.

## Return value

**WdfPreDeviceInstallEx** returns ERROR_SUCCESS if the operation succeeds. Otherwise, the function returns one of the additional ERROR_*XXX* values that are defined in *Winerror.h*.

## Remarks

The installer for the framework-based drivers of a non-PnP device must call [WdfPreDeviceInstall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpredeviceinstall) or **WdfPreDeviceInstallEx** before the installer calls **CreateService**.

To obtain the address of the co-installer's **WdfPreDeviceInstallEx** function, the installer must call **GetProcAddress** after the installer has called **LoadLibrary** to load the co-installer.

If the co-installer determines that the computer must be restarted to complete the driver installation (typically because an older version of the framework was previously installed), the **WdfPreDeviceInstallEx** function enables you to control when or whether the user is prompted to restart the computer, as follows:

* If the installer sets the *ShowRebootPrompt* member of the [WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options) structure to **TRUE**, **WdfPreDeviceInstallEx** informs the PnP manager that the computer must be restarted, and the PnP manager prompts the user that a restart is necessary. Setting the *ShowRebootPrompt* member to **TRUE** is equivalent to calling [WdfPreDeviceInstall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpredeviceinstall).
* If the installer sets the *ShowRebootPrompt* member of the [WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options) structure to **FALSE**, **WdfPreDeviceInstallEx** does not inform the PnP manager that a restart is necessary. Instead, the function returns **ERROR_SUCCESS_REBOOT_REQUIRED**. Your installer can determine when or whether to restart the computer,

For more information about the **WdfPreDeviceInstallEx** function and installers for framework-based drivers of non-PnP devices, see [Installing a Non-PnP Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/installing-a-non-pnp-driver). For more information about **CreateService**, **GetProcAddress**, and **LoadLibrary**, see the Microsoft Windows SDK documentation.

#### Examples

For a code example that uses the **WdfPreDeviceInstallEx** function, see the installer for the [NONPNP](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample.

## See also

[WdfPostDeviceInstall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpostdeviceinstall)

[WdfPreDeviceInstall](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpredeviceinstall)