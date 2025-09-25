# lineSetCallQualityOfService function

## Description

The
**lineSetCallQualityOfService** function allows the application to attempt to change the quality of service parameters (reserved capacity and performance guarantees) for an existing call. Except for basic parameter validation, this is a straight pass-through to a service provider.

## Parameters

### `hCall`

Handle to the call. The application must have OWNER privilege.

### `lpSendingFlowspec`

Pointer to memory containing a
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by provider-specific data. The provider-specific portion following the **FLOWSPEC** structure must not contain pointers to other blocks of memory in the application process, because TAPI will not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the service provider.

### `dwSendingFlowspecSize`

Total size of the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure and accompanying provider-specific data, in bytes. This is equivalent to what would have been stored in **SendingFlowspec** in a
[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure.

### `lpReceivingFlowspec`

Pointer to memory containing a [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure followed by provider-specific data. The provider-specific portion following the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure must not contain pointers to other blocks of memory in the application process, because TAPI will not know how to marshal the data pointed to by the private pointer(s) and convey it through interprocess communication to the service provider.

### `dwReceivingFlowspecSize`

Total size of the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) and accompanying provider-specific data, in bytes. This is equivalent to what would have been stored in **ReceivingFlowspec** in a [QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos) structure.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALCALLHANDLE, LINEERR_INVALCALLSTATE, LINEERR_INVALPARAM, LINEERR_INVALPOINTER, LINEERR_INVALRATE, LINEERR_NOMEM, LINEERR_NOTOWNER, LINEERR_OPERATIONUNAVAIL, LINEERR_OPERATIONFAILED, LINEERR_RATEUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[QOS](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-qos)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)