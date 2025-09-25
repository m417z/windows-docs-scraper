# RmRemoveFilter function

## Description

Removes any modifications to shutdown or restart actions that have been applied using the [RmAddFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmaddfilter) function. The primary installer can call the **RmRemoveFilter** function multiple times.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing Restart Manager session.

### `strModuleName` [in, optional]

A pointer to a **null**-terminated string value that contains the full path for the application's executable file. The **RmRemoveFilter** function removes any modifications to the referenced application's shutdown or restart actions previously applied by the [RmAddFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmaddfilter) function. This parameter must be **NULL** if the *Application* or *strServiceShortName* parameter is non-**NULL**.

### `pProcess` [in, optional]

The [RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structure for the application. The **RmRemoveFilter** function removes any modifications to the referenced application's shutdown or restart actions previously applied by the [RmAddFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmaddfilter) function. This parameter must be **NULL** if the *strFilename* or *strShortServiceName* parameter is non-**NULL**.

### `strServiceShortName` [in, optional]

A pointer to a **null**-terminated string value that contains the short service name. The **RmRemoveFilter** function removes any modifications to the referenced service's shutdown or restart actions previously applied by the [RmAddFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmaddfilter) function. This parameter must be **NULL** if the *strFilename* or *Application* parameter is non-**NULL**.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The function completed successfully. |
| **ERROR_FILE_NOT_FOUND**<br><br>1 | The specified filter could not be found. |
| **ERROR_SESSION_CREDENTIAL_CONFLICT**<br><br>1219 | This error is returned when a secondary installer calls this function. This function is only available to primary installers. |