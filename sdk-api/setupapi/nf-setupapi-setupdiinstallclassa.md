# SetupDiInstallClassA function

## Description

The **SetupDiInstallClass** function installs the **ClassInstall32** section of the specified INF file.

## Parameters

### `hwndParent` [in, optional]

The handle to the parent window for any user interface that is used to install this class. This parameter is optional and can be **NULL**.

### `InfFileName` [in]

A pointer to a NULL-terminated string that contains the name of the INF file that contains an [INF ClassInstall32 section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-classinstall32-section).

### `Flags` [in]

These flags control the installation process. Can be a combination of the following:

#### DI_NOVCP

Set this flag if *FileQueue* is supplied. DI_NOVCP instructs the **SetupInstallFromInfSection** function (described in Microsoft Windows SDK documentation) not to create a queue of its own and to use the caller-supplied queue instead. If this flag is set, files are not copied just queued.

#### DI_NOBROWSE

Set this flag to disable browsing if a copy operation cannot find a specified file. If the caller supplies a file queue, this flag is ignored.

#### DI_FORCECOPY

Set this flag to always copy files, even if they are already present on the user's computer. If the caller supplies a file queue, this flag is ignored.

#### DI_QUIETINSTALL

Set this flag to suppress the user interface unless absolutely necessary. For example, do not display the progress dialog. If the caller supplies a file queue, this flag is ignored.

### `FileQueue` [in, optional]

If the DI_NOVCP flag is set, this parameter supplies a handle to a file queue where file operations should be queued but not committed.

## Return value

The function returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

This function is called by a class installer when it installs a device of a new device class.

To install an interface class or a device class, use [SetupDiInstallClassEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstallclassexa).

> [!NOTE]
> The setupapi.h header defines SetupDiInstallClass as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiInstallClassEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstallclassexa)