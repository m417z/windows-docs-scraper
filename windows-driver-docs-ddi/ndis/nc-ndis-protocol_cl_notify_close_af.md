# PROTOCOL_CL_NOTIFY_CLOSE_AF callback function

## Description

The
*ProtocolClNotifyCloseAf* function
notifies a CoNDIS client that the client should close the associated address family (AF).

**Note** You must declare the function by using the **PROTOCOL_CL_NOTIFY_CLOSE_AF** type.
For more information, see the following Examples section.

## Parameters

### `ClientAfContext` [in]

A client-supplied handle to its context area for the associated AF. The client allocated this
context area and passed this handle to NDIS in its call to the
[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex) function.

## Return value

*ProtocolClNotifyCloseAf* can
return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The client successfully closed the address family. |
| **NDIS_STATUS_PENDING** | The client is handling this request asynchronously, and it will call the [NdisClNotifyCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclnotifycloseaddressfamilycomplete) function when the close operation is complete. |
| **NDIS_STATUS_*XXX*** | The client failed the request for some driver-determined reason. |

## Remarks

The
*ProtocolClNotifyCloseAf* function is required for CoNDIS clients. NDIS calls
*ProtocolClNotifyCloseAf* when a
call manager notifies NDIS that the address family (AF) that the
*ProtocolAfContext* parameter specifies should be closed. In response, the client
should:

1. Call the
   [NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty) function as many times
   as necessary until only a single party remains active on each multipoint virtual connection (VC), if
   the client has any active multipoint connections.
2. Call the
   [NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall) function as many times
   as necessary to close all of the calls that are still open and are associated with the AF.
3. Call the
   [NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap) function as many
   times as necessary to deregister all service access points (SAPs) that the client has registered with
   the call manager.
4. Call the
   [NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily) function to close the AF.

The client can complete these actions asynchronously by returning NDIS_STATUS_PENDING. If the client
completes the call asynchronously, it must subsequently call the
[NdisClNotifyCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclnotifycloseaddressfamilycomplete) function when the close operation is complete. If the client
does not return NDIS_STATUS_PENDING, the close operation is complete when
*ProtocolClNotifyCloseAf* returns.

NDIS calls
*ProtocolClNotifyCloseAf* at IRQL
<= DISPATCH_LEVEL.

The client may use the
*NdisAfHandle* while the AF is open or while a
*ProtocolClNotifyCloseAf* operation is pending. If the
*ProtocolClNotifyCloseAf* function returns NDIS_STATUS_PENDING, use the handle in the
[NdisClNotifyCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclnotifycloseaddressfamilycomplete) call after the close operation completes.

### Examples

To define a *ProtocolClNotifyCloseAf* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClNotifyCloseAf* function that is named "MyClNotifyCloseAf", use the **PROTOCOL_CL_NOTIFY_CLOSE_AF** type as shown in this code example:

```
PROTOCOL_CL_NOTIFY_CLOSE_AF MyClNotifyCloseAf;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyClNotifyCloseAf(
    NDIS_HANDLE  ProtocolAfContext
    )
  {...}
```

The **PROTOCOL_CL_NOTIFY_CLOSE_AF** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_NOTIFY_CLOSE_AF** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclcloseaddressfamily)

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClDeregisterSap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclderegistersap)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClNotifyCloseAddressFamilyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclnotifycloseaddressfamilycomplete)

[NdisClOpenAddressFamilyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclopenaddressfamilyex)