# MINIPORT_OID_REQUEST callback function

## Description

NDIS calls a miniport driver's
*MiniportOidRequest* function to handle an OID request to query or set information in the driver.

**Note** You must declare the function by using the **MINIPORT_OID_REQUEST** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that contains
both the buffer and the request packet for the miniport driver to handle. Depending on the request, the
driver returns requested information in the structure provided.

## Return value

*MiniportOidRequest* can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver has either set or obtained the data as requested. |
| **NDIS_STATUS_PENDING** | The miniport driver will complete the request asynchronously. After the miniport driver has completed all processing, it must call the [NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete) function to inform NDIS that the request is complete. |
| **NDIS_STATUS_INVALID_OID** | The request, specified at *OidRequest*, is invalid or not recognized. |
| **NDIS_STATUS_NOT_SUPPORTED** | The request, specified at *OidRequest*, is recognized, but not supported by the miniport driver. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The buffer, supplied at *OidRequest*, is too small to hold the requested data. |
| **NDIS_STATUS_INVALID_LENGTH** | The value specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST-structure at *OidRequest* is incorrect for the specified OID_ *XXX* code. |
| **NDIS_STATUS_INVALID_DATA** | One or more of the parameters specified for the request at *OidRequest* is invalid. |
| **NDIS_STATUS_NOT_ACCEPTED** | After calling the [MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function to indicate a surprise removal, NDIS calls the driver's [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. If the driver receives any OID requests before NDIS calls *MiniportHaltEx*, it should immediately complete such requests with a status value of NDIS_STATUS_NOT_ACCEPTED. |
| **NDIS_STATUS_REQUEST_ABORTED** | The miniport driver stopped processing the request. For example, NDIS called the [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function. |
| **NDIS_STATUS_INDICATION_REQUIRED** | The miniport driver will provide an OID completion status with a subsequent status indication. A miniport driver cannot return NDIS_STATUS_INDICATION_REQUIRED unless the particular OID allows it. To determine if this status is allowed, see the OID reference page.. For more information about NDIS_STATUS_INDICATION_REQUIRED, see [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) and [NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication). |

## Remarks

A driver specifies the
*MiniportOidRequest* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

NDIS calls the
*MiniportOidRequest* function either on its own behalf or on behalf of a bound protocol driver that
called the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function. Miniport drivers
should examine the request supplied at
*OidRequest* and take the action requested. For more information about the OIDs that miniport drivers
handle, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

Note that NDIS does not validate the OID-specific contents at
*OidRequest* . Therefore, the driver itself must validate these contents. If the driver determines
that the value to be set is out of bounds, it should fail the request and return
NDIS_STATUS_INVALID_DATA.

If
*MiniportOidRequest* returns NDIS_STATUS_PENDING, NDIS will not call
*MiniportOidRequest* with another request, for the miniport adapter specified at
MiniportAdapterContext, until the pending request is completed.

**Note** The NDIS check-for-hang logic will not reset a miniport driver that is not
responding if the miniport driver is waiting in the context of the
*MiniportOidRequest* call. Therefore, miniport drivers should not wait for hardware operations to
complete from within the context of the
*MiniportOidRequest* call. Instead, the driver can return NDIS_STATUS_PENDING and queue a work
item.

NDIS calls
*MiniportOidRequest* at IRQL == PASSIVE_LEVEL .

### Examples

To define a *MiniportOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportOidRequest* function that is named "MyOidRequest", use the **MINIPORT_OID_REQUEST** type as shown in this code example:

```
MINIPORT_OID_REQUEST MyOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyOidRequest(
    NDIS_HANDLE  MiniportAdapterContext,
    PNDIS_OID_REQUEST  OidRequest
    )
  {...}
```

The **MINIPORT_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)