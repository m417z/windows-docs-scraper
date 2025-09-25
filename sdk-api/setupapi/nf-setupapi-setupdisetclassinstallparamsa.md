# SetupDiSetClassInstallParamsA function

## Description

The **SetupDiSetClassInstallParams** function sets or clears class install parameters for a device information set or a particular device information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to the [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) for which to set class install parameters.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that represents the device for which to set class install parameters. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiSetClassInstallParams** sets the class installation parameters for the specified device. If this parameter is **NULL**, **SetupDiSetClassInstallParams** sets the class install parameters that are associated with *DeviceInfoSet*.

### `ClassInstallParams` [in, optional]

A pointer to a buffer that contains the new class install parameters to use. The [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header) structure at the beginning of this buffer must have its **cbSize** field set to **sizeof(**SP_CLASSINSTALL_HEADER**)** and the **InstallFunction** field must be set to the DI_FUNCTION code that reflects the type of parameters contained in the rest of the buffer.

If *ClassInstallParams* is not specified, the current class install parameters, if any, are cleared for the specified device information set or element.

### `ClassInstallParamsSize` [in]

The size, in bytes, of the *ClassInstallParams* buffer. If the buffer is not supplied (that is, the class install parameters are being cleared), *ClassInstallParamsSize* must be 0*.*

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

All parameters are validated before any changes are made. Therefore, a return value of **FALSE** indicates that no parameters were modified.

A side effect of setting class install parameters is that the DI_CLASSINSTALLPARAMS flag is set. If the caller wants to set the parameters, but disable their use, this flag must be cleared by a call to **SetupDiSetDeviceInstallParams**.

If the class install parameters are cleared, the DI_CLASSINSTALLPARAMS flag is reset.

> [!NOTE]
> The setupapi.h header defines SetupDiSetClassInstallParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiGetClassInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassinstallparamsa)

[SetupDiSetDeviceInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdeviceinstallparamsa)