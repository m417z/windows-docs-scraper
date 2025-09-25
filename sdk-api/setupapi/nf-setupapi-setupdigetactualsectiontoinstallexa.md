# SetupDiGetActualSectionToInstallExA function

## Description

The **SetupDiGetActualSectionToInstallEx** function retrieves the name of the [INF DDInstall section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section) that installs a device for a specified operating system and processor architecture.

## Parameters

### `InfHandle` [in]

A handle to the INF file that contains the *DDInstall* section.

### `InfSectionName` [in]

A pointer to the *DDInstall* section name (as specified in an [INF Models section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-models-section)). The maximum length of the section name, in characters, is 254.

### `AlternatePlatformInfo` [in, optional]

A pointer, if non-**NULL**, to an [SP_ALTPLATFORM_INFO](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_altplatform_info_v2) structure. This structure is used to specify an operating system and processor architecture that is different from that on the local computer. To return the *DDInstall* section name for the local computer, set this parameter to **NULL**. Otherwise, provide an SP_ALTPLATFORM structure and set its members as follows:

#### cbSize

Set to the size, in bytes, of an SP_ALTPLATFORM_INFO structure.

#### Platform

Set to VER_PLATFORM_WIN32_NT for Windows XP and later versions of Windows.

#### MajorVersion

Not used.

#### MinorVersion

Not Used.

#### ProcessorArchitecture

Set one of the following processor architecture constants.

| Processor Architecture Constant | Meaning |
| --- | --- |
| PROCESSOR_ARCHITECTURE_INTEL | The alternative platform is an x86-based processor architecture. |
| PROCESSOR_ARCHITECTURE_IA64 | The alternative platform is an Itanium-based processor architecture. |
| PROCESSOR_ARCHITECTURE_AMD64 | The alternative platform is an x64-based processor architecture. |

#### Reserved

Set to zero.

### `InfSectionWithExt` [out, optional]

A pointer to a character buffer to receive the *DDInstall* section name, its platform extension, and a NULL terminator. This is the decorated section name that should be used for installation. If this parameter is **NULL**, the function returns **TRUE** and sets *RequiredSize* to the size, in characters, that is required to return the *DDInstall* section name, its platform extension, and a terminating NULL character.

### `InfSectionWithExtSize` [in]

The size, in characters, of the buffer that is pointed to by the *InfSectionWithExt* parameter. The maximum length of a NULL-terminated INF section name, in characters, is MAX_INF_SECTION_NAME_LENGTH.

### `RequiredSize` [out, optional]

A pointer to the variable that receives the size, in characters, that is required to return the *DDInstall* section name, the platform extension, and a terminating NULL character.

### `Extension` [out, optional]

A pointer to a variable that receives a pointer to the '.' character that marks the start of the extension in the *InfSectionWithExt* buffer. If the *InfSectionWithExt* buffer is not supplied or is too small, this parameter is not set. Set this parameter to **NULL** if a pointer to the extension is not required.

### `Reserved`

Reserved for internal use only. Must be set to **NULL**.

## Return value

If the function is successful, it returns **TRUE**. Otherwise, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetupDiGetActualSectionToInstallEx** is an extended form of [SetupDiGetActualSectionToInstall](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetactualsectiontoinstalla). These functions support the extensions to *DDInstall* section names that are used to specify OS-specific and architecture-specific installation actions for a device. For information about these extensions, see [Creating INF Files for Multiple Platforms and Operating Systems](https://learn.microsoft.com/windows-hardware/drivers/install/creating-inf-files-for-multiple-platforms-and-operating-systems).

If you do not supply alternative platform information with a call to **SetupDiGetActualSectionToInstallEx**, the function performs the same operation as **SetupDiGetActualSectionToInstall**. The latter function searches for the specified install section name using the platform information for the local computer.

If you supply alternative platform information with a call to **SetupDiGetActualSectionToInstallEx**, the function does the following:

* If you specify a platform of VER_PLATFORM_WIN32_NT, the function first searches in the specified INF file for a decorated install section name that matches the name, operating system, and processor architecture that you specify. If, for example, you specify an install section name of **InstallSec**, the function searches for one of the following decorated names, depending on the specified processor architecture:
  + If you specify the x86-based processor architecture, the function searches for the decorated name **InstallSec.ntx86**.
  + If you specify the x64-based processor architecture, the function searches for the decorated name **InstallSec.ntamd64**.
  + If you specify the Itanium-based processor architecture, the function searches for the decorated name **InstallSec.ntia64**.

  If the function finds a match for the name, operating system, and processor architecture, it terminates the search and returns the corresponding decorated name. If the function does not find such a match, the function searches for a section whose name is **InstallSec.nt**. If the function finds a match for **InstallSec.nt**, it terminates the search and returns this name. If the function does not find a match for either of the above searches, it returns **InstallSec**, but does not verify that the INF file contains an install section whose name is **InstallSec**.

> [!NOTE]
> The setupapi.h header defines SetupDiGetActualSectionToInstallEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[INF DDInstall Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-ddinstall-section)

[SetupDiGetActualSectionToInstallEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetactualsectiontoinstallexa)

[SetupDiInstallDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstalldevice)