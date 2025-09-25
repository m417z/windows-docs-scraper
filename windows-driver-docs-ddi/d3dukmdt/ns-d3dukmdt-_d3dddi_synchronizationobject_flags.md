# D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS structure

## Description

The **D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS** structure identifies attributes of a synchronization object.

## Members

### `Shared`

A UINT value that specifies whether the synchronization object is shared.

If **Shared** is set to 1 (TRUE), the synchronization object is shared. If **Shared** is set to zero (FALSE), the synchronization object is not shared. For more information, see the Remarks section.

### `NtSecuritySharing`

A UINT value that specifies whether the synchronization object is shared with an NT handle, meaning that it does not have a global **D3DKMT_HANDLE** kernel-mode handle to the resource.

If **NtSecuritySharing** is set to 1 (TRUE), the synchronization object is shared but does not have a global **D3DKMT_HANDLE** handle to the resource.

> [!NOTE]
> If **NtSecuritySharing** is set to 1, **Shared** must be set to 1. For more information, see the Remarks section.

Supported starting with Windows 8.

### `CrossAdapter`

A UINT value that specifies whether the synchronization object is a shared [cross-adapter resource object on a hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system).

If **CrossAdapter** is set to 1 (TRUE), the synchronization object is a shared cross-adapter object. If **CrossAdapter** is set to zero (FALSE), the synchronization object is not a shared cross-adapter object.

### `TopOfPipeline`

|Value|Meaning|
|--- |--- |
|TRUE|Specifies whether the synchronization object is signaled as soon as the contents of command buffer preceding it is entirely copied to the GPU pipeline, but not necessarily completed execution. This behavior allows reusing command buffers as soon as possible.|
|FALSE|The synchronization object is signaled after the preceding command buffers completed execution.|

This value can only be set to 1 (TRUE) for monitored fence synchronization objects, and it should be set to zero (FALSE) for all other synchronization object types.

Supported starting with Windows 10.

### `NoSignal`

|Value|Meaning|
|--- |--- |
|TRUE|Specifies the device this sync object is created or opened on can only submit wait commands for it. An attempt to submit a signal operation when this flag is set will return STATUS_ACCESS_DENIED.|
|FALSE|The synchronization object can be signaled.|

This value can only be set to 1 (TRUE) for monitored fence synchronization objects, and it should be set to zero (FALSE) for all other synchronization object types.

Supported starting with Windows 10.

### `NoWait`

|Value|Meaning|
|--- |--- |
|TRUE|Specifies the device this sync object is created or opened on can only submit signal commands for it. An attempt to submit a wait operation when this flag is set will return STATUS_ACCESS_DENIED.|
|FALSE|The synchronization object can be waited on.|

This value can only be set to 1 (TRUE) for monitored fence synchronization objects, and it should be set to zero (FALSE) for all other synchronization object types.

This flag cannot be set simultaneously with **NoSignal** flag.

Supported starting with Windows 10.

### `NoSignalMaxValueOnTdr`

|Value|Meaning|
|--- |--- |
|TRUE|Instructs the GPU scheduler to bypass the aforementioned signaling of the monitored fence to the maximum value in TDR cases.|
|FALSE|The GPU scheduler will signal the monitored fence to the maximum value when a device that can potentially signal it is affected by the GPU reset (TDR).|

Supported starting with Windows 10.

### `NoGPUAccess`

When set, the fence will not be mapped into the GPU virtual address space and will always stored as a 64-bit value (regardless of adapter caps). Only packet-based signal/wait operations are supported. Supported starting with Windows 10.

### `SignalByKmd`

When set, the fence can be signaled by the kernel-mode driver (KMD). This flag can only be used with [**D3DDDI_CPU_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_synchronizationobject_type) objects. Supported starting with Windows 11 (WDDM 3.0).

### `Unused`

This member is unused and should be set to zero. Available starting with Windows 11, version 22H2 (WDDM 3.1).

### `UnwaitCpuWaitersOnlyOnDestroy`

When set, the waiters for a shared synchronization object on the CPU will be unblocked only when the shared sync object is finally destroyed. By default, CPU waiters are unblocked when a local sync object is destroyed, but the main shared sync object is still opened by another local sync object. Supported starting with Windows 11, version 24H2 (WDDM 3.2).

### `Reserved`

This member is reserved and should be set to zero.

### `D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS_RESERVED0`

This member is reserved and should be set to zero.

Supported starting with Windows 8.

### `Value`

A member in the union that is contained in **D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS** that can hold one 32-bit value that identifies attributes of a synchronization object.

## Remarks

Objects to be shared by using the [**D3DKMTShareObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects) function must first be created with the **NtSecuritySharing** flag value set. This flag value is available in the [**D3DKMT_CREATEALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocationflags), [**D3DKMT_CREATEKEYEDMUTEX2_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2_flags), and **D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS** structures.

Drivers should follow these guidelines on **D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS** flags:

* If the synchronization object is not shared, set both **Shared** and **NtSecuritySharing** to 0.

* If the synchronization object is shared with a **D3DKMT_HANDLE** data type, set **Shared** = 1 and **NtSecuritySharing** = 0.

* If the synchronization object is shared with an NT handle to the process (and without a global **D3DKMT_HANDLE** kernel-mode handle to the resource), set **Shared** = 1 and **NtSecuritySharing** = 1.

## See also

[**D3DDDI_SYNCHRONIZATIONOBJECTINFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobjectinfo2)

[**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags)

[**D3DKMTShareObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects)

[**D3DKMT_CREATEALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocationflags)

[**D3DKMT_CREATEKEYEDMUTEX2_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2_flags)