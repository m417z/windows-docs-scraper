# SetProviderStatusInfo structure

## Description

A structure that is used by the
[SetProviderStatusFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-setproviderstatusfunc) function.

## Members

### `tpsCurrentState`

The new state of the provider. This member can be one of the following values:

#### TPC_Error

#### TPS_Running

### `dwStratum`

The new stratum of the provider. Computers using a hardware clock (such as cesium, GPS, or radio) to keep time are stratum 1. Computers that synchronize their time with another computer over the network are stratum N+1, where N is the stratum of the computer with which they are synchronizing.

### `wszProvName`

The name of the provider.

### `hWaitEvent`

A handle to an event to set to the signaled state when the operation has been completed. To create an event object, use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function.

If notification is not needed, this member can be **NULL**.

### `pfnFree`

A pointer to a
[SetProviderStatusInfoFreeFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-setproviderstatusinfofreefunc) function which frees the structure on completion.

### `pHr`

On completion, this member contains the result of the operation. If the operation succeeds, the result is S_OK. Otherwise, the result is one of the error codes defined in WinError.h.

### `pdwSysStratum`

On completion, this member contains the new system stratum. The system stratum is the lowest stratum of all time providers on the system. If the time provider with the lowest stratum increments its stratum, this increments the system stratum.

## See also

[SetProviderStatusFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-setproviderstatusfunc)

[SetProviderStatusInfoFreeFunc](https://learn.microsoft.com/windows/desktop/api/timeprov/nc-timeprov-setproviderstatusinfofreefunc)