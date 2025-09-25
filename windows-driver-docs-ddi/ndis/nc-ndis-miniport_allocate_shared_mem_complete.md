# MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE callback function

## Description

NDIS calls a miniport driver's
*MiniportSharedMemoryAllocateComplete* function to complete a shared memory allocation request that
the miniport driver started by calling the
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) function.

**Note** You must declare the function by using the **MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE**
type. For more information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

The handle to a context area allocated by the miniport driver in which the driver maintains state
information for a NIC. The driver allocates this context area in the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `VirtualAddress` [in]

The base virtual address of the shared memory that the miniport driver allocated by calling
**NdisMAllocateSharedMemoryAsyncEx**.
*VirtualAddress* is **NULL** if the allocation attempt failed.

### `PhysicalAddress` [in]

The base physical address for the NIC to use that is mapped to the address that the
*VirtualAddress* parameter specifies.

### `Length` [in]

The number of bytes that
**NdisMAllocateSharedMemoryAsyncEx** allocated.

### `Context` [in]

A pointer to a context area that the miniport driver specified in the preceding call to
**NdisMAllocateSharedMemoryAsyncEx**.

## Remarks

*MiniportAllocateSharedMemoryComplete* is an optional function for miniport drivers. A miniport
driver registers a
*MiniportAllocateSharedMemoryComplete* function in the NDIS_SG_DMA_DESCRIPTION structure that the
driver passed to the
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) function.

Miniport drivers call
[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex) to allocate shared memory. If
**NdisMAllocateSharedMemoryAsyncEx** returns NDIS_STATUS_PENDING, NDIS calls
*MiniportAllocateSharedMemoryComplete* to pass the memory to the miniport driver.

NDIS calls
*MiniportSharedMemoryAllocateComplete* at IRQL PASSIVE_LEVEL.

### Examples

To define a *MiniportSharedMemoryAllocateComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportSharedMemoryAllocateComplete* function that is named "MySharedMemoryAllocateComplete", use the **MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE** type as shown in this code example:

```
MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE MySharedMemoryAllocateComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MySharedMemoryAllocateComplete(
    NDIS_HANDLE  MiniportAdapterContext,
    PVOID  VirtualAddress,
    PNDIS_PHYSICAL_ADDRESS  PhysicalAddress,
    ULONG  Length,
    PVOID  Context
    )
  {...}
```

The **MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMAllocateSharedMemoryAsyncEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatesharedmemoryasyncex)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)