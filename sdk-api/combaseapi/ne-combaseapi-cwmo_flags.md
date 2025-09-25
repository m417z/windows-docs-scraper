## Description

Provides flags for the [CoWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultipleobjects) function.

## Constants

### `CWMO_DEFAULT:0`

No call dispatch.

### `CWMO_DISPATCH_CALLS:1`

Dispatch calls from [CoWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultipleobjects) (default is no call dispatch).

### `CWMO_DISPATCH_WINDOW_MESSAGES:2`

Enable dispatch of window messages from [CoWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultipleobjects) in a ASTA or STA (default in ASTA is no window messages dispatched, default in STA is only a small set of special-cased messages dispatched). The value has no meaning in MTA and is ignored.