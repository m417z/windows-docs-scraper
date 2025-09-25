# FILTER_DETACH callback function

## Description

NDIS calls a filter driver's
*FilterDetach* function to release all the resources that are associated with a filter module.

**Note** You must declare the function by using the **FILTER_DETACH** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that NDIS will remove from the driver stack.
The filter driver created and initialized this context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

## Remarks

*FilterDetach* is a required function. NDIS calls
*FilterDetach* to remove a filter module from a driver stack. NDIS calls
*FilterDetach* when the filter module is in the
*Paused* state.

*FilterDetach* frees the driver's context areas and other resources (such as buffer pools) for the
affected filter module.

After the filter driver returns from
*FilterDetach*, the filter module is in the
*Detached* state.

NDIS calls
*FilterDetach* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *FilterDetach* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterDetach* function that is named "MyDetach", use the **FILTER_DETACH** type as shown in this code example:

```
FILTER_DETACH MyDetach;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyDetach(
    NDIS_HANDLE  FilterModuleContext
    )
  {...}
```

The **FILTER_DETACH** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_DETACH** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)