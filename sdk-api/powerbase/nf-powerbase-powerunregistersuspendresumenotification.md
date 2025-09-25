# PowerUnregisterSuspendResumeNotification function

## Description

Cancels a registration to receive notification when the system is suspended or resumed.

## Parameters

### `RegistrationHandle` [in, out]

A handle to a registration obtained by calling the [PowerRegisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerregistersuspendresumenotification) function.

## Return value

Returns ERROR_SUCCESS (zero) if the call was successful, and a nonzero value if the call failed.

## See also

[PowerRegisterSuspendResumeNotification](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-powerregistersuspendresumenotification)