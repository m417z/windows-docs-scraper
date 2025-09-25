# SNMPAPI_CALLBACK callback function

## Description

[SNMP is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Windows Remote Management](https://learn.microsoft.com/windows/desktop/WinRM/portal), which is the Microsoft implementation of WS-Man.]

The Microsoft WinSNMP implementation calls the
**SNMPAPI_CALLBACK** function to notify a WinSNMP session that an SNMP message or asynchronous event is available.

**SNMPAPI_CALLBACK** is a placeholder for an application- or library-defined callback function name.

## Parameters

### `hSession` [in]

Handle to the WinSNMP session.

### `hWnd` [in]

Handle to a window of the WinSNMP application to notify when an asynchronous request completes, or when trap notification occurs. This parameter does not have significance for the WinSNMP session, but the implementation always passes the value to the callback function.

### `wMsg` [in]

Specifies an unsigned integer that identifies the notification message to send to the WinSNMP application window. This parameter does not have significance for the WinSNMP session, but the implementation always passes the value to the callback function.

### `wParam` [in]

Specifies an application-defined 32-bit value that identifies the type of notification. If this parameter is equal to zero, an SNMP message is available for the session. The application should call the
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) function to retrieve the message. If this parameter is not equal to zero, it indicates an asynchronous event notification for the session. For additional information, see the following Remarks section.

### `lParam` [in]

Specifies an application-defined 32-bit value that specifies the request identifier of the PDU being processed.

### `lpClientData` [in]

If the *lpClientData* parameter was not **NULL** on the call to the
[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession) function for this session, this parameter is a pointer to application-defined data.

## Return value

The function must return SNMPAPI_SUCCESS to continue execution of the application. If the function returns any other value, the implementation responds as if the application called the
[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose) function for the indicated session.

## Remarks

When the implementation is executing the retransmission policy for the WinSNMP application and a transmission time-out occurs, the implementation informs the session of the error. In this situation the value of the *wParam* parameter would be SNMPAPI_TL_TIMEOUT. For a list of other transport layer errors, see the reference pages for the
[SnmpRegister](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpregister),
[SnmpSendMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpsendmsg), and
[SnmpRecvMsg](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmprecvmsg) functions.

## See also

[SnmpClose](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpclose)

[SnmpCreateSession](https://learn.microsoft.com/windows/desktop/api/winsnmp/nf-winsnmp-snmpcreatesession)

[WinSNMP
Functions](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-functions)

[WinSNMP API Overview](https://learn.microsoft.com/windows/desktop/SNMP/winsnmp-api)