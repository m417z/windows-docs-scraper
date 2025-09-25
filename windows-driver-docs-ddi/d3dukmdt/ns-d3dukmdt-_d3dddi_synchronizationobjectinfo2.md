# D3DDDI_SYNCHRONIZATIONOBJECTINFO2 structure

## Description

The **D3DDDI_SYNCHRONIZATIONOBJECTINFO2** structure contains information about a second-generation synchronization object.

## Members

### `Type`

[in] A value of type [**D3DDDI_SYNCHRONIZATIONOBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_synchronizationobject_type) that indicates the type of synchronization object.

### `Flags`

[in] A [**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags) structure that specifies, in bit-field flags, attributes of the synchronization object.

### `SynchronizationMutex`

A structure that contains information about a synchronization mutex. If the **Type** member is equal to **D3DDDI_SYNCHRONIZATION_MUTEX**, the union in **D3DDDI_SYNCHRONIZATIONOBJECTINFO2** holds a **SynchronizationMutex** structure.

### `SynchronizationMutex.InitialState`

A Boolean value that indicates whether the synchronization mutex is initially owned by an object. A value of TRUE indicates that the mutex is owned; FALSE indicates that the mutex is not owned.

### `Semaphore`

A structure that contains information about a semaphore. If the **Type** member is equal to **D3DDDI_SEMAPHORE**, the union in **D3DDDI_SYNCHRONIZATIONOBJECTINFO2** holds a **Semaphore** structure.

### `Semaphore.MaxCount`

The maximum number of events that an object can be waiting for.

### `Semaphore.InitialCount`

The initial number of events that an object is waiting for.

### `Fence`

A structure that contains information about a fence. If the **Type** member is equal to **D3DDDI_FENCE**, the union in **D3DDDI_SYNCHRONIZATIONOBJECTINFO2** holds a **Fence** structure.

### `Fence.FenceValue`

A 64-bit value that specifies the initial fence value.

### `CPUNotification`

A structure that contains information about a CPU notification. If the **Type** member is equal to **D3DDDI_CPU_NOTIFICATION**, the union in **D3DDDI_SYNCHRONIZATIONOBJECTINFO2** holds a **CPUNotification** structure.

### `CPUNotification.Event`

The handle to the CPU notification event.

### `MonitoredFence`

A structure that contains information about a monitored fence. If the **Type** member is equal to **D3DDDI_MONITORED_FENCE**, the union in **D3DDDI_SYNCHRONIZATIONOBJECTINFO2** holds a **MonitoredFence** structure.

Monitored fences can be shared only by using NT handles for security reasons, so the [**NtSecuritySharing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags) flag must be set when using a monitored fence.

Supported starting with Windows 10.

### `MonitoredFence.InitialFenceValue`

[in] A 64-bit value that specifies the initial fence value.

Supported starting with Windows 10.

### `MonitoredFence.FenceValueCPUVirtualAddress`

[out] A read-only mapping of the fence value for the CPU. This is a user mode address readable from the process that created the monitored fence object. For 32 bit platforms that support 64 bit atomic reads via methods such as ```InterlockedCompareExchange64(pointer,0,0)```, the mapping will be made read-write instead of read-only to avoid an access violation during the interlocked operation. Depending on the value of **No64BitAtomics** cap, this address points to either a 32 bit or a 64 bit underlying value.

Supported starting with Windows 10.

### `MonitoredFence.FenceValueGPUVirtualAddress`

[out] A read-write mapping of the fence value for the GPU. A driver can signal a new fence value by inserting a GPU write command for this address into a command buffer, and *Dxgkrnl* will unblock waiters for this fence object value. Depending on the value of **No64BitAtomics** cap, this address points to either a 32 bit or a 64 bit underlying value. If the device doesn’t support cache coherency with the CPU, it shouldn't write to the fence value using the GPU virtual address. Access to the fence value should be done only by the CPU.

Supported starting with Windows 10.

### `MonitoredFence.EngineAffinity`

[in] A bit field, where each bit position (starting from zero) defines a physical adapter index in a link display adapter (LDA) link where the GPU virtual address will be committed. Zero means that the GPU virtual address will be committed to all physical adapters.

Supported starting with Windows 10.

### `PeriodicMonitoredFence`

A structure that contains information about a periodic monitored fence. If the **Type** member is equal to **D3DDDI_PERIODIC_MONITORED_FENCE**, the union in **D3DDDI_SYNCHRONIZATIONOBJECTINFO2** holds a **MonitoredFence** structure.

Supported starting with Windows 10.

#### VidPnTargetID

[out] The output ID that the compositor wishes to receive notifications for.

### `PeriodicMonitoredFence.hAdapter`

[in] A handle to the adapter associated with VidPnSourceID

### `PeriodicMonitoredFence.VidPnTargetId`

### `PeriodicMonitoredFence.Time`

[out] Represents an offset before the VSync (time of VSync – Time parameter). The Time value may not be longer than a VSync interval (1 / DisplayModeRefresh). Time is specified in units of 100ns.

### `PeriodicMonitoredFence.FenceValueCPUVirtualAddress`

[in] Read-only mapping of the fence value for the CPU

### `PeriodicMonitoredFence.FenceValueGPUVirtualAddress`

[in] Read-only mapping of the fence value for the GPU

### `PeriodicMonitoredFence.EngineAffinity`

[in] Defines physical adapters where the GPU VA will be mapped

### `Reserved`

A structure that is reserved for future use. This structure contains the following member:

### `Reserved.[8]`

An array of 64-bit values that are reserved for future use.

### `SharedHandle`

[out] A handle to the shared synchronization object if a shared handle currently exists. The driver should share synchronization objects using NT handles. It should set the [**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS::NtSecuritySharing**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags) to indicate that the object will be shared using NT handles and call [**D3DKMTShareObjects**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects) to get an NT handle. Using global handles is not secure. Any process can guess a global handle and open a shared objects. Global handles are supported only for compatibility reasons with old D3D runtimes.

## See also

[**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags)

[**D3DDDI_SYNCHRONIZATIONOBJECT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_synchronizationobject_type)

[**D3DKMTCreateSynchronizationObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject)

[**D3DKMT_CREATESYNCHRONIZATIONOBJECT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createsynchronizationobject2)