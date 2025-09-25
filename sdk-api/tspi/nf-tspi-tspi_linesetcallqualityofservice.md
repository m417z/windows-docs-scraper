# TSPI_lineSetCallQualityOfService function

## Description

The
**TSPI_lineSetCallQualityOfService** function service provider attempts to renegotiate the QOS on the call with the switch If the desired QOS is not available, then the function fails, but the call continues with the previous QOS. If the function succeeds, the new QOS information is stored in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo); a LINECALLINFOSTATE_QOS message is sent by the service provider to indicate the updated values.

## Parameters

### `dwRequestID`

Identifier for reporting asynchronous function results.

### `hdCall`

The service provider's handle to the call.

### `lpSendingFlowspec`

Pointer to memory containing a WinSock2 [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by provider-specific data. The provider-specific portion following the **FLOWSPEC** structure must not contain pointers to other blocks of memory in the application process, because TAPI does not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the service provider.

### `dwSendingFlowspecSize`

The total size in bytes of the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) and accompanying provider-specific data, equivalent to what would have been stored in SendingFlowspec.len in a WinSock2 [QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure.

### `lpReceivingFlowspec`

Pointer to memory containing a WinSock2 [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by provider-specific data. The provider-specific portion following the **FLOWSPEC** structure must not contain pointers to other blocks of memory in the application process, because TAPI does not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the service provider.

### `dwReceivingFlowspecSize`

The total size in bytes of the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) and accompanying provider-specific data, equivalent to what would have been stored in ReceivingFlowspec.len in a WinSock2 [QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure.

## Return value

Returns **dwRequestID** if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALCALLSTATE, LINEERR_INVALRATE, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_RATEUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)