# PAC_CHANGES_CALLBACK_FN callback function

## Description

The **PAC_CHANGES_CALLBACK_FN** function is used to add custom behavior to the app container change notification process.

## Parameters

### `context` [in, optional]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [NetworkIsolationRegisterForAppContainerChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-networkisolationregisterforappcontainerchanges) function.

### `pChange` [in]

Type: **const [INET_FIREWALL_AC_CHANGE](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_ac_change)***

The app container change information.

## Remarks

Call [NetworkIsolationRegisterForAppContainerChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-networkisolationregisterforappcontainerchanges) to register this callback function.

## See also

[INET_FIREWALL_AC_CHANGE](https://learn.microsoft.com/windows/desktop/api/netfw/ns-netfw-inet_firewall_ac_change)

[NetworkIsolationRegisterForAppContainerChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-networkisolationregisterforappcontainerchanges)