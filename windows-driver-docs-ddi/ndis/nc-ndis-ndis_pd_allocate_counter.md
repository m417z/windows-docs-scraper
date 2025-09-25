# NDIS_PD_ALLOCATE_COUNTER callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*NdisPDAllocateCounter* function to allocate a counter object. There are three kinds of counters:

* Receive queue counters are used for tracking receive queue activity.
* Transmit queue counters are used for tracking transmit queue activity.
* Filter counters are used for tracking filter match activity.

**Note** You must declare the function by using the **NDIS_PD_ALLOCATE_COUNTER** type. For more
information, see the following Examples section.

## Parameters

### `ProviderHandle` [in]

A provider handle that identifies the PD-capable miniport driver's provider object.

### `CounterParameters` [in]

An [NDIS_PD_COUNTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_counter_parameters) structure that specifies information such as the counter type.

### `CounterHandle` [out]

A pointer to a driver-allocated counter handle variable. If the counter allocation succeeds, the miniport driver returns a handle to the newly allocated counter in this variable.

## Return value

*NdisPDAllocateCounter* can return one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The miniport driver successfully allocated the counter and returned a handle in the *CounterHandle* parameter. |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation failed due to insufficient resources. |

## Remarks

The same counter object can be associated with multiple queue or filter objects of the same type as the counter. For example, if there are 5 receive queues (RQ1 through RQ5) and 2 receive counters (RC1 and RC2), receive counter RC1 could be associated with receive queues RQ1, RQ2, RQ3, and receive counter RC2 could be associated with receive queues RQ4 and RQ5.

### Examples

To define a *NdisPDAllocateCounter* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *NdisPDAllocateCounter* function that is named "MyPDAllocateCounter", use the **NDIS_PD_ALLOCATE_COUNTER** type as shown in this code example:

```
NDIS_PD_ALLOCATE_COUNTER MyPDAllocateCounter;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NTSTATUS
 MyPDAllocateCounter(
    NDIS_PD_PROVIDER_HANDLE  ProviderHandle,
    CONST NDIS_PD_COUNTER_PARAMETERS*  CounterParameters,
    NDIS_PD_COUNTER_HANDLE*  CounterHandle
    )
  {...}
```

The **NDIS_PD_ALLOCATE_COUNTER** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_ALLOCATE_COUNTER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_PD_COUNTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_counter_parameters)

[NdisPDFreeCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_free_counter)