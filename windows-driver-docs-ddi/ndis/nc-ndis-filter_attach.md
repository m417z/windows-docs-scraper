# FILTER_ATTACH callback function

## Description

NDIS calls a filter driver's
*FilterAttach* function to allocate and initialize a filter module's data structures.

**Note** You must declare the function by using the **FILTER_ATTACH** type. For more
information, see the following Examples section.

## Parameters

### `NdisFilterHandle` [in]

An NDIS handle that identifies a filter module. The filter driver must save this handle. The
handle is required in subsequent calls to
**NdisF*Xxx*** functions.

### `FilterDriverContext` [in]

The handle that the driver passed to the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function that identifies the driver context area.

### `AttachParameters` [in]

A pointer to an
[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters) structure that defines the initialization parameters for the filter
module.

## Return value

*FilterAttach* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *FilterAttach* successfully allocated and initialized data structures for this filter module. |
| **NDIS_STATUS_RESOURCES** | *FilterAttach* failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | *FilterAttach* returns NDIS_STATUS_FAILURE if none of the preceding values applies. The filter driver should call the [NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry) function together with parameters that specify the reason for the failure. |

## Remarks

*FilterAttach* is a required function. NDIS calls a filter driver's
*FilterAttach* function when the specified filter module is in the
*Detached* state. NDIS can call
*FilterAttach* at any time after the call to the
[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function returns.

At the start of execution in
*FilterAttach*, the filter module enters the
*Attaching* state.

Filter drivers should avoid issuing unnecessary OID queries. Instead, use the information in
[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters), when available, to obtain information about underlying drivers.

A filter driver performs the following operations when NDIS calls
*FilterAttach*.

* Creates a context area for the filter module and allocates buffer pools and any other resources.
* Calls the
  [NdisFSetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsetattributes) function together
  with the
  *NdisFilterHandle* that NDIS passed to
  *FilterAttach*. The
  *FilterModuleContext* parameter of
  **NdisFSetAttributes** specifies the filter driver's context area for this filter module. NDIS passes
  this context area to the filter driver's
  *FilterXxx* functions.
* Optionally reads configuration parameters from the registry.
* If the preceding operations completed successfully, the filter module enters the
  *Paused* state.
* If the preceding operations failed, the filter driver must release any resources that it allocated
  in the
  *FilterAttach* function and return the filter module to the
  *Detached* state.
* Returns NDIS_STATUS_SUCCESS or an appropriate failure code.

A filter driver should not make send requests, indicate received data, make OID requests, or make
status indications from the
*Attaching* state.

NDIS calls a filter driver's
[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach) function to release all the
resources that are associated with a filter module and return the filter module to the
*Detached* state.

NDIS calls
*FilterAttach* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *FilterAttach* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterAttach* function that is named "MyAttach", use the **FILTER_ATTACH** type as shown in this code example:

```
FILTER_ATTACH MyAttach;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyAttach(
    NDIS_HANDLE  NdisFilterHandle,
    NDIS_HANDLE  FilterDriverContext,
    PNDIS_FILTER_ATTACH_PARAMETERS  AttachParameters
    )
  {...}
```

The **FILTER_ATTACH** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_ATTACH** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterDetach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_detach)

[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[NDIS_FILTER_ATTACH_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_attach_parameters)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFSetAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsetattributes)

[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry)