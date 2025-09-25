# RmRegisterResources function

## Description

Registers resources to a Restart Manager session. The Restart Manager uses the list of resources registered with the session to determine which applications and services must be shut down and restarted. Resources can be identified by filenames, service short names, or [RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structures that describe running applications. The **RmRegisterResources** function can be used by a primary or secondary installer.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing Restart Manager session.

### `nFiles` [in]

The number of files being registered.

### `rgsFileNames` [in, optional]

An array of **null**-terminated strings of full filename paths. This parameter can be **NULL** if *nFiles* is 0.

### `nApplications` [in]

The number of processes being registered.

### `rgApplications` [in, optional]

An array of [RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structures. This parameter can be **NULL** if *nApplications* is 0.

### `nServices` [in]

The number of services to be registered.

### `rgsServiceNames` [in, optional]

An array of **null**-terminated strings of service short names. This parameter can be **NULL** if *nServices* is 0.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The resources specified have been registered. |
| **ERROR_SEM_TIMEOUT**<br><br>121 | A Restart Manager function could not obtain a Registry write mutex in the allotted time. A system restart is recommended because further use of the Restart Manager is likely to fail. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by Restart Manager function if a **NULL** pointer or 0 is passed in a parameter that requires a non-**null** and non-zero value. |
| **ERROR_WRITE_FAULT**<br><br>29 | An operation was unable to read or write to the registry. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not complete because not enough memory was available. |
| **ERROR_INVALID_HANDLE**<br><br>6 | No Restart Manager session exists for the handle supplied. |

## Remarks

Each call to the **RmRegisterResources** function performs relatively expensive write operations. Do not call this function once per file, instead group related files together into components and register these together.