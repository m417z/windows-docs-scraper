# RmAddFilter function

## Description

Modifies the shutdown or restart actions that are applied to an application or service. The primary installer can call the **RmAddFilter** function multiple times. The most recent call overrides any previous modifications to the same file, process, or service.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing Restart Manager session.

### `strModuleName` [in, optional]

A pointer to a **null**-terminated string value that contains the full path to the application's executable file. Modifications to shutdown or restart actions are applied for the application that is referenced by the full path. This parameter must be **NULL** if the *Application* or *strServiceShortName* parameter is non-**NULL**.

### `pProcess` [in, optional]

A pointer to a [RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structure for the application. Modifications to shutdown or restart actions are applied for the application that is referenced by the **RM_UNIQUE_PROCESS** structure. This parameter must be **NULL** if the *strFilename* or *strShortServiceName* parameter is non-**NULL**.

### `strServiceShortName` [in, optional]

A pointer to a **null**-terminated string value that contains the short service name. Modifications to shutdown or restart actions are applied for the service that is referenced by short service filename. This parameter must be **NULL** if the *strFilename* or *Application* parameter is non-**NULL**.

### `FilterAction` [in]

An [RM_FILTER_ACTION](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_filter_action) enumeration value that specifies the type of modification to be applied.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The function completed successfully. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in as a parameter that requires a non-**null** and non-zero value. |
| **ERROR_SESSION_CREDENTIAL_CONFLICT**<br><br>1219 | This error is returned when a secondary installer calls this function. This function is only available to primary installers. |

## See also

[RmGetFilterList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetfilterlist)