# DhcpDeRegisterParamChange function

## Description

The
**DhcpDeRegisterParamChange** function releases resources associated with previously registered event notifications, and closes the associated event handle.

## Parameters

### `Flags` [in]

Reserved. Must be set to zero.

### `Reserved` [in]

Reserved. Must be set to **NULL**.

### `Event` [in]

Must be the same value as the **HANDLE** variable in the
[DhcpRegisterParamChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpregisterparamchange) function call for which the client is deregistering event notification.

## Return value

Returns ERROR_SUCCESS upon successful completion. Otherwise, returns Windows error codes.

## Remarks

The
**DhcpDeRegisterParamChange** function must be made subsequent to an associated
[DhcpRegisterParamChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpregisterparamchange) function call, and the *Flags* parameter and the **HANDLE** variable passed
in the *Event* parameter to **DhcpDeRegisterParamChange** must match corresponding *Flags* parameter and the **HANDLE** variable of the previous and associated
**DhcpRegisterParamChange** function call.

## See also

[DHCP Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-functions)

[DhcpCApiInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpcapiinitialize)

[DhcpRegisterParamChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpcsdk/nf-dhcpcsdk-dhcpregisterparamchange)