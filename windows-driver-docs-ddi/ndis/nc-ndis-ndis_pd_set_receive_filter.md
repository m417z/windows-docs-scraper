# NDIS_PD_SET_RECEIVE_FILTER callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*NdisPDSetReceiveFilter* function to direct specific flows of packets to a specific PD receive queue.

**Note** You must declare the function by using the **NDIS_PD_SET_RECEIVE_FILTER** type. For more
information, see the following Examples section.

## Parameters

### `ProviderHandle` [in]

A provider handle that identifies the PD-capable miniport driver's provider object.

### `FilterParameters` [in]

Parameters that identify any necessary information for the filter. For more information, see the [NDIS_PD_FILTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_filter_parameters) structure.

### `FilterHandle` [out]

A handle to the filter.

## Return value

This function returns STATUS_SUCCESS when it completes successful, otherwise it returns the appropriate error code.

## Remarks

PD filters are applied before any spreading takes place this is why packet matching a PD filter can be placed into their dedicated PD queue, and the rest of the packets can be spread by RSS as usual. The PD client is responsible for plumbing non-overlapping ambiguous filters. However, some PD provides may allow overlapping ambiguous filters as long as the PD client can pass a priority value that indicates which filter must be applied first. The PD provider may fail filter set requests with STATUS_NOT_SUPPORTED if the client attempts to set filters with conflicting profiles or overlapping match conditions. The [NDIS_PD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pd_capabilities) structure does not allow the provider to advertise all valid combinations of profiles that the PD client can use simultaneously, this is why some of the capabilities are discovered by the PD client at runtime when and if the PD provider fails the filter set request with STATUS_NOT_SUPPORTED

### Examples

To define a *NdisPDSetReceiveFilter* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *NdisPDSetReceiveFilter* function that is named "MyPDSetReceiveFilter", use the **NDIS_PD_SET_RECEIVE_FILTER** type as shown in this code example:

```
NDIS_PD_SET_RECEIVE_FILTER MyPDSetReceiveFilter;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyPDSetReceiveFilter(
    NDIS_PD_PROVIDER_HANDLE  ProviderHandle,
    CONST NDIS_PD_FILTER_PARAMETERS*  FilterParameters,
    NDIS_PD_FILTER_HANDLE*  FilterHandle
    )
  {...}
```

The **NDIS_PD_SET_RECEIVE_FILTER** function type is defined in the Ntddndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **NDIS_PD_SET_RECEIVE_FILTER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).