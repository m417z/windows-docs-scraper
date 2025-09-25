# PROTOCOL_CL_CLOSE_AF_COMPLETE callback function

## Description

The
*ProtocolClCloseAfComplete* function is used by connection-oriented NDIS clients. All
connection-oriented NDIS clients must have
*ProtocolClCloseAfComplete* functions to complete the asynchronous operations that they initiate with
[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily).

**Note** You must declare the function by using the **PROTOCOL_CL_CLOSE_AF_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the client-initiated request to close the address family, which can
be one of the following:

#### NDIS_STATUS_SUCCESS

The address family was closed. The
*NdisAfHandle* that represented the open address family, which the client stored in its
*ProtocolAfContext* area, is now invalid.

#### NDIS_STATUS_FAILURE

Either the AF has associated VC(s) and/or registered SAP(s) that the client must release before
attempting to close the AF, or the client called
**NdisClCloseAddressFamily** twice because NDIS discovered that the AF state was marked as
"closing."

### `ProtocolAfContext` [in]

Specifies the client-supplied handle to its per-AF context area. The client originally set up this
context area and passed this handle to NDIS with
**NdisClOpenAddressFamilyEx**.

## Remarks

After ensuring that it has no outstanding VCs and/or registered SAPs on its open address family, a
client calls
[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily) to
delete the association between itself, a call manager, and a particular underlying NIC. NDIS calls the
*ProtocolCmCloseAf* function for the call manager that this client originally used to open the
address family as an asynchronous operation. After calling
**NdisClCloseAddressFamily**, the client should consider the
*NdisAfHandle* invalid.

Consequently, the client must have a
*ProtocolClCloseAfComplete* function, which NDIS calls when the asynchronous close-AF operation is
done. If the input
*Status* is NDIS_STATUS_SUCCESS, the client can release its per-AF context area.

### Examples

To define a *ProtocolClCloseAfComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClCloseAfComplete* function that is named "MyClCloseAfComplete", use the **PROTOCOL_CL_CLOSE_AF_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_CLOSE_AF_COMPLETE MyClCloseAfComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClCloseAfComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolAfContext
    )
  {...}
```

The **PROTOCOL_CL_CLOSE_AF_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_CLOSE_AF_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[ProtocolCmCloseAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_af)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)