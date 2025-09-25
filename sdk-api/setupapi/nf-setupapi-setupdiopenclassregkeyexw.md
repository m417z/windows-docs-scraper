# SetupDiOpenClassRegKeyExW function

## Description

The **SetupDiOpenClassRegKeyEx** function opens the [device setup class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-setup-classes) registry key, the [device interface class](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-device-interface-classes) registry key, or a specific class's subkey. This function opens the specified key on the local computer or on a remote computer.

## Parameters

### `ClassGuid` [in, optional]

A pointer to the GUID of the class whose registry key is to be opened. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the root of the class tree (**HKLM\SYSTEM\CurrentControlSet\Control\Class**) is opened.

### `samDesired` [in]

The registry security access for the key to be opened. For information about registry security access values of type REGSAM, see the Microsoft Windows SDK documentation.

### `Flags` [in]

The type of registry key to be opened, which is specified by one of the following:

#### DIOCR_INSTALLER

Open a setup class key. If *ClassGuid* is **NULL**, open the root key of the class installer branch.

#### DIOCR_INTERFACE

Open an interface class key. If *ClassGuid* is **NULL**, open the root key of the interface class branch.

### `MachineName` [in, optional]

Optionally points to a string that contains the name of a remote computer on which to open the specified key.

> [!CAUTION]
> Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

### `Reserved`

Reserved. Must be **NULL**.

##### - Flags.DIOCR_INSTALLER

Open a setup class key. If *ClassGuid* is **NULL**, open the root key of the class installer branch.

##### - Flags.DIOCR_INTERFACE

Open an interface class key. If *ClassGuid* is **NULL**, open the root key of the interface class branch.

## Return value

**SetupDiOpenClassRegKeyEx** returns a handle to an opened registry key where information about this setup class can be stored/retrieved.

If the function fails, it returns INVALID_HANDLE_VALUE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Depending on the value that is passed in the *samDesired* parameter, it might be necessary for the caller of this function to be a member of the Administrators group.

**SetupDiOpenClassRegKeyEx** does not create a registry key if it does not already exist.

Callers of this function must close the handle returned from this function by calling [RegCloseKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regclosekey).

> [!NOTE]
> The setupapi.h header defines SetupDiOpenClassRegKeyEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupDiCreateDeviceInterfaceRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdicreatedeviceinterfaceregkeya)

[SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendevregkey)