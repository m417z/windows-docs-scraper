# DdeNameService function

## Description

Registers or unregisters the service names a Dynamic Data Exchange (DDE) server supports. This function causes the system to send [XTYP_REGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-register) or [XTYP_UNREGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-unregister) transactions to other running [Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library) (DDEML) client applications.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hsz1` [in, optional]

Type: **HSZ**

A handle to the string that specifies the service name the server is registering or unregistering. An application that is unregistering all of its service names should set this parameter to 0L.

### `hsz2` [in, optional]

Type: **HSZ**

Reserved; should be set to 0L.

### `afCmd` [in]

Type: **UINT**

The service name options. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DNS_REGISTER**<br><br>0x0001 | Registers the error code service name. |
| **DNS_UNREGISTER**<br><br>0x0002 | Unregisters the error code service name. If the *hsz1* parameter is 0L, all service names registered by the server will be unregistered. |
| **DNS_FILTERON**<br><br>0x0004 | Turns on service name initiation filtering. The filter prevents a server from receiving [XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect) transactions for service names it has not registered. This is the default setting for this filter. <br><br>If a server application does not register any service names, the application cannot receive [XTYP_WILDCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-wildconnect) transactions. |
| **DNS_FILTEROFF**<br><br>0x0008 | Turns off service name initiation filtering. If this flag is specified, the server receives an [XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect) transaction whenever another DDE application calls the [DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect) function, regardless of the service name. |

## Return value

Type: **HDDEDATA**

If the function succeeds, it returns a nonzero value. That value is not a true **HDDEDATA** value, merely a Boolean indicator of success. The function is typed **HDDEDATA** to allow for possible future expansion of the function and a more sophisticated return value.

If the function fails, the return value is 0L.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

The service name identified by the
*hsz1* parameter should be a base name (that is, the name should contain no instance-specific information). The system generates an instance-specific name and sends it along with the base name during the
[XTYP_REGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-register) and
[XTYP_UNREGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-unregister) transactions. The receiving applications can then connect to the specific application instance.

## See also

**Conceptual**

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**

[XTYP_REGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-register)

[XTYP_UNREGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-unregister)