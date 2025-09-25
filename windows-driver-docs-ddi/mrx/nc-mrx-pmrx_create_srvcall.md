# PMRX_CREATE_SRVCALL callback function

## Description

The **MRxCreateSrvCall** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that the network mini-redirector create an SRV_CALL structure and establish connection with a server.

## Parameters

### `SrvCall`

[in, out] A pointer to the SRV_CALL structure to be created.

### `SrvCallCallBackContext`

[in, out] A pointer to the callback context used by the network mini-redirector to notify RDBSS when the **MRxCreateSrvCall** request is finally completed. The **SrvCallCallBackContext** parameter points to an MRX_SRVCALLDOWN_STRUCTURE structure that contains the RX_CONTEXT structure for this request, as well as the **Callback** routine that the mini-redirector calls when the **MRxCreateSrvCall** request is finally completed.

## Return value

RDBSS expects **MRxCreateSrvCall** to return STATUS_PENDING on success or failure. This behavior results because RDBSS expects this call to be completed asynchronously. A network mini-redirector should map STATUS_SUCCESS to STATUS_PENDING as a return value for **MRxCreateSrvCall**.

The final completion status is returned in the **SrvCallCallBackContext->Status** member once the call completes and the routine in the **Callback** member in the MRX_SRVCALLDOWN_STRUCTURE structure is called by the network mini-redirector. This member initially contains STATUS_BAD_NETWORK_PATH until the network mini-redirector changes this value on completion.

The **SrvCallCallBackContext->Status** member contains STATUS_SUCCESS on success once the call is completed or one of the following common error codes on failure (although other error codes are possible):

| Return code | Description |
| ----------- | ----------- |
| STATUS_BAD_NETWORK_PATH | The network path that was specified is bad. |
| STATUS_NETWORK_UNREACHABLE | The network was unreachable. |

## Remarks

The two important abstractions used in the interface between RDBSS and a network mini-redirector are the SRV_CALL structure and the NET_ROOT structure. An SRV_CALL structure corresponds to the context associated with a server once a connection is established. A NET_ROOT structure corresponds to a share on a server (this could also be viewed as a portion of the namespace that has been claimed by a network mini-redirector).

The creation of an SRV_CALL structure typically involves at least one network round trip. This operation can take considerable time to complete because a network connection with a remote resource may need to be established. To ensure that the asynchronous operations continue, the creation of an SRV_CALL structure is modeled as a two-phase activity. Each call down to a network mini-redirector for creating an SRV_CALL structure is accompanied by a call up from the network mini-redirector to RDBSS that specifies the completion status of the request. RDBSS assumes that **MRxCreateSrvCall** will be completed asynchronously. So RDBSS expects **MRxCreateSrvCall** to return STATUS_PENDING. RDBSS will be notified using the callback routine when the call finally completes.

A network mini-redirector implementation of **MRxCreateSrvCall** is expected to return STATUS_PENDING to the initial call. When processing is completed, the network mini-redirector calls the callback routine that is passed in as part of the **SrvCallCallBackContext** parameter to notify RDBSS that the call was completed and to return the completion status. The callback routine that the network mini-redirector calls is specified as the **Callback** member in the MRX_SRVCALLDOWN_STRUCTURE of the **SrvCallCallBackContext** parameter. The final completion status of the call must be stored in the **Status** member of the **SrvCallCallBackContext** parameter.

On success, the network mini-redirector must also store some value in the **RecommunicateContext** member of the **SrvCallCallBackContext**. The value stored in the **RecommunicateContext** member is the value that RDBSS will pass to [**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify) in the **RecommunicateContext** parameter if **MRxCreateSrvCall** was successful. The network mini-redirector must also fill the appropriate data in the **SrvCall** parameter for the SRV_CALL structure that was created. Note that the **SrvCall** parameter passed to **MRxCreateSrvCall** is the same as the **SrvCall** member in the MRX_SRVCALLDOWN_STRUCTURE of the **SrvCallCallBackContext** parameter. This same SrvCall parameter is also passed to **MRxSrvCallWinnerNotify** in the **SrvCall** parameter.

The implementation of **MRxCreateSrvCall** in a network mini-redirector is also complicated by the need for transport handles. Certain transport-related interfaces require a handle to be created and used for all communication. Creating an SRV_CALL structure may require establishing transport-related handles for network communications. Because the process of establishing a network connection can be time consuming, once a connection is established it makes sense to use the connection for communication as long as possible. Once a transport handle to a remote network resource is established, it can be reused by any number of other application requests. When a user application terminates, the handles associated with the process are deleted. For this reason, establishing transport handles in the context of a transient user-mode process that could be short-lived does not make sense. So an SRV_CALL structure normally needs to be initialized in the context of a well known process that will not disappear while these transport handles are being used for communication.

One method used to work around the potential problems with transport handles is to have the RDBSS system process allocate the transport handles. This affects how the **MRxCreateSrvCall** routine is executed. If the request to **MRxCreateSrvCall** was issued in the context of the RDBSS system process, then this call can be executed immediately and does not need to be posted to a work queue. However, in order to avoid problems, if the request to **MRxCreateSrvCall** is from any other process, the request would be posted to a system work queue using [**RxDispatchToWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread) for later execution. RDBSS will later use one of its system threads to process the work queue request and execute **MRxCreateSrvCall**. This ensures that any transport handles will be owned by a system process.

A network mini-redirector can determine if a call to **MRxCreateSrvCall** was received directly from RDBSS by calling [**RxGetRDBSSProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxstruc/nf-rxstruc-rxgetrdbssprocess). **RxGetRDBSSProcess** will return the RDBBS process and this value can be compared with the current process returned using [**IoGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess). If the call to **MRxCreateSrvCall** was not initiated in the context of the RDBSS system process, then **MRxCreateSrvCall** can return STATUS_PENDING and post the call to a work queue using [**RxDispatchToWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread)for later execution by RDBSS. Normally, these calls would be posted to the [**DelayedWorkQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_work_queue_type).

It is up to the developer of the network mini-redirector to decide how **MRxCreateSrvCall** is implemented. If the process to create a SRV_CALL can take a considerable amount of time, then **MRxCreateSrvCall** should be completed asynchronously. If transport handles are needed, then the network mini-redirector needs to find a system process that is long-lived to establish these handles.

When this call completes, the **SrvCall** parameter should be modified with the SRV_CALL structure information updated from the network mini-redirector.

A network mini-redirector that indicates support as a UNC provider will receive a prefix claim from the Multiple UNC Provider (MUP) as a call to **MRxCreateSrvCall**. For more information about UNC Naming and MUP, see [Support for UNC Naming and MUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/support-for-unc-naming-and-mup).

## See also

[**IoGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess)

[**MRxCreateVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_v_net_root)

[**MRxExtractNetRootName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extract_netroot_name)

[**MRxFinalizeNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_net_root_calldown)

[**MRxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_srvcall_calldown)

[**MRxFinalizeVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

[**MRxPreparseName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_preparse_name)

[**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify)

[**RxDispatchToWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread)

[**RxGetRDBSSProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxstruc/nf-rxstruc-rxgetrdbssprocess)