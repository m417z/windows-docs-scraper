# ClfsMgmtDeregisterManagedClient function

## Description

The **ClfsMgmtDeregisterManagedClient** routine removes the connection between a client and a log, so that the client no longer manages the log.

## Parameters

### `ClientCookie`

The cookie we give back to the caller for future use of the API.

## Return value

The **ClfsMgmtDeregisterManagedClient** routine returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The client is no longer associated with the log. |
| **STATUS_UNSUCCESSFUL** | CLFS management was not able to deregister the client. |
| **STATUS_INVALID_PARAMETER** | A **NULL** value was supplied for the *Client* parameter. |
| **STATUS_INVALID_PARAMETER_1** | The value that was supplied for the *Client* parameter does not represent a valid client. |

## Remarks

After calling the **ClfsMgmtDeregisterManagedClient** routine, a client's callback functions will no longer be invoked.

## See also

[ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient)