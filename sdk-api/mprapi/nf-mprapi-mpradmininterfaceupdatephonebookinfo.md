# MprAdminInterfaceUpdatePhonebookInfo function

## Description

The
**MprAdminInterfaceUpdatePhonebookInfo** function forces the router to pick up changes made on a specified demand-dial interface. Call this function after changes are made to a phone-book entry for a demand-dial interface.

## Parameters

### `hMprServer` [in]

Handle to the router on which to execute this call. Obtain the handle by calling
[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect).

### `hInterface` [in]

Handle to a demand-dial interface. Obtain this handle by calling
[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling application does not have sufficient privileges. |
| **ERROR_CANNOT_LOAD_PHONEBOOK** | The function could not load the phone book into memory. |
| **ERROR_CANNOT_OPEN_PHONEBOOK** | The function could not find the phone-book file. |
| **ERROR_DDM_NOT_RUNNING** | The Demand Dial Manager (DDM) is not running. |
| **ERROR_INTERFACE_HAS_NO_DEVICES** | No device is currently associated with this interface. |
| **ERROR_INVALID_HANDLE** | The *hInterface* value is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient resources to complete the operation. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[MprAdminInterfaceCreate](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacecreate)

[MprAdminServerConnect](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminserverconnect)

[Router Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/router-administration-functions)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)