# DXGK_PHYSICALADAPTERCAPS structure

## Description

The **DXGK_PHYSICALADAPTERCAPS** structure is used to report details of a physical adapter.

## Members

### `NumExecutionNodes`

The number of execution nodes in the physical adapter.

### `PagingNodeIndex`

Index of the paging node for the physical adapter.

### `DxgkPhysicalAdapterHandle`

Handle, which is passed to the kernel mode driver as **DXGKRNL_INTERFACE::DeviceHandle** in [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `Flags`

|Value|Meaning|
|--- |--- |
|Flags.IoMmuSupported TRUE|The adapter supports IoMmu.|
|Flags.GpuMmuSupported TRUE|The adapter supports GpuMmu.|
|Flags.MovePagingSupported TRUE|The adapter supports move paging.|
|Flags.VPRPagingContextRequired TRUE|The adapter requires the index of the VPR paging node.|

### `VPRPagingNode`

Index of the node to be used for move paging in the VPR.

### `VirtualCopyNodeIndex`

Node is specified as a virtual copy engine node. Available starting in Windows 10 version 2004 (WDDM 2.7).