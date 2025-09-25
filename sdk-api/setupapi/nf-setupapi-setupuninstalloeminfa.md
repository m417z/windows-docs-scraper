# SetupUninstallOEMInfA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupUninstallOEMInf** function uninstalls a specified .inf file and any associated .pnf file. If the .inf file was installed with a catalog for signing drivers, the catalog is also removed. A caller of this function must have administrative privileges, otherwise the function fails.

## Parameters

### `InfFileName` [in]

File name, without path, of the .inf file in the Windows Inf directory that is to be uninstalled.

### `Flags` [in]

This parameter can be set as follows.

| Flag | Meaning |
| --- | --- |
| **SUOI_FORCEDELETE**<br><br>0x0001 | The **SetupUninstallOEMInf** function first checks whether there are any devices installed using the .inf file. A device does not need to be present to be detected as using the .inf file.<br><br>If this flag is not set and the function finds a currently installed device that was installed using this .inf file, the .inf file is not removed.<br><br>If this flag is set, the .inf file is removed whether the function finds a device that was installed with this .inf file.<br><br>**Note** This flag only applies to x86, amd64, and ia64 architectures. It is ignored on all other architectures.<br><br>**Note** If the driver package has any files that are copied to a [DestinationDir](https://learn.microsoft.com/windows-hardware/drivers/install/inf-destinationdirs-section) that uses a [DirId](https://learn.microsoft.com/windows-hardware/drivers/install/using-dirids) of 13, then this force flag is ignored.<br><br>**Note** It is recommended to use [DiUninstallDriver](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-diuninstalldrivera) to remove a driver package instead of using this flag. |

### `Reserved` [in]

Set to **null**.

## Return value

This function returns WINSETUPAPI BOOL.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCopyOEMInf](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcopyoeminfa)

[DiUninstallDriver](https://learn.microsoft.com/windows/win32/api/newdev/nf-newdev-diuninstalldrivera)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupUninstallOEMInf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).