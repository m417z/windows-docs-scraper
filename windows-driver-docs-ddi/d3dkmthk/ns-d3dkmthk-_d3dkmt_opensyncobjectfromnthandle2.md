# _D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2 structure

## Description

**D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2** is used with [D3DKMTOpenSyncObjectFromNtHandle2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensyncobjectfromnthandle2) to open a monitored fence object.

## Members

### `hNtHandle` [in]

NT handle for the sync object to be opened.

### `hDevice` [in]

Device handle to use this sync object on.

### `Flags` [in]

Specifies the desired sync object behavior for this device, such as wait and signal semantics and TDR handling.

### `hSyncObject` [out]

Handle to the sync object that can be used in this process.

### `MonitoredFence`

Contains sync object virtual addresses that can be used in this process.

### `MonitoredFence.FenceValueCPUVirtualAddress` [out]

A read-only mapping of the fence value for the CPU. This is a user mode address readable from the process that created the monitored fence object. For 32 bit platforms that support 64 bit atomic reads via methods such as `InterlockedCompareExchange64(pointer,0,0)`, the mapping will be made read-write instead of read-only to avoid an access violation during the interlocked operation. Depending on the value of **No64BitAtomics** cap, this address points to either a 32 bit or a 64 bit underlying value.

### `MonitoredFence.FenceValueGPUVirtualAddress` [out]

A read-write mapping of the fence value for the GPU. A driver can signal a new fence value by inserting a GPU write command for this address into a command buffer, and the DirectX graphics kernel will unblock waiters for this fence object value. This GPU virtual address is mapped asynchronously, and the driver should wait for the device that opened or created the monitored fence synchronization object to reach **PagingFenceValue** on its paging fence object prior to accessing this GPU virtual address. Depending on the value of **No64BitAtomics** cap, this address points to either a 32 bit or a 64 bit underlying value.

### `MonitoredFence.EngineAffinity` [in]

A bit field, where each bit position (starting from zero) defines a physical adapter index in a linked display adapter link where the GPU virtual address will be committed. Zero means that GPU virtual address will be committed to all physical adapters.

### `Reserved`

The consolidated value of the **MonitoredFence** structure.

## See also

[D3DKMTOpenSyncObjectFromNtHandle2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensyncobjectfromnthandle2)