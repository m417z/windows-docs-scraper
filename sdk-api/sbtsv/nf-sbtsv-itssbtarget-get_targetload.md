# ITsSbTarget::get_TargetLoad

## Description

Retrieves the relative load on a target. This value is based on the number of existing and pending sessions. By default a pending session has the same value as an existing session.

This property is read-only.

## Parameters

## Remarks

The weight of a pending session relative to an active session can be changed by setting the value of the *LB_ConnectionEstablishmentPenalty* parameter for the Connection Broker. This parameter is located under the **HKLM\System\CurrentControlSet\Services\Tssdis\Parameters** registry key. The default value of 1 specifies that pending sessions have the same weight as active sessions.

This property is available on Windows Server 2012 R2 with [KB3091411](https://support.microsoft.com/help/3091411/user-connection-fails-when-many-connections-are-made-to-windows-server) installed in the [ITsSbTargetEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbtargetex) interface.

## See also

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)

[ITsSbTargetEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbtargetex)