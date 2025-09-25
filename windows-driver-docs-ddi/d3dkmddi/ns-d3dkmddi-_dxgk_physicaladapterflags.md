# _DXGK_PHYSICALADAPTERFLAGS structure

## Description

**DXGK_PHYSICALADAPTERFLAGS** defines a set of flags to indicate the type of memory management model supported by a device.

## Members

### `IoMmuSupported`

Indicates that the CPU and GPU share a common address space and common page tables.

### `GpuMmuSupported`

Indicates that the video memory manager manages the GPU memory management unit and underlying page tables to expose services to the user mode driver.

### `MovePagingSupported`

Indicates that the device driver is capable of moving content to a new destination on the same memory segment.

### `VPRPagingContextRequired`

Indicates that the device driver requires that move paging operations done within a Video Protected Region (VPR) occur on a different paging context than standard paging operations.

### `AllowHardwareProtectedNoVpr`

Indicates that the hardware does not use a range-based VPR for hardware-protected surfaces, and instead uses allocation based hardware protection.

### `VirtualCopyEngineSupported`

Indicates that the driver implements an emulated aperture segment and uses a virtualized hardware node to map and unmap the page tables for the aperture. Supported starting with Windows 10 version 2004.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

The consolidated value of the bitfield members in this structure.