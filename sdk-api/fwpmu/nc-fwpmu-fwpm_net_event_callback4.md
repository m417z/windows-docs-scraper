## Description

**FWPM_NET_EVENT_CALLBACK4** is the function signature of a callback function that you implement, and the system calls. The purpose is to add custom behavior to the net event subscription process.

## Parameters

### `context`

Optional context pointer. It contains the value of the *context* parameter of the [FwpmNetEventSubscribe4](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe4) function.

### `event`

An [FWPM_NET_EVENT5](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event5) structure that contains the event information.

## Remarks

To register your callback function, call [FwpmNetEventSubscribe4](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe4).

## See also