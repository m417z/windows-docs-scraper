# SetupDiGetClassInstallParamsA function

## Description

The **SetupDiGetClassInstallParams** function retrieves class installation parameters for a device information set or a particular device information element.

## Parameters

### `DeviceInfoSet` [in]

A handle to a [device information set](https://learn.microsoft.com/windows-hardware/drivers/install/device-information-sets) that contains the class install parameters to retrieve.

### `DeviceInfoData` [in, optional]

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure that specified a device information element in *DeviceInfoSet*. This parameter is optional and can be **NULL**. If this parameter is specified, **SetupDiGetClassInstallParams** retrieves the class installation parameters for the specified device. If this parameter is **NULL**, **SetupDiGetClassInstallParams** retrieves the class install parameters for the global class driver list that is associated with *DeviceInfoSet*.

### `ClassInstallParams` [out, optional]

A pointer to a buffer that contains an [SP_CLASSINSTALL_HEADER](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_classinstall_header) structure. This structure must have its **cbSize** member set to **sizeof(**SP_CLASSINSTALL_HEADER**)** on input or the buffer is considered to be invalid. On output, the **InstallFunction** member is filled with the [device installation function code](https://learn.microsoft.com/windows-hardware/drivers/install/handling-dif-codes) for the class installation parameters being retrieved. If the buffer is large enough, it also receives the class installation parameters structure specific to the function code. If *ClassInstallParams* is not specified, *ClassInstallParamsSize* must be 0.

### `ClassInstallParamsSize` [in]

The size, in bytes, of the *ClassInstallParams* buffer. If the buffer is supplied, it must be at least as large as **sizeof(**SP_CLASSINSTALL_HEADER**)**. If the buffer is not supplied, *ClassInstallParamsSize* must be 0*.*

### `RequiredSize` [out, optional]

A pointer to a variable of type DWORD that receives the number of bytes required to store the class install parameters. This parameter is optional and can be **NULL**.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The class install parameters are specific to a particular [device installation function code](https://learn.microsoft.com/windows-hardware/drivers/install/handling-dif-codes) that is stored in the **ClassInstallHeader** field located at the beginning of the *ClassInstallParams* buffer.

> [!NOTE]
> The setupapi.h header defines SetupDiGetClassInstallParams as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiSetClassInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetclassinstallparamsa)