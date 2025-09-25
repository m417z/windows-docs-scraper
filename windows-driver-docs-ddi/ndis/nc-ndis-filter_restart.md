# FILTER_RESTART callback function

## Description

The
*FilterRestart* function initiates a restart operation for the specified filter module.

**Note** You must declare the function by using the **FILTER_RESTART** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that the filter driver should restart. The
filter driver created and initialized this context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `RestartParameters` [in]
A pointer to an
[NDIS_FILTER_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_restart_parameters) structure that defines the restart parameters for the filter
module.

## Return value

*FilterRestart* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *FilterRestart* successfully restarted the specified filter module. |
| **NDIS_STATUS_PENDING** | The filter driver will complete the request asynchronously with a call to the [NdisFRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartcomplete) function after it completes the restart operation. |
| **NDIS_STATUS_RESOURCES** | *FilterRestart* failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | None of the preceding status values applies. The filter driver should call the [NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry) function together with parameters that specify the reason for the failure. |

## Remarks

*FilterRestart* is a required function for filter drivers. NDIS can call
*FilterRestart* when a filter module is in the
*Paused* state. The filter module enters the
*Restarting* state at the start of the execution of
*FilterRestart*.

When NDIS calls
*FilterRestart*, a filter driver:

* Must complete the operations that are required to restart normal send and receive operations.
* Optionally reads or writes configuration parameters.
* Optionally reallocates buffer pools.
* Optionally modifies the restart attributes that are specified in the
  **RestartAttributes** member of the
  [NDIS_FILTER_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_restart_parameters) structure. If the pointer in
  **RestartAttributes** is **NULL**, the filter driver should not modify or add to the restart attributes
  list. If the pointer in
  **RestartAttributes** is non-**NULL**, it points to the first
  [NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure
  in the list of restart attributes. If a filter driver does not restart, it should not modify any
  attributes.
* Optionally uses OID requests to query or set information in the underlying drivers. Filter drivers
  should not issue OID requests for information that is already provided in the list of restart
  attributes.
* Returns NDIS_STATUS_SUCCESS or a failure status.

If a filter driver modifies the list of restart attributes, the filter driver:

* Should not modify any media-specific attributes if it does not recognize the OID in the
  **Oid** member of the
  [NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure.
* Can add new media-specific attributes to the list of restart attributes. In this situation, the
  filter driver must allocate a new NDIS_RESTART_ATTRIBUTES structure--for example, with the
  [NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function--and provide memory space for the new attributes.
  After propagating the restart attributes to overlying drivers, NDIS frees the attributes memory for
  filter drivers.
* Can modify the media-specific attributes in the list of restart attributes. If the filter driver
  requires more memory space, it can free the
  [NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes) structure
  with the
  [NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function and allocate a
  new structure to contain the modified information. After propagating the restart attributes to
  overlying drivers, NDIS frees the attributes memory for filter drivers.
* Should, if the
  **Oid** member in the NDIS_RESTART_ATTRIBUTES structure is
  [OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes), make sure that the
  [NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes) structure contains the information that the filter driver
  requires. To make sure that the NDIS_RESTART_GENERAL_ATTRIBUTES structure contains the required
  information, you should check the
  **Revision** member in the
  [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that is
  specified in the
  **Header** member of the NDIS_RESTART_GENERAL_ATTRIBUTES structure.

  **Note** A filter driver can modify any member in the NDIS_RESTART_GENERAL_ATTRIBUTES
  structure. If some attributes that the filter driver should modify are not included in the revision of
  the structure that NDIS provided, the filter driver should rely on overlying drivers to issue OID
  requests for the missing attributes. The filter driver can modify the attributes when it completes the
  OID request.
* Must, if the filter driver changes restart attributes, provide a
  [FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request) function. The
  filter driver must make sure that the information that overlying drivers receive in the restart
  attributes is consistent with the information that they receive in response to OID requests.

After the filter driver returns its status or calls the
[NdisFRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartcomplete) function, the
restart operation is complete. If the operation completed successfully, the filter module is in the
*Running* state and normal send and receive processing is resumed. If the restart operation failed,
the filter module returns to the
*Paused* state.

NDIS calls
*FilterRestart* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *FilterRestart* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterRestart* function that is named "MyRestart", use the **FILTER_RESTART** type as shown in this code example:

```
FILTER_RESTART MyRestart;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyRestart(
    NDIS_HANDLE  FilterModuleContext,
    PNDIS_FILTER_RESTART_PARAMETERS  FilterRestartParameters
    )
  {...}
```

The **FILTER_RESTART** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_RESTART** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_oid_request)

[FilterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_status)

[NDIS_FILTER_RESTART_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_restart_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_attributes)

[NDIS_RESTART_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_restart_general_attributes)

[NDIS_STATUS_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-link-state)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFRestartComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfrestartcomplete)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry)

[OID_GEN_LINK_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-link-state)

[OID_GEN_MINIPORT_RESTART_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-miniport-restart-attributes)