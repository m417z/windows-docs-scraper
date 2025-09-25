# SetupDiOpenClassRegKey function

## Description

The **SetupDiOpenClassRegKey** function opens the setup class registry key or a specific class's subkey.

## Parameters

### `ClassGuid` [in, optional]

A pointer to the GUID of the setup class whose key is to be opened. This parameter is optional and can be **NULL**. If this parameter is **NULL**, the root of the setup class tree (**HKLM\SYSTEM\CurrentControlSet\Control\Class**) is opened.

### `samDesired` [in]

The registry security access for the key to be opened. For information about registry security access values of type REGSAM, see the Microsoft Windows SDK documentation.

## Return value

If the function is successful, it returns a handle to an opened registry key where information about this setup class can be stored/retrieved.

If the function fails, it returns INVALID_HANDLE_VALUE. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Depending on the value that is passed in the *samDesired* parameter, it might be necessary for the caller of this function to be a member of the Administrators group.

This function does not create a registry key if it does not already exist.

The handle returned from this function must be closed by calling [RegCloseKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regclosekey).

To open the interface class registry key or a specific interface class subkey, call [SetupDiOpenClassRegKeyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopenclassregkeyexa).

## See also

[SetupDiOpenClassRegKeyEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopenclassregkeyexa)

[SetupDiOpenDevRegKey](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiopendevregkey)