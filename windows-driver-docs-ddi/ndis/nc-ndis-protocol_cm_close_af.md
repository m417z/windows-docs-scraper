# PROTOCOL_CM_CLOSE_AF callback function

## Description

The
*ProtocolCmCloseAf* function is a required function that releases per-open resources for an address
family that a call manager supports.

**Note** You must declare the function by using the **PROTOCOL_CM_CLOSE_AF** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrAfContext` [in]

Specifies the handle to the call manager's per-AF context area, originally supplied to NDIS by the
call manager's
*ProtocolCmOpenAf* function.

## Return value

*ProtocolCmCloseAf* returns the status of its operation(s) as one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager has successfully released or deactivated any resources that is allocated on behalf of the connection-oriented client that opened this instance of the address family. |
| **NDIS_STATUS_PENDING** | Indicates that the request to close the open instance of the address family will be completed asynchronously. The call manager must call [NdisCmCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmcloseaddressfamilycomplete) when all such operations have been completed. |

## Remarks

*ProtocolCmCloseAf* releases and/or deactivates any resources that were allocated by the call manager
in its
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function. The call
manager also should undo any other actions it took on behalf of the connection-oriented client when the
address family was opened by that client.

If there are any outstanding requests or connections still open on an address family stored in the
*CallMgrAfContext*, a call manager can respond to a client's request to close the address family in
either of the following ways:

* The call manager can fail the request with NDIS_STATUS_NOT_ACCEPTED.
* The call manager can return NDIS_STATUS_PENDING. After the client has closed all calls and
  deregistered all SAPs, the call manager can then close the address family and call
  **NdisCmCloseAddressFamilyComplete** or
  [NdisMCmCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmcloseaddressfamilycomplete) to notify the client. This is the preferred response.

### Examples

To define a *ProtocolCmCloseAf* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmCloseAf* function that is named "MyCmCloseAf", use the **PROTOCOL_CM_CLOSE_AF** type as shown in this code example:

```
PROTOCOL_CM_CLOSE_AF MyCmCloseAf;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmCloseAf(
    NDIS_HANDLE  CallMgrAfContext
    )
  {...}
```

The **PROTOCOL_CM_CLOSE_AF** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_CLOSE_AF** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmcloseaddressfamilycomplete)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)