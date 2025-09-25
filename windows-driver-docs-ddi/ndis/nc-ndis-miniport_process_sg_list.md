# MINIPORT_PROCESS_SG_LIST callback function

## Description

A bus-master miniport driver provides a
*MiniportProcessSGList* function to process scatter/gather lists for network data.

**Note** You must declare the function by using the **MINIPORT_PROCESS_SG_LIST** type. For more
information, see the following Examples section.

## Parameters

### `pDO` [in]

Miniport drivers should ignore this parameter.

### `Reserved` [in]

Miniport drivers should ignore this parameter.

### `pSGL` [in]

A pointer to a scatter/gather list buffer. This is not necessarily the same buffer as the one the
driver specified in the call to the
[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist) function

### `Context` [in]

A pointer to a context area that the miniport driver created prior to calling
**NdisMAllocateNetBufferSGList**.

## Remarks

Miniport drivers call the
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) function to register a
*MiniportProcessSGList* function. When a miniport driver calls
**NdisMAllocateNetBufferSGList** to create a scatter/gather list, NDIS calls HAL to create the list.

NDIS calls the miniport driver's *MiniportProcessSGList* function if **NdisMAllocateNetBufferSGList** is successful. However, a success return from that function does not guarantee the callback was already invoked; it can be invoked asynchronously.

When NDIS calls
*MiniportProcessSGList*, the driver can send the NET_BUFFER structure to the hardware. MiniportProcessSGList submits the physical addresses of the scatter/gather list to the NIC's DMA
and issues a send command to the NIC.

HAL can call
*MiniportProcessSGList* before or after NDIS returns from
**NdisMAllocateNetBufferSGList**. Therefore, driver writers should not assume that the call is made
within the context of
**NdisMAllocateNetBufferSGList**.

NDIS calls
*MiniportProcessSGList* at IRQL = DISPATCH_LEVEL.

### Examples

To define a *MiniportProcessSGList* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportProcessSGList* function that is named "MyProcessSGList", use the **MINIPORT_PROCESS_SG_LIST** type as shown in this code example:

```
MINIPORT_PROCESS_SG_LIST MyProcessSGList;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyProcessSGList(
    PDEVICE_OBJECT  pDO,
    PVOID  Reserved,
    PSCATTER_GATHER_LIST  pSGL,
    PVOID  Context
    )
  {...}
```

The **MINIPORT_PROCESS_SG_LIST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_PROCESS_SG_LIST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)