# FILTER_SET_MODULE_OPTIONS callback function

## Description

The
*FilterSetModuleOptions* function changes the set of optional services that are
associated with a specified filter module.

**Note** You must declare the function by using the **FILTER_SET_MODULE_OPTIONS** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that is the target of this request. The filter
driver created and initialized this context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

## Return value

*FilterSetModuleOptions* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *FilterSetModuleOptions* successfully registered the filter module's optional services and resources. |
| **NDIS_STATUS_RESOURCES** | *FilterSetModuleOptions* could not allocate the resources that the filter module requires. |
| **NDIS_STATUS_ *XXX* or NTSTATUS_ *XXX*** | The filter driver's attempt to register options failed. Usually, such an error status is propagated from an **Ndis*Xxx*** function or a kernel-mode support routine. |

## Remarks

If
*FilterSetModuleOptions* is defined, NDIS calls
*FilterSetModuleOptions* before it calls the
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function to start the
filter module.

A filter driver specifies the default values for the changeable filter module options in the
NDIS_FILTER_DRIVER_CHARACTERISTICS structure that it passes to the
[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) function during driver initialization.

To change options for a specific filter module at run time, the filter driver must also specify an
entry point for
*FilterSetModuleOptions* in the
[NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics) structure.

To specify the options that should be changed,
*FilterSetModuleOptions* defines a characteristics structure and calls the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.
Filter drivers must not call
**NdisSetOptionalHandlers** from a different thread.

The possible characteristics structures that can be specified from
*FilterSetModuleOptions* are:

[NDIS_FILTER_PARTIAL_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_partial_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_generic_characteristics)

[NDIS_CLIENT_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_client_chimney_offload_tcp_characteristics)

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_generic_characteristics)

[NDIS_PROVIDER_CHIMNEY_OFFLOAD_TCP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndischimney/ns-ndischimney-_ndis_provider_chimney_offload_tcp_characteristics)

For information on the last four structures, see
[NDIS 6.0 TCP chimney offload
documentation](https://learn.microsoft.com/windows-hardware/drivers/network/full-tcp-offload).

The options that are specified in each characteristics structure can be different for each filter
module.

When NDIS calls the
*FilterDetach* function, the filter driver should undo all the operations that
were performed in
*FilterSetModuleOptions*.

NDIS calls
*FilterSetModuleOptions* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *FilterSetModuleOptions* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterSetModuleOptions* function that is named "MySetModuleOptions", use the **FILTER_SET_MODULE_OPTIONS** type as shown in this code example:

```
FILTER_SET_MODULE_OPTIONS MySetModuleOptions;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MySetModuleOptions(
    NDIS_HANDLE  FilterModuleContext
    )
  {...}
```

The **FILTER_SET_MODULE_OPTIONS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_SET_MODULE_OPTIONS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics)

[NDIS_FILTER_PARTIAL_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_partial_characteristics)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)