# DXGKDDI_PROTECTED_CALLBACK callback function

## Description

The *DxgkProtectedCallback* callback routine is implemented by the display miniport driver and is called by [DxgkCbExcludeAdapterAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_exclude_adapter_access) during a protected state when all access to the display adapter is prevented.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `ProtectedCallbackContext` [in]

A pointer to driver-defined information that was specified in a previous call to [DxgkCbExcludeAdapterAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_exclude_adapter_access).

### `ProtectionStatus` [in]

Status of the display adapter's protected state. If STATUS_SUCCESS, the adapter was successfully protected from access. A failure status code indicates that the adapter is not protected.

## Prototype

```cpp
DXGKDDI_PROTECTED_CALLBACK DxgkProtectedCallback;

VOID DxgkProtectedCallback(
  _In_ const PVOID    MiniportDeviceContext,
  _In_       PVOID    ProtectedCallbackContext,
  _In_       NTSTATUS ProtectionStatus
)
{ ... }
```

## Remarks

*DxgkProtectedCallback* must be called only when all access to the display adapter has been halted, as indicated by the status parameter *ProtectionStatus.*

The driver must ensure that following conditions are met during the callback routine:

* All interrupts on the device are disabled, and any remaining pending interrupts are handled, including any DPCs that may have been queued on any CPU but not yet serviced.
* All write-combined memory and any other cache-related states have been flushed.
* Any ACPI or BIOS/SMI events that occur do not access the hardware.
* Coherency is achieved between all adapters in a linked-adapter state configuration.
* The adapter, including its registers and display mode, is maintained in the proper state to handle the DMA buffer that occurs on the return from the *DxgkProtectedCallback* routine. The driver should not change the visible state or capabilities of any application.

## See also

[DxgkCbExcludeAdapterAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_exclude_adapter_access)