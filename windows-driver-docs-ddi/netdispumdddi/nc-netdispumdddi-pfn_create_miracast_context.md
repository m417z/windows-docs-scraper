# PFN_CREATE_MIRACAST_CONTEXT callback function

## Description

Called by the operating system to create a user-mode Miracast context.

## Parameters

### `hMiracastDeviceHandle` [in]

A handle to the current Miracast display device, supplied by the operating system.

### `pMiracastCallbacks` [in]

A pointer to a [MIRACAST_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-_miracast_callbacks) structure that has pointers to callback functions, supplied by the operating system, that the Miracast user-mode driver can call.

### `ppMiracastContext` [out]

A pointer to a buffer, supplied by the operating system, that holds the Miracast context that the Miracast user-mode driver returns.

## Return value

On success, this function returns **STATUS_SUCCESS**. Otherwise, the function returns an error code defined in the Ntstatus.h header.

## Remarks

When this function is called, the Miracast user-mode driver should prepare all resources that it needs for a new Miracast connected session.

The driver can call the callback functions pointed to by *pMiracastCallbacks* only during the lifetime of the current Miracast context.

#### Thread Safety

The operating system guarantees that only one of the *CreateMiracastContext*, [DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context), [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session), and [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) functions is called at a time.

## See also

[DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context)

[MIRACAST_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-_miracast_callbacks)

[StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session)

[StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session)