# DXGKCB_NOTIFY_DPC callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_NOTIFY_DPC** to inform the graphics processing unit (GPU) scheduler about a graphics hardware update at deferred procedure call (DPC) time.

## Parameters

### `hAdapter` [in]

A handle to the adapter object for the GPU. The driver receives the handle from the **DeviceHandle** member of the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure in a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

## Remarks

The display miniport driver's DPC callback routine calls **DXGKCB_NOTIFY_DPC** to inform the GPU scheduler about an update to a fence through a direct memory access (DMA) stream to the graphics hardware.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbNotifyDpc** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

### Examples

The following code example shows how to notify the GPU scheduler about the DMA or V-Sync interrupt.

```cpp
NTSTATUS
D3DDDINotifyDPC(
    HW_DEVICE_EXTENSION  *pAdapter)
{
    DXGKRNL_INTERFACE  *pCallback;
    DXGKCB_NOTIFY_DPC  DxgkCbNotifyDpc;

    pCallback = &(pAdapter->ddiCallback);

    if (! pAdapter->pVidSchDPCCB) {
        return (STATUS_SUCCESS);
    }

    DxgkCbNotifyDpc = (DXGKCB_NOTIFY_DPC)pAdapter->pVidSchDPCCB;

    DxgkCbNotifyDpc(pAdapter->DeviceHandle);

    return (STATUS_SUCCESS);
}
```

## See also

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)

[**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[**DxgkCbQueueDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_queue_dpc)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)