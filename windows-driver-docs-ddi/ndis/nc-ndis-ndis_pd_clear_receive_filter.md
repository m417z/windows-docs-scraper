# NDIS_PD_CLEAR_RECEIVE_FILTER callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*NdisPDClearReceiveFilter* function to clear this filter from the PD platform.

**Note** You must declare the function by using the **NDIS_PD_CLEAR_RECEIVE_FILTER** type. For more
information, see the following Examples section.

## Parameters

### `FilterHandle` [in]

A handle to a PD platform filter.

## Return value

This callback function does not return a value.

## Remarks

After this function returns, it's guaranteed that no more newly arriving packet will match this filter. However, there may still be in-flight packets that have already matched this filter and they are on their way to being placed into the target receive queue.

### Examples

To define a *NdisPDClearReceiveFilter* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *NdisPDClearReceiveFilter* function that is named "MyPDClearReceiveFilter", use the **NDIS_PD_CLEAR_RECEIVE_FILTER** type as shown in this code example:

```
NDIS_PD_CLEAR_RECEIVE_FILTER MyPDClearReceiveFilter;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyPDClearReceiveFilter(
    NDIS_PD_FILTER_HANDLE  FilterHandle
    )
  {...}
```

The **NDIS_PD_CLEAR_RECEIVE_FILTER** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_CLEAR_RECEIVE_FILTER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).