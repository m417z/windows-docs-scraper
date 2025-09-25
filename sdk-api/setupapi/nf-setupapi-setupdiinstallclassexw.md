# SetupDiInstallClassExW function

## Description

The **SetupDiInstallClassEx** function installs a class installer or an interface class.

## Parameters

### `hwndParent` [in, optional]

The handle to the parent window for any user interface that is used to install this class. This parameter is optional and can be **NULL**.

### `InfFileName` [in, optional]

A pointer to a NULL-terminated string that contains the name of an INF file. This parameter is optional and can be **NULL**. If this function is being used to install a class installer, the INF file contains an [INF ClassInstall32 section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-classinstall32-section) and this parameter must not be **NULL**.

If this function is being used to install an interface class, the INF file contains an [INF InterfaceInstall32 section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-interfaceinstall32-section).

### `Flags` [in]

A value of type DWORD that controls the installation process. *Flags* can be zero or a bitwise OR of the following values:

#### DI_NOVCP

Set this flag if *FileQueue* is supplied.

DI_NOVCP instructs the **SetupInstallFromInfSection** function not to create a queue of its own and to use the caller-supplied queue instead.

If this flag is set, files are not copied just queued.

For more information about the **SetupInstallFromInfSection** function, see the Microsoft Windows SDK documentation.

#### DI_NOBROWSE

Set this flag to disable browsing if a copy operation cannot find a specified file. If the caller supplies a file queue, this flag is ignored.

#### DI_FORCECOPY

Set this flag to always copy files, even if they are already present on the user's computer. If the caller supplies a file queue, this flag is ignored.

#### DI_QUIETINSTALL

Set this flag to suppress the user interface unless absolutely necessary. For example, do not display the progress dialog. If the caller supplies a file queue, this flag is ignored.

### `FileQueue` [in, optional]

If the DI_NOVCP flag is set, this parameter supplies a handle to a file queue where file operations should be queued but not committed.

### `InterfaceClassGuid` [in, optional]

A pointer to a GUID that identifies the interface class to be installed. This parameter is optional and can be **NULL**. If this parameter is specified, this function is being used to install the interface class represented by the GUID. If this parameter is **NULL**, this function is being used to install a class installer.

### `Reserved1`

Reserved. Must be zero.

### `Reserved2`

Reserved. Must be zero.

##### - Flags.DI_FORCECOPY

Set this flag to always copy files, even if they are already present on the user's computer. If the caller supplies a file queue, this flag is ignored.

##### - Flags.DI_NOBROWSE

Set this flag to disable browsing if a copy operation cannot find a specified file. If the caller supplies a file queue, this flag is ignored.

##### - Flags.DI_NOVCP

Set this flag if *FileQueue* is supplied.

DI_NOVCP instructs the **SetupInstallFromInfSection** function not to create a queue of its own and to use the caller-supplied queue instead.

If this flag is set, files are not copied just queued.

For more information about the **SetupInstallFromInfSection** function, see the Microsoft Windows SDK documentation.

##### - Flags.DI_QUIETINSTALL

Set this flag to suppress the user interface unless absolutely necessary. For example, do not display the progress dialog. If the caller supplies a file queue, this flag is ignored.

## Return value

**SetupDiInstallClassEx** returns **TRUE** if it is successful. Otherwise, it returns **FALSE** and the logged error can be retrieved with a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The caller of this function must be a member of the Administrators group.

**SetupDiInstallClassEx** is typically called by a class installer to install a new [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) or a new [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes).

**Note** An interface class can also be installed automatically by calling [SetupDiInstallDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstalldeviceinterfaces) to install the device interfaces for a device.

> [!NOTE]
> The setupapi.h header defines SetupDiInstallClassEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiCallClassInstaller](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicallclassinstaller)

[SetupDiInstallDeviceInterfaces](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiinstalldeviceinterfaces)