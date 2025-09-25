# MINIPORT_DIRECT_OID_REQUEST callback function

## Description

NDIS calls a miniport driver's
*MiniportDirectOidRequest* function to handle a direct OID request to query or set information in the
driver.

**Note** You must declare the function by using the **MINIPORT_DIRECT_OID_REQUEST** type. For
more information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that contains
both the buffer and the request packet for the miniport driver to handle. Depending on the request, the
driver returns requested information in the structure that is provided.

## Return value

*MiniportDirectOidRequest* can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver set or obtained the data as requested. |
| **NDIS_STATUS_PENDING** | The miniport driver will complete the request asynchronously. After the miniport driver has completed all processing, it must call the [NdisMDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismdirectoidrequestcomplete) function to inform NDIS that the request is complete. |
| **NDIS_STATUS_INVALID_OID** | The request that *OidRequest* specified was invalid or not recognized. |
| **NDIS_STATUS_NOT_SUPPORTED** | The request that *OidRequest* specified was recognized, but the miniport driver does not support it. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The buffer that *OidRequest* supplies was too small to hold the requested data. |
| **NDIS_STATUS_INVALID_LENGTH** | The value that was specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST structure at *OidRequest* is incorrect for the specified OID_*Xxx* code. |
| **NDIS_STATUS_INVALID_DATA** | One or more of the parameters that were specified for the request at *OidRequest* were invalid. |
| **NDIS_STATUS_NOT_ACCEPTED** | After calling the [MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function to indicate a surprise removal, NDIS called the driver's [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. If the driver received any OID requests before NDIS calls *MiniportHaltEx*, it should immediately complete such requests with a status value of NDIS_STATUS_NOT_ACCEPTED. |
| **NDIS_STATUS_REQUEST_ABORTED** | The miniport driver stopped processing the request. For example, NDIS called the [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function. |
| **NDIS_STATUS_INDICATION_REQUIRED** | The miniport driver will provide an OID completion status with a subsequent status indication. A miniport driver cannot return NDIS_STATUS_INDICATION_REQUIRED unless the particular OID allows it. To determine if this status is allowed, see the OID reference page.. For more information about NDIS_STATUS_INDICATION_REQUIRED, see [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) and [NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication). |

## Remarks

*MiniportDirectOidRequest* is an optional function. A miniport driver registers this function if it
handles direct OID requests. A driver specifies the
*MiniportDirectOidRequest* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function. A miniport driver that registers the
[MiniportCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_direct_oid_request) function must also register
*MiniportDirectOidRequest*.

NDIS calls the
*MiniportDirectOidRequest* function either on its own behalf or on behalf of a bound protocol driver
that called the
[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest) function.
Miniport drivers should examine the request that is supplied at the
*OidRequest* parameter and take the action requested.

Note that NDIS does not validate the OID-specific contents at
*OidRequest*. Therefore, the driver itself must validate these contents. If the driver determines
that the value to be set is out of bounds, it should fail the request and return
NDIS_STATUS_INVALID_DATA.

NDIS does not serialize requests that it sends to
*MiniportDirectOidRequest* with other OID requests. The miniport driver must be able to handle
multiple calls to
*MiniportDirectOidRequest* when other requests that are sent to
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) or
*MiniportDirectOidRequest* are outstanding.

**Note** The NDIS check-for-hang logic will not reset a miniport driver that is not
responding if the miniport driver is waiting in the context of the
*MiniportOidRequest* call. Therefore, miniport drivers should not wait for hardware operations to
complete from within the context of the
*MiniportOidRequest* call. Instead, the driver can return NDIS_STATUS_PENDING and queue a work
item.

NDIS calls
*MiniportDirectOidRequest* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *MiniportDirectOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportDirectOidRequest* function that is named "MyDirectOidRequest", use the **MINIPORT_DIRECT_OID_REQUEST** type as shown in this code example:

```
MINIPORT_DIRECT_OID_REQUEST MyDirectOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyDirectOidRequest(
    NDIS_HANDLE  MiniportAdapterContext,
    PNDIS_OID_REQUEST  OidRequest
    )
  {...}
```

The **MINIPORT_DIRECT_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_DIRECT_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_direct_oid_request)

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[MiniportDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_direct_oid_request)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest)

[NdisMDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismdirectoidrequestcomplete)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)