# PROTOCOL_CM_CLOSE_CALL callback function

## Description

The
*ProtocolCmCloseCall* function is a required function that terminates an existing call and releases any
resources that the call manager allocated for the call.

**Note** You must declare the function by using the **PROTOCOL_CM_CLOSE_CALL** type.
For more information, see the following Examples section.

## Parameters

### `CallMgrVcContext` [in]

Specifies the handle to a call manager-allocated context area in which the call manager maintains
its per-VC state. This handle was provided to NDIS from the call managers
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call) function.

### `CallMgrPartyContext` [in, optional]

Specifies the handle, if any, to a call manager-allocated context area in which the call manager
maintain information about a party on a multipoint VC. This handle is **NULL** if the call being closed is
not a multipoint call.

### `CloseData` [in, optional]

Pointer to a buffer containing connection-oriented client-specified data that should be sent
across the connection before the call is terminated. This parameter is **NULL** if the underlying network
medium does not support transfers of data when closing a connection.

### `Size` [in, optional]

Specifies the length, in bytes, of the buffer at
*CloseData*, zero if
*CloseData* is **NULL**.

## Return value

*ProtocolCmCloseCall* returns the status of its operation(s) as one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the call manager successfully terminated the call. |
| **NDIS_STATUS_PENDING** | Indicates that the call manager will complete the request to terminate the call asynchronously. When the call manager has completed all operations required to terminate the connection, it must then call [NdisCmCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmclosecallcomplete) to signal NDIS that the call has been closed. |
| **NDIS_STATUS_INVALID_DATA** | Indicates that *CloseData* was specified, but the underlying network medium does not support sending data concurrent with terminating a call. |
| **NDIS_STATUS_*XXX*** | Indicates that the call manager could not terminate the call. The actual error returned can be a status propagated from another NDIS library routine. |

## Remarks

*ProtocolCmCloseCall* communicated with network control devices or other media-specific actors, as
necessitated by its media, to terminate a connection between the local node and a remote node. If the
call manager is required to communicate with network control devices (such as a networking switch) it
should use a virtual connection to the network control device that it established in its
*ProtocolBindAdapterEx* function. Stand-alone call managers communicate to such network devices by
calling
[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists).
Miniport drivers with integrated call-management support never call
**NdisCoSendNetBufferLists**. Instead, they transmit the data directly across the network.

If
*CloseData* is non-**NULL** and sending data at connection termination is supported by the media that
this call manager handles, the call manager should transmit the data specified at
*CloseData* to the remote node before completing the call termination. If sending data concurrent
with a connection being terminated is not supported, call managers should return
NDIS_STATUS_INVALID_DATA.

If
*ProtocolCmCloseCall* is passed an explicit
*CallMgrPartyContext*, then the call being terminated is a multipoint VC, and the call manager must
perform any necessary network communication with its networking hardware, as appropriate to its media
type, to terminate the call as a multipoint call. The call manager must also free the memory that it
allocated earlier, in
[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call), for its
per-party state that is pointed to by
*CallMgrPartyContext* . Failure to properly release, deallocate, or otherwise deactivate those
resources causes a memory leak.

After the call has been terminated with the network, any close data has been sent, and any resources
at
*CallMgrPartyContext* have been freed, the call manager must call
[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc). This notifies NDIS
and the underlying miniport driver, if any, to expect no further transfers on the given VC.

### Examples

To define a *ProtocolCmCloseCall* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCmCloseCall* function that is named "MyCmCloseCall", use the **PROTOCOL_CM_CLOSE_CALL** type as shown in this code example:

```
PROTOCOL_CM_CLOSE_CALL MyCmCloseCall;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCmCloseCall(
    NDIS_HANDLE  CallMgrVcContext,
    NDIS_HANDLE  CallMgrPartyContext,
    PVOID  CloseData,
    UINT  Size
    )
  {...}
```

The **PROTOCOL_CM_CLOSE_CALL** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CM_CLOSE_CALL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdeactivatevc)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)