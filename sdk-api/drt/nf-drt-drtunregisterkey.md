## Description

The **DrtUnregisterKey** function deregisters a key from the DRT.

## Parameters

### `hKeyRegistration` [in]

The DRT handle returned by the [DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey) function specifying a registered key within the DRT.

## Remarks

A node can deregister a key anytime after registration. Additionally, if an application calls [DrtClose](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtclose), all keys are deregistered by the DRT infrastructure.

Only the application that registered they key may deregister it. An application can deregister a key from the local node. Upon completion the function triggers a **DRT_EVENT_LEAFSET_KEY_CHANGE** event; informing the application and other nodes participating in the DRT mesh of the deregistration.

## See also

[DrtClose](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtclose)

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)

[DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey)