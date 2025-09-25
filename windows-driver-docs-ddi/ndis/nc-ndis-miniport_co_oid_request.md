# MINIPORT_CO_OID_REQUEST callback function

## Description

The
*MiniportCoOidRequest* function handles an OID request to query or set information in CoNDIS miniport
driver.

**Note** You must declare the function by using the **MINIPORT_CO_OID_REQUEST** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `MiniportVcContext` [in]

A handle to a miniport driver-allocated context area in which the miniport driver maintains its
per-virtual connection (VC) state. The miniport driver supplied this handle to NDIS from its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function. If the
request is
not VC-specific, this parameter is **NULL**.

### `NdisRequest`

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that contains
both the buffer and the request packet for the miniport driver to handle. Depending on the request, the
driver returns requested information in the structure that this parameter points to.

## Return value

*MiniportCoOidRequest* can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver either set or obtained the data as requested. |
| **NDIS_STATUS_PENDING** | The miniport driver will complete the request asynchronously. After the miniport driver has completed all processing, it must call the [NdisMCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcooidrequestcomplete) function to inform NDIS that the request is complete. |
| **NDIS_STATUS_INVALID_OID** | The request that the *OidRequest* parameter specified was invalid or not recognized. |
| **NDIS_STATUS_NOT_SUPPORTED** | The request that the *OidRequest* parameter specified was recognized but not supported by the miniport driver. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The buffer that the *OidRequest* parameter supplied was too small to hold the requested data. |
| **NDIS_STATUS_INVALID_LENGTH** | The value that was specified in the **InformationBufferLength** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure at *OidRequest* is incorrect for the specified OID_*XXX* code. |
| **NDIS_STATUS_INVALID_DATA** | One or more of the parameters that were specified for the request at *OidRequest* iwas invalid. |
| **NDIS_STATUS_NOT_ACCEPTED** | After NDIS calls the [MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function to indicate a surprise removal, NDIS calls the driver's [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. If the driver receives any OID requests before NDIS calls *MiniportHaltEx*, it should immediately complete such requests with a status value of NDIS_STATUS_NOT_ACCEPTED. |
| **NDIS_STATUS_REQUEST_ABORTED** | The miniport driver stopped processing the request. For example, NDIS called the [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) or [MiniportCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_oid_request) function. |

## Remarks

NDIS calls the
*MiniportCoOidRequest* function to handle an OID request to query or set information in a CoNDIS
miniport driver.

To register
*MiniportCoOidRequest*, miniport drivers call the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
from the
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function. In
*MiniportSetOptions*, the miniport driver initializes an
[NDIS_MINIPORT_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_co_characteristics) structure and passes it at the
*OptionalHandlers* parameter of
**NdisSetOptionalHandlers**.

NDIS calls the
*MiniportCoOidRequest* function either on its own behalf or on behalf of a bound protocol driver that
called the
[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest) function. Miniport
drivers should examine the request supplied at
*OidRequest* and take the action requested. For more information about the OIDs that miniport drivers
handle, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

Note that NDIS does not validate the OID-specific contents at
*OidRequest* . Therefore, the driver itself must validate these contents. If the driver determines
that the value to be set is out of bounds, it should fail the request and return
NDIS_STATUS_INVALID_DATA.

If
*MiniportCoOidRequest* returns NDIS_STATUS_PENDING, NDIS can call
*MiniportCoOidRequest* with another request, for the miniport adapter specified at
*MiniportAdapterContext*, before the pending request is completed. NDIS does not serialize connection
oriented OID requests.

### Examples

To define a *MiniportCoOidRequest* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCoOidRequest* function that is named "MyCoOidRequest", use the **MINIPORT_CO_OID_REQUEST** type as shown in this code example:

```
MINIPORT_CO_OID_REQUEST MyCoOidRequest;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoOidRequest(
    NDIS_HANDLE  MiniportAdapterContext,
    NDIS_HANDLE  MiniportVcContext,
    PNDIS_OID_REQUEST  OidRequest
    )
  {...}
```

The **MINIPORT_CO_OID_REQUEST** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CO_OID_REQUEST** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_oid_request)

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[NDIS_MINIPORT_CO_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_co_characteristics)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisCoOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscooidrequest)

[NdisMCoOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcooidrequestcomplete)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)