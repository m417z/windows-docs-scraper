## Description

**FWPM_NET_EVENT_CALLBACK3** is the function signature of a callback function that you implement, and the system calls. The purpose is to add custom behavior to the net event subscription process.

## Parameters

### `context`

Optional context pointer. It contains the value of the *context* parameter of the [FwpmNetEventSubscribe3](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe3) function.

### `event`

An [FWPM_NET_EVENT4](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event4) structure that contains the event information.

## Remarks

To register your callback function, call [FwpmNetEventSubscribe3](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmneteventsubscribe3).

## See also