# SetupDiGetActualSectionToInstallW function

## Description

The **SetupDiGetActualSectionToInstall** function retrieves the appropriate [INF DDInstall section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section) to use when installing a device from a device INF file on a local computer.

## Parameters

### `InfHandle` [in]

The handle to the INF file that contains the *DDInstall* section.

### `InfSectionName` [in]

A pointer to the *DDInstall* section name (as specified in an [INF Models section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section)). The maximum length of the section name, in characters, is 254.

### `InfSectionWithExt` [out, optional]

A pointer to a character buffer to receive the *DDInstall* section name, its platform extension, and a NULL terminator. This is the decorated section name that should be used for installation. If this parameter is **NULL**, *InfSectionWithExtSize* must be zero. If this parameter is **NULL**, the function returns **TRUE** and sets *RequiredSize* to the size, in characters, that is required to return the *DDInstall* section name, its platform extension, and a terminating NULL character.

### `InfSectionWithExtSize` [in]

The size, in characters, of the *InfSectionWithExt* buffer. If *InfSectionWithExt* is **NULL**, this parameter must be zero.

### `RequiredSize` [out, optional]

A pointer to the variable that receives the size, in characters, that is required to return the *DDInstall* section name, the platform extension, and a terminating NULL character.

### `Extension` [out, optional]

A pointer to a variable that receives a pointer to the '.' character that marks the start of the extension in the *InfSectionWithExt* buffer. If the *InfSectionWithExt* buffer is not supplied or is too small, this parameter is not set. Set this parameter to **NULL** if a pointer to the extension is not required.

## Return value

If the function is successful, it returns **TRUE**. If the function fails, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function supports the extensions to *DDInstall* section names that are used to specify OS-specific and architecture-specific installation behaviors for a device. For information about these extensions, see [Creating INF Files for Multiple Platforms and Operating Systems](https://learn.microsoft.com/windows-hardware/drivers/install/creating-inf-files-for-multiple-platforms-and-operating-systems). **SetupDiGetActualSectionToInstall** searches for a *DDInstall* section name that matches the local computer in the manner described below.

The function first searches in the specified INF file for a decorated install section name that matches the specified name and has an extension that matches the operating system and processor architecture of the local computer. If, for example, you specify a section name of **InstallSec**, the function searches for one of the following decorated names, depending on the processor architecture of the local computer:

* For a computer that is based on the x86 processor architecture, the function searches for the decorated name **InstallSec.ntx86**.
* For a computer that is based on the x64 processor architecture, the function searches for the decorated name **InstallSec.ntamd64**.
* For a computer that is based on the Itanium processor architecture, the function searches for the decorated name **InstallSec.ntia64**.

If the function finds a match for the name, operating system, and processor architecture, it terminates the search and returns the corresponding decorated name. If the function does not find such a match, the function searches for a section whose name is **InstallSec.NT**. If the function finds a match for **InstallSec.NT**, it terminates the search and returns this name. If the function does not find a match for either of the above searches, it returns **InstallSec**, but does not verify that the INF file contains an install section whose name is **InstallSec**.

The *DDInstall* section name is used as the base for **Hardware** and **Services** section names. For example, if the *DDInstall* section name that is found is **InstallSec.NTX86**, the **Services** section name must be named **InstallSec.NTX86.Services**.

The original *DDInstall* section name that is specified in the driver node is written to the driver's registry key's **InfSection** value entry. The extension that was found is stored in the key as the REG_SZ value **InfSectionExt**. For example:

```
InfSection       : REG_SZ :    "InstallSec"
InfSectionExt    : REG_SZ :    ".NTX86"
```

If a driver is not selected for the specified device information element, a null driver is installed. Upon return, the flags in the device's [SP_DEVINSTALL_PARAMS](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinstall_params_a) structure indicate whether the system should be restarted or rebooted to cause the device to start.

> [!NOTE]
> The setupapi.h header defines SetupDiGetActualSectionToInstall as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[INF DDInstall Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section)

[SetupDiGetActualSectionToInstallEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetactualsectiontoinstallexa)

[SetupDiInstallDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstalldevice)