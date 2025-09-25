# PROTOCOL_CM_NOTIFY_CLOSE_AF_COMPLETE callback function

## Description

The
*ProtocolCmNotifyCloseAfComplete* function indicates that a client has completed the closing of an
address family (AF) that a stand-alone call manager or miniport call manager (MCM) started by calling the
[NdisCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmnotifycloseaddressfamily) or
[NdisMCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmnotifycloseaddressfamily) function, respectively.

**Note** You must declare the function by using the **PROTOCOL_CM_NOTIFY_CLOSE_AF_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrAfContext` [in]

A handle to the call manager's AF context area that the call manager supplied to NDIS in the
[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af) function.

### `Status` [in]

The clients final status for the AF close notification.
*Status* can be one of the following:

#### NDIS_STATUS_SUCCESS

The client successfully closed its address family.

#### NDIS_STATUS_XXX

The client failed the request for some driver-determined reason.

## Remarks

The
*ProtocolCmNotifyCloseAfComplete* function is required for CoNDIS call managers.

If a stand-alone call manager will unbind from an underlying miniport adapter, the call manager must
call the
[NdisCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmnotifycloseaddressfamily) function before unbinding. When a miniport call manager (MCM) halts
a miniport adapter, the MCM must call the
[NdisMCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmnotifycloseaddressfamily) function.

If
**NdisCmNotifyCloseAddressFamily** or
**NdisMCmNotifyCloseAddressFamily** returns NDIS_STATUS_PENDING, NDIS calls
*ProtocolCmNotifyCloseAfComplete* after the client completes the AF close operation.

NDIS calls
*ProtocolCmNotifyCloseAfComplete* at IRQL <= DISPATCH_LEVEL.

### Examples

To define a *ProtocolCmNotifyCloseAfComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmNotifyCloseAfComplete* function that is named "MyCmNotifyCloseAfComplete", use the **PROTOCOL_CM_NOTIFY_CLOSE_AF_COMPLETE** type as shown in this code example:

```
PROTOCOL_CM_NOTIFY_CLOSE_AF_COMPLETE MyCmNotifyCloseAfComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyCmNotifyCloseAfComplete(
    NDIS_HANDLE  CallMgrAfContext,
    NDIS_STATUS  Status
    )
  {...}
```

The **PROTOCOL_CM_NOTIFY_CLOSE_AF_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_NOTIFY_CLOSE_AF_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmnotifycloseaddressfamily)

[NdisMCmNotifyCloseAddressFamily](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmnotifycloseaddressfamily)

[ProtocolCmOpenAf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_open_af)