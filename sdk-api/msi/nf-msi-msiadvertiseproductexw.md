# MsiAdvertiseProductExW function

## Description

The
**MsiAdvertiseProductEx** function generates an advertise script or advertises a product to the computer. This
function enables Windows Installer to write to a script the registry and shortcut information used to assign or publish a product. The script can be written to be consistent with a specified platform by using
**MsiAdvertiseProductEx**. The **MsiAdvertiseProductEx** function provides the same functionality as
[MsiAdvertiseProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiadvertiseproducta).

## Parameters

### `szPackagePath` [in]

The full path to the package of the product being advertised.

### `szScriptfilePath` [in]

The full path to the script file to be created with the advertised information. To advertise the product locally to the computer, set ADVERTISEFLAGS_MACHINEASSIGN or ADVERTISEFLAGS_USERASSIGN.

| Flag | Meaning |
| --- | --- |
| **ADVERTISEFLAGS_MACHINEASSIGN**<br><br>0 | Set to advertise a per-computer installation of the product available to all users. |
| **ADVERTISEFLAGS_USERASSIGN**<br><br>1 | Set to advertise a per-user installation of the product available to a particular user. |

### `szTransforms` [in]

A semicolon–delimited list of transforms to be applied. The list of transforms can be prefixed with the @ or | character to specify the secure caching of transforms. The @ prefix specifies secure-at-source transforms and the | prefix indicates secure full path–transforms. For more information, see
[Secured Transforms](https://learn.microsoft.com/windows/desktop/Msi/secured-transforms). This parameter may be null.

### `lgidLanguage` [in]

The language to use if the source supports multiple languages.

### `dwPlatform` [in]

Bit flags that control for which platform the installer should create the script. This parameter is ignored if *szScriptfilePath* is null. If *dwPlatform* is zero (0), then the script is created based on the current platform. This is the same functionality as
[MsiAdvertiseProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiadvertiseproducta). If *dwPlatform* is 1 or 2, the installer creates script for the specified platform.

| Flag | Meaning |
| --- | --- |
| **none**<br><br>0 | Creates a script for the current platform. |
| **MSIARCHITECTUREFLAGS_X86**<br><br>1 | Creates a script for the x86 platform. |
| **MSIARCHITECTUREFLAGS_IA64**<br><br>2 | Creates a script for Itanium-based systems. |
| **MSIARCHITECTUREFLAGS_AMD64**<br><br>4 | Creates a script for the x64 platform. |

### `dwOptions` [in]

Bit flags that specify extra advertisement options. Nonzero value is only available in Windows Installer versions shipped with Windows Server 2003 and Windows XP with SP1 and later.

| Flag | Meaning |
| --- | --- |
| **MSIADVERTISEOPTIONS_INSTANCE**<br><br>1 | Multiple instances through product code changing transform support flag. Advertises a new instance of the product. Requires that the *szTransforms* parameter includes the instance transform that changes the product code. For more information, see [Installing Multiple Instances of Products and Patches](https://learn.microsoft.com/windows/desktop/Msi/installing-multiple-instances-of-products-and-patches). |

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | The function completes successfully. |
| **An error that relates to an action** | For more information, see [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An initialization error has occurred. |
| **ERROR_CALL_NOT_IMPLEMENTED** | This error is returned if an attempt is made to generate an advertise script on any platform other than Windows 2000 or Windows XP. Advertisement to the local computer is supported on all platforms. |

## Remarks

Multiple instances through product code–changing transforms is only available for Windows Installer versions shipping with Windows Server 2003 and Windows XP with SP1 and later.

> [!NOTE]
> The msi.h header defines MsiAdvertiseProductEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)