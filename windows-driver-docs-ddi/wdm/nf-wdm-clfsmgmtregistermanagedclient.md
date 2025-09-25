# ClfsMgmtRegisterManagedClient function

## Description

The **ClfsMgmtRegisterManagedClient** routine creates a client that will manage a CLFS log.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log stream that the client created by **ClfsMgmtRegisterManagedClient** will manage.

### `RegistrationData` [in]

An instance of the [CLFS_MGMT_CLIENT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_client_registration) structure that contains the functions that will be used to manage the log.

### `ClientCookie`

The cookie we give back to the caller for future use of the API.

## Return value

The **ClfsMgmtRegisterManagedClient** routine returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | A client has been created to manage the log. |
| **STATUS_UNSUCCESSFUL** | CLFS management was not able to create a client to manage the log. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory to complete the operation. |
| **STATUS_INVALID_PARAMETER** | An input parameter is invalid. |

This routine might also return other [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The *Client* parameter that is provided by the **ClfsMgmtRegisterManagedClient** routine is a required parameter for other CLFS management functions. You should store this value for later use.

A client application must be ready for its callback routine to be called as soon as it calls the **ClfsMgmtRegisterManagedClient** routine.

More than one client can register with a log stream.

## See also

[CLFS_MGMT_CLIENT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_client_registration)

[LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)