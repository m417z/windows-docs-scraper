# NDIS_TIMER_FUNCTION callback function

## Description

The
*NdisTimerFunction* callback function is called by NDIS after a driver sets a one-shot or periodic timer when a
timer fires.

**Note** You must declare the function by using the **NDIS_TIMER_FUNCTION** type. For more
information, see the following Examples section.

## Parameters

### `SystemSpecific1` [in]

A pointer to a system-specific value that is reserved for system use.

### `FunctionContext` [in]

A pointer to a driver-supplied context area that the driver passed to the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function. If the
*FunctionContext* parameter of
**NdisSetTimerObject** was **NULL**, NDIS uses the default value that the driver specified in the
[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics) structure. The driver passed the structure to the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function
to initialize the associated timer object.

### `SystemSpecific2` [in]

A pointer to a system-specific value that is reserved for system use.

### `SystemSpecific3` [in]

A pointer to a system-specific value that is reserved for system use.

## Remarks

Any NDIS driver can have one or more
*NdisTimerFunction* callback functions. Each such
*NdisTimerFunction* callback must be associated with a different driver-allocated and initialized
timer object.

The driver initializes a driver-allocated timer object by calling the
[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject) function.

A subsequent call to the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function causes the
*NdisTimerFunction* callback that is associated with the timer object to be run after a specified
interval or periodically.

To cancel calls to
*NdisTimerFunction*, call the
[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject) function. NDIS
might still call
*NdisTimerFunction* if the timeout has already expired before the call to
**NdisCancelTimerObject**.

If a
*NdisTimerFunction* callback shares resources with other driver functions, the driver should
synchronize access to those resources with a spin lock.

### Examples

To define a *NdisTimerFunction* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *NdisTimerFunction* function that is named "MyTimerCallback", use the **NDIS_TIMER_FUNCTION** type as shown in this code example:

```
NDIS_TIMER_FUNCTION MyTimerCallback;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyTimerCallback(
    PVOID  SystemSpecific1,
    PVOID  FunctionContext,
    PVOID  SystemSpecific2,
    PVOID  SystemSpecific3
    )
  {...}
```

The **NDIS_TIMER_FUNCTION** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_TIMER_FUNCTION** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[Initializing NDIS Timers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-ndis-timers)

[NDIS_TIMER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_timer_characteristics)

[NdisAllocateTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatetimerobject)

[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)

[Servicing Timers](https://learn.microsoft.com/windows-hardware/drivers/network/servicing-timers)

[Setting and Clearing Timers](https://learn.microsoft.com/windows-hardware/drivers/network/setting-and-clearing-timers)