# _WDF_COINSTALLER_INSTALL_OPTIONS structure

## Description

[Applies to KMDF only]

The **WDF_COINSTALLER_INSTALL_OPTIONS** structure contains installation options that a framework-based driver's installer can specify to the framework's co-installer.

## Members

### `Size`

The size, in bytes, of this structure.

### `ShowRebootPrompt`

A Boolean value. If this value is **TRUE**, and if the co-installer determines that the computer must be restarted to complete the driver installation, [WdfPreDeviceInstallEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpredeviceinstallex) informs the Plug and Play (PnP) manager, and the PnP manager prompts the user that a restart is necessary.

If this value is **FALSE**, and if the co-installer determines that the computer must be restarted to complete the driver installation, [WdfPreDeviceInstallEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpredeviceinstallex) does not inform the PnP manager.

## Remarks

The **WDF_COINSTALLER_INSTALL_OPTIONS** structure is used as an input parameter to [WdfPreDeviceInstallEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpredeviceinstallex).

Your installer should initialize the **WDF_COINSTALLER_INSTALL_OPTIONS** structure by calling [WDF_COINSTALLER_INSTALL_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdf_coinstaller_install_options_init).

## See also

[WDF_COINSTALLER_INSTALL_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdf_coinstaller_install_options_init)