# WdfPreDeviceRemove function

## Description

[Applies to KMDF only]

The co-installer's **WdfPreDeviceRemove** function performs any operations that the co-installer might require before a non-Plug and Play (PnP) driver's installer deletes the driver's kernel-mode service.

## Parameters

### `InfPath` [in]

A pointer to a null-terminated wide-character string that contains the directory path to the driver's INF file. The driver's installer can obtain this string by calling [GetCurrentDirectory](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-getcurrentdirectory), which is described in the Microsoft Windows SDK.

### `InfSectionName` [in, optional]

A pointer to a null-terminated wide-character string that contains the *Wdf-install-section* name in the driver's INF file. For more information about this name, see [Using the KMDF Co-installer](https://learn.microsoft.com/windows-hardware/drivers/wdf/installing-the-framework-s-co-installer). If this pointer is **NULL**, the co-installer uses **WdfSection** for the name.

## Return value

**WdfPreDeviceRemove** returns **ERROR_SUCCESS** if the operation succeeds. Otherwise, the function returns one of the additional **ERROR_XXX** values that are defined in Winerror.h.

## Remarks

The installer for the framework-based drivers of a non-PnP device must call **WdfPreDeviceRemove** before the installer calls [DeleteService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-deleteservice).

To obtain the address of the co-installer's **WdfPreDeviceRemove** function, the installer must call [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) after the installer has called [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) to load the co-installer.

For more information about the **WdfPreDeviceRemove** function and installers for framework-based drivers of non-PnP devices, see [Installing a Non-PnP Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/installing-a-non-pnp-driver). For more information about [DeleteService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-deleteservice), [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress), and [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya), see the Microsoft Windows SDK documentation.

#### Examples

For a code example that uses the **WdfPreDeviceRemove** function, see the installer for the [NONPNP](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample.

## See also

[WdfPostDeviceRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/nf-wdfinstaller-wdfpostdeviceremove)