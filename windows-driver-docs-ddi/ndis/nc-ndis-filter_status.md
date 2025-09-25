# FILTER_STATUS callback function

## Description

The
*FilterStatus* function indicates status changes that are reported by NDIS or an underlying
driver.

**Note** You must declare the function by using the **FILTER_STATUS** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module. The filter driver created and initialized this
context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `StatusIndication` [in]

A pointer to an
[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication) structure
that contains the status information.

## Remarks

*FilterStatus* is an optional function. If a filter driver does not use status indications, it can
set the entry point for this function to **NULL** when it calls the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function.

To determine link status, use the status indications from underlying drivers instead of OID queries.
These status indications will improve system performance and avoid possible race conditions.

A filter driver usually calls the
[NdisFIndicateStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatestatus) function at the
end of its
*FilterStatus* function to pass on the status indication to overlying drivers.

A filter driver can filter out certain status indications or modify the indicated status. To filter
out a status indication, the driver simply does not call
**NdisFIndicateStatus**.

NDIS calls
*FilterStatus* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *FilterStatus* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterStatus* function that is named "MyStatus", use the **FILTER_STATUS** type as shown in this code example:

```
FILTER_STATUS MyStatus;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyStatus(
    NDIS_HANDLE  FilterModuleContext,
    PNDIS_STATUS_INDICATION  StatusIndication
    )
  {...}
```

The **FILTER_STATUS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_STATUS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisFIndicateStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfindicatestatus)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)