# MINIPORT_CANCEL_OID_REQUEST callback function

## Description

NDIS calls a miniport driver's
*MiniportCancelOidRequest* function to cancel an OID request.

**Note** You must declare the function by using the **MINIPORT_CANCEL_OID_REQUEST** type. For
more information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `RequestId` [in]

A cancellation identifier for the request. This identifier specifies the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structures that are being
canceled.

## Remarks

A driver specifies the
*MiniportCancelOidRequest* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

When NDIS calls
*MiniportCancelOidRequest*, the miniport driver should attempt to call
[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete) function
as soon as possible.

The request parameters are defined in the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure at
*OidRequest* .

NDIS calls
*MiniportCancelOidRequest* either when the originator of the request cancels the request or when the
time-out, specified at the
**Timeout** member, expires.

If the request processing is still not complete in a miniport driver, the driver calls the
**NdisMOidRequestComplete** function with the status set to NDIS_STATUS_REQUEST_ABORTED.

If the request processing is still not complete in an intermediate driver and the request was
propagated to an underlying driver, the intermediate driver calls the
[NdisCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceloidrequest) function with
the
*OidRequest* parameter set to the value that it sent to the underlying driver.

NDIS calls
*MiniportCancelOidRequest* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *MiniportCancelOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCancelOidRequest* function that is named "MyCancelOidRequest", use the **MINIPORT_CANCEL_OID_REQUEST** type as shown in this code example:

```
MINIPORT_CANCEL_DIRECT_OID_REQUEST MyCancelOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCancelRequest(
    NDIS_HANDLE  MiniportAdapterContext,
    PVOID  RequestId
    )
  {...}
```

The **MINIPORT_CANCEL_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CANCEL_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceloidrequest)

[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)