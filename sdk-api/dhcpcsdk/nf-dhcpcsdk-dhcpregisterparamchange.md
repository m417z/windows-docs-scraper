# DhcpRegisterParamChange function

## Description

The
**DhcpRegisterParamChange** function enables clients to register for notification of changes in DHCP configuration parameters.

## Parameters

### `Flags` [in]

Reserved. Must be set to DHCPCAPI_REGISTER_HANDLE_EVENT. If it is not set to this flag value, the API call will not be successful.

### `Reserved` [in]

Reserved. Must be set to **NULL**.

### `AdapterName` [in]

GUID of the adapter for which event notification is being requested. Must be under 256 characters.

### `ClassId` [in]

Reserved. Must be set to **NULL**.

### `Params` [in]

Parameters for which the client is interested in registering for notification, in the form of a [DHCPCAPI_PARAMS_ARRAY](https://learn.microsoft.com/windows/win32/api/dhcpcsdk/ns-dhcpcsdk-dhcpcapi_params_array) structure.

### `Handle` [in, out]

Attributes of *Handle* are determined by the value of *Flags*. In version 2 of the DHCP API, *Flags* must be set to DHCPCAPI_REGISTER_HANDLE_EVENT, and therefore, *Handle* must be a pointer to a **HANDLE** variable that will hold the handle to a Windows event that gets signaled when parameters specified in *Params* change. Note that this **HANDLE** variable is used in a subsequent call to the
**DhcpDeRegisterParamChange** function to deregister event notifications associated with this particular call to the
**DhcpRegisterParamChange** function.

## Return value

Returns ERROR_SUCCESS upon successful completion. Otherwise, returns Windows error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | Returned if the AdapterName parameter is over 256 characters long. |

## Remarks

Version 2 of the DHCP Client API provides only event-based notification. With event-based notification in DHCP, clients enable notification by having *Handle* point to a variable that, upon successful return, holds the EVENT handles that are signaled whenever changes occur to the parameters requested in *Params*.

## See also

[DHCP Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-functions)

[DHCPCAPI_PARAMS_ARRAY](https://learn.microsoft.com/windows/win32/api/dhcpcsdk/ns-dhcpcsdk-dhcpcapi_params_array)

[DhcpCApiInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpcapiinitialize)

[DhcpDeRegisterParamChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpderegisterparamchange)