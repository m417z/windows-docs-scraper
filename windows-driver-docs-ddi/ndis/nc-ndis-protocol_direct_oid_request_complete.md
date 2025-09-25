# PROTOCOL_DIRECT_OID_REQUEST_COMPLETE callback function

## Description

The
*ProtocolDirectOidRequestComplete* function completes the processing of a protocol
driver-initiated direct OID request for which the
[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest) function returned
NDIS_STATUS_PENDING.

**Note** You must declare the function by using the **PROTOCOL_DIRECT_OID_REQUEST_COMPLETE** type. For more
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
**NdisDirectOidRequest** function.

### `Status` [in]

The final status of the request. The underlying driver or NDIS determines this final status. This
parameter determines what
*ProtocolDirectOidRequestComplete* does with the information at
*OidRequest*.

## Remarks

*ProtocolDirectOidRequestComplete* is an optional function. If a protocol driver
does not use direct OID requests, it can set the entry point for this function to **NULL** when it calls the
[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver) function.

*ProtocolDirectOidRequestComplete* uses the input value of the
*Status* parameter as follows:

* If
  *Status* is NDIS_STATUS_SUCCESS, the
  **BytesRead** or
  **BytesWritten** member of the
  [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure has been set
  by NDIS or the underlying driver. These values specify how much protocol driver-supplied information
  was transferred from the buffer at
  **InformationBuffer** to the NIC in a set operation or how much information
  was returned at
  **InformationBuffer** in response to a query operation.

  If the protocol driver made a query,
  *ProtocolDirectOidRequestComplete* can use the data that is returned at
  **InformationBuffer** in any way that the protocol driver determines,
  depending on the value of the
  **Oid** member.

  For example, if the protocol driver originally initiated an
  [OID_GEN_MAXIMUM_SEND_PACKETS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-send-packets) query,
  *ProtocolDirectOidRequestComplete* might set up state variables in the
  *ProtocolBindingContext* area to throttle the number of outstanding sends that
  the driver will set up for subsequent calls to the
  [NdisSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissendnetbufferlists) function.
* If
  *Status* is NDIS_STATUS_INVALID_LENGTH or NDIS_STATUS_BUFFER_TOO_SHORT, the
  **BytesNeeded** member specifies the OID-specific value of the
  **InformationBufferLength** member that is required to carry out the
  requested operation.

  In these circumstances,
  *ProtocolDirectOidRequestComplete* can allocate sufficient buffer space for the
  request, set up another NDIS_OID_REQUEST structure with the required
  **InformationBufferLength** value and same
  **Oid** value, and retry the call to the
  [NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest) function.

  *ProtocolDirectOidRequestComplete* can retry requests for certain other
  NDIS_STATUS_
  *Xxx* arguments, as well, as described in
  [NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest).
* If
  *Status* is an NDIS_STATUS_
  *Xxx* value that is an unrecoverable error,
  *ProtocolDirectOidRequestComplete* should release the memory that is allocated
  for the NDIS_OID_REQUEST structure and determine whether the driver should close the binding or adjust
  its binding-specific state information to handle continued network I/O operations on the binding.

*ProtocolDirectOidRequestComplete* can be called before the protocol driver has
had time to inspect the status code that
**NdisDirectOidRequest** returns at
*Status*.

NDIS calls
*ProtocolDirectOidRequestComplete* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *ProtocolDirectOidRequestComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolDirectOidRequestComplete* function that is named "MyDirectOidRequestComplete", use the **PROTOCOL_DIRECT_OID_REQUEST_COMPLETE** type as shown in this code example:

```
PROTOCOL_DIRECT_OID_REQUEST_COMPLETE MyDirectOidRequestComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyDirectOidRequestComplete(
    NDIS_HANDLE  ProtocolBindingContext,
    PNDIS_OID_REQUEST  OidRequest,
    NDIS_STATUS  Status
    )
  {...}
```

The **PROTOCOL_DIRECT_OID_REQUEST_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_DIRECT_OID_REQUEST_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NdisDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisdirectoidrequest)

[NdisMDirectOidRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismdirectoidrequestcomplete)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[OID_GEN_MAXIMUM_SEND_PACKETS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-maximum-send-packets)