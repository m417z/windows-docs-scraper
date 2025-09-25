# FILTER_PAUSE callback function

## Description

NDIS calls a filter driver's
*FilterPause* function to initiate a pause operation for the specified filter module.

**Note** You must declare the function by using the **FILTER_PAUSE** type. For more
information, see the following Examples section.

## Parameters

### `FilterModuleContext` [in]

A handle to the context area for the filter module that the filter driver should pause. The filter
driver created and initialized this context area in the
[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach) function.

### `PauseParameters` [in]
A pointer to an
[NDIS_FILTER_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_pause_parameters) structure that defines the pause parameters for the filter
module.

## Return value

NDIS drivers cannot fail a pause request. The filter driver should call the
[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry) function
together with parameters that specify the reason for any errors that occur.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | *FilterPause* successfully paused the specified filter module. |
| **NDIS_STATUS_PENDING** | The filter driver will complete the request asynchronously with a call to the [NdisFPauseComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfpausecomplete) function. |

## Remarks

*FilterPause* is a required function. NDIS can call
*FilterPause* when the filter module is in the
*Running* state. The filter module enters the
*Pausing* state at the start of execution in the
*FilterPause* function.

A filter driver performs the following operations when NDIS calls
*FilterPause*:

* Must call the
  [NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete) function for any queued send buffers that an overlying driver
  created.
* Must call the
  [NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists) function for any queued receive buffers that an underlying driver
  created.
* Must wait for NDIS to return all outstanding send requests that the driver originated to the
  [FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete) function.
* Must wait for NDIS to return all outstanding receive indications that the driver originated to the
  [FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists) function.

After the filter driver returns NDIS_STATUS_SUCCESS from
*FilterPause* or calls the
[NdisFPauseComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfpausecomplete) function, the pause
operation is complete. The filter module is in the
*Paused* state.

In the
*Pausing* or
*Paused* states, a filter driver should continue to handle OID requests or status indications. The
driver should reject calls to its
[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists) function. The driver can pass on calls to its
[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists) function. However, the driver cannot pass any buffers that it created.
The driver must not originate any receive indications or send requests.

In the
*Paused* state, the filter module must not generate send requests or receive indications.

NDIS calls the
[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart) function to initiate a
restart request for a filter module that is in the
*Paused* state.

NDIS calls
*FilterPause* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *FilterPause* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *FilterPause* function that is named "MyPause", use the **FILTER_PAUSE** type as shown in this code example:

```
FILTER_PAUSE MyPause;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyPause(
    NDIS_HANDLE  FilterModuleContext,
    PNDIS_FILTER_PAUSE_PARAMETERS  FilterPauseParameters
    )
  {...}
```

The **FILTER_PAUSE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **FILTER_PAUSE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[FilterReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_receive_net_buffer_lists)

[FilterRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_restart)

[FilterReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_return_net_buffer_lists)

[FilterSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists)

[FilterSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_send_net_buffer_lists_complete)

[NDIS_FILTER_PAUSE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_pause_parameters)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisFPauseComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfpausecomplete)

[NdisFReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreturnnetbufferlists)

[NdisFSendNetBufferListsComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfsendnetbufferlistscomplete)

[NdisWriteEventLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteeventlogentry)