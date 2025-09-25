# WdfPostDeviceRemove function

## Description

[Applies to KMDF only]

The co-installer's **WdfPostDeviceRemove** function performs any operations that the co-installer might require after a non-Plug and Play (PnP) driver's installer has deleted the driver's kernel-mode service.

## Parameters

### `InfPath` [in]

A pointer to a null-terminated wide-character string that contains the directory path to the driver's INF file. The driver's installer can obtain this string by calling **GetCurrentDirectory**, which is described in the Microsoft Windows SDK.

### `InfSectionName` [in, optional]

A pointer to a null-terminated wide-character string that contains the *Wdf-install-section* name in the driver's INF file. For more information about this name, see [Using the KMDF Co-installer](https://learn.microsoft.com/windows-hardware/drivers/wdf/installing-the-framework-s-co-installer). If this pointer is **NULL**, the co-installer uses **WdfSection** for the name.

## Return value

**WdfPostDeviceRemove** returns ERROR_SUCCESS if the operation succeeds. Otherwise, the function returns one of the additional ERROR_*XXX* values that are defined in *Winerror.h*.

## Remarks

The installer for the framework-based drivers of a non-PnP device must call **WdfPostDeviceRemove** after the installer calls **DeleteService**.

To obtain the address of the co-installer's **WdfPostDeviceRemove** function, the installer must call **GetProcAddress** after the installer has called **LoadLibrary** to load the co-installer.

For more information about the **WdfPostDeviceRemove** function and installers for framework-based drivers of non-PnP devices, see [Installing a Non-PnP Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/installing-a-non-pnp-driver). For more information about **DeleteService**, **GetProcAddress**, and **LoadLibrary**, see the Microsoft Windows SDK documentation.

#### Examples

For a code example that uses the **WdfPostDeviceRemove** function, see the installer for the [NONPNP](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample.

## See also

[WdfPreDeviceRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpredeviceremove)