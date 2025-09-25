# PROTOCOL_OID_REQUEST_COMPLETE callback function

## Description

The
*ProtocolOidRequestComplete* function completes the processing of a protocol
driver-initiated OID request for which the
[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function returned
NDIS_STATUS_PENDING.

**Note** You must declare the function by using the **PROTOCOL_OID_REQUEST_COMPLETE** type. For more
information, see the following Examples section.

## Parameters

### `ProtocolBindingContext` [in]

A handle to a protocol driver-allocated context area in which the protocol driver maintains
per-binding run-time state. The driver supplied this handle when it called the
[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex) function.

### `OidRequest` [in]

A pointer to the protocol driver-supplied
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that was
previously passed to the
**NdisOidRequest** function.

### `Status` [in]

The final status of the request. The underlying driver or NDIS determines this final status. This
parameter determines what
*ProtocolOidRequestComplete* does with the information at
*OidRequest*.

## Remarks

*ProtocolOidRequestComplete* uses the input value of
*Status* as follows:

* If
  *Status* is NDIS_STATUS_SUCCESS, the
  **BytesRead** or
  **BytesWritten** member of the
  [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure has been set
  by NDIS or the underlying driver to specify how much protocol driver-supplied information was
  transferred from the buffer at
  **InformationBuffer** to the NIC in a set operation or how much information
  was returned at
  **InformationBuffer** in response to a query operation.

  If the protocol driver made a query,
  *ProtocolOidRequestComplete* can use the data returned at
  **InformationBuffer** in any way determined by the protocol driver, depending
  on the value of the
  **Oid** member.

  For example, if the protocol driver originally initiated an
  [OID_GEN_MAXIMUM_SEND_PACKETS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-send-packets) query,
  *ProtocolOidRequestComplete* might set up state variables in the
  *ProtocolBindingContext* area to throttle the number of outstanding sends the
  driver will set up for subsequent calls to the
  **NdisSendNetBufferLIsts** function.
* If
  *Status* is NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT, the
  **BytesNeeded** member specifies the OID-specific value of the
  **InformationBufferLength** member required to carry out the requested
  operation.

  In these circumstances,
  *ProtocolOidRequestComplete* can allocate sufficient buffer space for the
  request, set up another NDIS_OID_REQUEST structure with the required
  **InformationBufferLength** and same
  **Oid**, and retry the call to the
  [NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function.

  *ProtocolOidRequestComplete* can retry requests for certain other NDIS_STATUS_
  *XXX* arguments, as well, as described in the reference for the
  [NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest) function.
* If
  *Status* is an NDIS_STATUS_
  *XXX* value that is an unrecoverable error,
  *ProtocolOidRequestComplete* should release the memory allocated for the
  NDIS_OID_REQUEST structure and determine whether the driver should close the binding, or adjust its
  binding-specific state information to handle continued network I/O operations on the binding.

For global queries and sets, the underlying connectionless miniport driver's call to the
[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete) function
causes NDIS to call the
*ProtocolOidRequestComplete* function. NDIS forwards the miniport
driver-determined
*Status* passed to
**NdisMOidRequestComplete** as the input
*Status* to
*ProtocolOidRequestComplete*.

For binding-specific queries, NDIS calls the
*ProtocolOidRequestComplete* function itself. Because the NDIS library maintains
bindings for all miniport drivers, NDIS can return binding-specific information only about underlying
drivers that report their medium-type as one for which the system provides a filter library. NDIS returns
NDIS_STATUS_NOT_SUPPORTED for protocol driver-initiated binding-specific queries to other miniport
drivers.

For more information about system-defined OIDs, see
[NDIS OIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/).

*ProtocolOidRequestComplete* can be called before the protocol driver has had
time to inspect the status code that
**NdisOidRequest** returns at
*Status*.

NDIS calls
*ProtocolOidRequestComplete* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *ProtocolOidRequestComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolOidRequestComplete* function that is named "MyOidRequestComplete", use the **PROTOCOL_OID_REQUEST_COMPLETE** type as shown in this code example:

```
PROTOCOL_OID_REQUEST_COMPLETE MyOidRequestComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyOidRequestComplete(
    NDIS_HANDLE  ProtocolBindingContext,
    PNDIS_OID_REQUEST  OidRequest,
    NDIS_STATUS  Status
    )
  {...}
```

The **PROTOCOL_OID_REQUEST_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_OID_REQUEST_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisMOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismoidrequestcomplete)

[NdisOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisoidrequest)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[OID_GEN_MAXIMUM_SEND_PACKETS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-send-packets)