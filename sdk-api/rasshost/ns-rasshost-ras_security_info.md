# RAS_SECURITY_INFO structure

## Description

The
**RAS_SECURITY_INFO** structure is used with the
[RasSecurityDialogGetInfo](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialoggetinfo) function to return information about the RAS port associated with a RAS security DLL authentication transaction.

## Members

### `LastError`

Specifies an error code that indicates the state of the last
[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive) call for the port. If the receive operation failed, **LastError** is one of the error codes defined in Raserror.h or Winerror.h. Otherwise, **LastError** is one of the following values.

| Value | Meaning |
| --- | --- |
| **SUCCESS** | The receive operation has been successfully completed. The **BytesReceived** member indicates the number of bytes received. |
| **PENDING** | The receive operation is pending completion. |

### `BytesReceived`

Specifies the number of bytes received in the most recent
[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive) operation. This member is valid only if the value of the **LastError** member is SUCCESS.

### `DeviceName`

Specifies a null-terminated string that contains the user-friendly display name of the device on the port, such as Hayes SmartModem 9600.

## See also

[RAS Server Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-structures)

[RasSecurityDialogGetInfo](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialoggetinfo)

[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)