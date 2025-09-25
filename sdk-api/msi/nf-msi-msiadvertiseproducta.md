# MsiAdvertiseProductA function

## Description

The
**MsiAdvertiseProduct** function generates an advertise script or advertises a product to the computer. The
**MsiAdvertiseProduct** function enables the installer to write to a script the registry and shortcut information used to assign or publish a product. The script can be written to be consistent with a specified platform by using
[MsiAdvertiseProductEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiadvertiseproductexa).

## Parameters

### `szPackagePath` [in]

The full path to the package of the product being advertised.

### `szScriptfilePath` [in]

The full path to script file that will be created with the advertise information. To advertise the product locally to the computer, set ADVERTISEFLAGS_MACHINEASSIGN or ADVERTISEFLAGS_USERASSIGN.

| Flag | Meaning |
| --- | --- |
| **ADVERTISEFLAGS_MACHINEASSIGN**<br><br>0 | Set to advertise a per-machine installation of the product available to all users. |
| **ADVERTISEFLAGS_USERASSIGN**<br><br>1 | Set to advertise a per-user installation of the product available to a particular user. |

### `szTransforms` [in]

A semicolon-delimited list of transforms to be applied. The list of transforms can be prefixed with the @ or | character to specify the secure caching of transforms. The @ prefix specifies secure-at-source transforms and the | prefix indicates secure full path transforms. For more information, see
[Secured Transforms](https://learn.microsoft.com/windows/desktop/Msi/secured-transforms). This parameter may be null.

### `lgidLanguage` [in]

The installation language to use if the source supports multiple languages.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | The function completed successfully. |
| **An error relating to an action** | See [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An initialization error occurred. |
| **ERROR_CALL_NOT_IMPLEMENTED** | This error is returned if an attempt is made to generate an advertise script on any platform other than Windows 2000 or Windows XP. Advertisement to the local computer is supported on all platforms. |

## See also

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

## Remarks

> [!NOTE]
> The msi.h header defines MsiAdvertiseProduct as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).