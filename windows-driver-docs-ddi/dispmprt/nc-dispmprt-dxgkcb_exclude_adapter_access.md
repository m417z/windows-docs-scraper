# DXGKCB_EXCLUDE_ADAPTER_ACCESS callback function

## Description

The **DxgkCbExcludeAdapterAccess** function prevents all access to the display adapter and calls a provided [DxgkProtectedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_protected_callback) callback routine while in this protected state.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `Attributes` [in]

A value that specifies video memory operations. This parameter can be any combination of the following bit flag values, except that DXGK_EXCLUDE_EVICT_ALL and DXGK_EXCLUDE_CALL_SYNCHRONOUS are mutually exclusive. These values are defined in *Dispmprt.h*.

#### DXGK_EXCLUDE_EVICT_ALL

All video memory in the adapter is copied to system memory; this is an expensive operation. If the *Attributes* parameter is not set to this value, access to locked surfaces in system memory is suspended.

#### DXGK_EXCLUDE_CALL_SYNCHRONOUS

Executes the protected [DxgkProtectedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_protected_callback) driver callback routine in the same thread context as the caller. The caller must be calling from a [second level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level) or [third level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-third-level) synchronized DDI call. Otherwise the **DxgkCbExcludeAdapterAccess** function will fail.

#### DXGK_EXCLUDE_BRIDGE_ACCESS

Protects access to the PCI Express (PCIe) root port when the driver needs to access the root port configuration space. Set the *Attributes* parameter to this value before calling [DxgkCbReadDeviceSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_read_device_space) or [DxgkCbWriteDeviceSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_write_device_space) functions with the *DataType* parameter set to DXGK_WHICHSPACE_BRIDGE.

### `DxgkProtectedCallback` [in]

The callback routine to be called back when all access to the adapter has been halted.

### `ProtectedCallbackContext` [in]

A pointer to the value to pass to the *ProtectedCallbackContext* parameter of the [DxgkProtectedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_protected_callback) callback routine.

## Return value

**DxgkCbExcludeAdapterAccess** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

Application requests will be blocked until this function returns. While in this protective state, the provided [DxgkProtectedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_protected_callback) callback routine is called at IRQL = PASSIVE_LEVEL.

**DxgkCbExcludeAdapterAccess** acquires exclusive adapter access in order to prevent graphics-related I/O operations to the display adapter and all links. This effectively idles the GPU for the entire duration of the call.

This function also prevents all PCI configuration space access to the PCI Express (PCIe) root port if DXGK_EXCLUDE_BRIDGE_ACCESS is specified in the *Attributes* parameter.

The driver should not block continued execution of the calling thread by waiting for the [DxgkProtectedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_protected_callback) callback routine to return. For example, the driver could schedule an asynchronous worker thread to handle the callback routine.

An exception to this blocking of application requests occurs when the user-mode display driver has set the **UseAlternateVA** bit-field flag in the **Flags** member of the [D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags) structure in a call to the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function. **DxgkCbExcludeAdapterAccess** does not block this type of allocation lock, and the CPU can access the display adapter while the protected callback routine is executing.

**Note** If **UseAlternateVA** has been set in a call to **pfnLockCb**, the display miniport driver should not call **DxgkCbExcludeAdapterAccess**.

## See also

[DxgkProtectedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_protected_callback)