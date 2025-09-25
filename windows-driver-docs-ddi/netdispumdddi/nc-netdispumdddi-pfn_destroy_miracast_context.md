# PFN_DESTROY_MIRACAST_CONTEXT callback function

## Description

Called by the operating system to destroy a user-mode Miracast context.

## Parameters

### `pMiracastContext` [in]

A pointer to a context associated with a display adapter.

The operating system obtained the context when it called the Miracast user-mode driver's [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

## Remarks

When this function is called, the Miracast user-mode driver should release all resources it allocated when [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) was last called.

If the display miniport driver is still reporting the Miracast monitor for this Miracast instance, the Miracast user-mode driver can optionally call the display miniport driver to immediately send a monitor departure hot-plug detection (HPD) awareness value, or it can let the display miniport driver do so in its kernel-mode [DxgkDdiMiracastDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_destroy_context) function.

**Important** The Miracast user-mode driver should complete this function call in 3 seconds so it does not block system plug and play (PnP) or power operations.

After this call completes, the operating system unloads the Miracast user-mode driver such that the driver leaves no resources still opened and no thread still running.

#### Thread Safety

The operating system guarantees that only one of the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context), *DestroyMiracastContext*, [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session), and [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) functions is called at a time.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session)

[StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session)