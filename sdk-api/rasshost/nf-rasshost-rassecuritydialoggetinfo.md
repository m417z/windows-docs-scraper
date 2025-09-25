# RasSecurityDialogGetInfo function

## Description

The
**RasSecurityDialogGetInfo** function is called by a RAS security DLL to get information about a port from the RAS server.

To call this function, first call the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to load Rasman.dll. Then call the
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to get the DLL's
**RasSecurityDialogGetInfo** entry point.

**Note** Windows Server 2008,
Windows Server 2003,
Windows 2000 Server, and
Windows NT Server 4.0 currently provide RAS security host support for serial devices only. Other types of connections, such as Integrated Services Digital Network (ISDN) or virtual private network (VPN) connections, are not supported.

## Parameters

### `hPort` [in]

Specifies the port handle that the RAS server passed to the security DLL in the
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin) call for this authentication transaction.

### `pBuffer` [in]

Pointer to the
[RAS_SECURITY_INFO](https://learn.microsoft.com/windows/desktop/api/rasshost/ns-rasshost-ras_security_info) structure that receives information about the specified RAS port.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value is one of the error codes defined in Raserror.h or Winerror.h.
[GetLastError](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-iabcontainer-getlasterror) does not provide extended error information.

## Remarks

The
**RasSecurityDialogGetInfo** function retrieves information about the port associated with a RAS security DLL authentication transaction.

The **LastError** member of the
[RAS_SECURITY_INFO](https://learn.microsoft.com/windows/desktop/api/rasshost/ns-rasshost-ras_security_info) structure indicates the state of the last
[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive) call for the port. If the receive operation has been completed successfully, **LastError** is SUCCESS and the **BytesReceived** member indicates the number of bytes received. Otherwise, **LastError** is PENDING if the receive operation is still in progress, or a nonzero error code if the receive operation failed.

## See also

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[RAS Server Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-functions)

[RAS_SECURITY_INFO](https://learn.microsoft.com/windows/desktop/api/rasshost/ns-rasshost-ras_security_info)

[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)