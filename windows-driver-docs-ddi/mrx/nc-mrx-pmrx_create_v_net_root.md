# PMRX_CREATE_V_NET_ROOT callback function

## Description

The **MRxCreateVNetRoot** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that the network mini-redirector create a V_NET_ROOT structure and, in some cases, a NET_ROOT structure.

## Parameters

### `Context`

[in, out] A pointer to the callback context used by the network mini-redirector to notify RDBSS when the call is finally completed. This includes the RX_CONTEXT structure of the request at **Context->RxContext**. The **Context** parameter includes the V_NET_ROOT structure to be constructed at **Context->pVNetRoot**. This V_NET_ROOT structure contains a pointer to the NET_ROOT structure at **pVNetRoot->pNetRoot**. The NET_ROOT structure also contains a pointer to the SRV_CALL structure at **pNetRoot->pSrvCall**.

## Return value

RDBSS expects that **MRxCreateVNetRoot** returns STATUS_PENDING on success or failure. This behavior results because RDBSS expects this call to be completed asynchronously. A network mini-redirector should map STATUS_SUCCESS to STATUS_PENDING as a return value for **MRxCreateVNetRoot**.

The final completion status is returned in **Context->VirtualNetRootStatus** and **Context->NetRootStatus** members once the call completes and the routine in the **Callback** member of **Context** structure is called by the network mini-redirector. These members initially contain STATUS_SUCCESS until the network mini-redirector changes this value on completion. If the call completed successfully, both of the members contain STATUS_SUCCESS.

On failure to create a V_NET_ROOT or NET_ROOT structure, one of the following common error codes for the**VirtualNetRootStatus** or **NetRootStatus** member is returned (although other error codes are possible):

| Return code | Description |
| ----------- | ----------- |
| STATUS_CONNECTION_RESET | The connection to the remote resource was reset. |
| STATUS_IO_TIMEOUT | A time out occurred on an I/O request. |
| STATUS_RETRY | A remote boot server was not ready to satisfy the request. |
| STATUS_UNEXPECTED_NETWORK_ERROR | An unexpected network error occurred usually caused by an invalid handle. |

## Remarks

The two important abstractions used in the interface between RDBSS and a network mini-redirector are the SRV_CALL structure and the NET_ROOT/V_NET_ROOT structure. An SRV_CALL structure corresponds to the context associated with a server with which a connection has been established. A NET_ROOT structure corresponds to a share on a server. A V_NET_ROOT structure could be viewed as a portion of the namespace below a NET_ROOT structure claimed by a network mini-redirector.

The creation of a NET_ROOT/V_NET_ROOT structure typically involves at least one network round trip. This operation can take considerable time to complete because a network connection with a remote resource may need to be established. To ensure that the asynchronous operations continue, the creation of a NET_ROOT/V_NET_ROOT structure is modeled as a two-phase activity. Each call to a network mini-redirector for creating a NET_ROOT/V_NET_ROOT structure is followed by a call back from the network mini-redirector to RDBSS that indicates to RDBSS the completion status of the request to the network mini-redirector. Because RDBSS expects **MRxCreateVNetRoot** is completed asynchronously, RDBSS expects **MRxCreateVNetRoot** to return STATUS_PENDING. RDBSS will be notified using the callback routine when the call finally completes.

**MRxCreateVNetRoot** must deal with two cases of interest:

* A new V_NET_ROOT structure and the associated new NET_ROOT structure are being created.
* A new V_NET_ROOT structure that is associated with an existing NET_ROOT structure is being created.

These two cases can be distinguished by checking if the context associated with a NET_ROOT structure is NULL.

A network mini-redirector implementation of **MRxCreateVNetRoot** is expected to return STATUS_PENDING to initial call. When processing is completed, the network mini-redirector would call the callback routine passed in as part of the **Context** parameter to notify RDBSS that the call was completed and return the completion status. The callback routine that the network mini-redirector should call up to is specified as the **Callback** member in the MRX_CREATENETROOT_CONTEXT structure passed as the **Context** parameter. The final completion status of the **MRxCreateVNetRoot** call must be stored in the **VirtualNetRootStatus** and **NetRootStatus** members of the **Context** parameter. Note that separate status is returned for the NET_ROOT and V_NET_ROOT structures.

The implementation of **MRxCreateVNetRoot** in a network mini-redirector is also complicated by the need for transport handles. Certain transport-related interfaces require a handle to be created and used for all communication. Creating a NET_ROOT or V_NET_ROOT structure may require establishing transport-related handles for network communications. Because the process of establishing a network connection can be time consuming, once a connection is established it makes sense to use the connection for communication as long as possible. Once a transport handle to a remote network resource is established, it can be reused by any number of other application requests. When a user application terminates, the handles associated with the process are deleted. For this reason, establishing transport handles in the context of a transient user-mode process that might be short-lived does not make sense. So a NET_ROOT or V_NET_ROOT structure normally needs to be initialized in the context of a well known process that will not disappear while these transport handles are being used for communication.

One method used to manage this in network mini-redirectors is to have the RDBSS system process allocate these transport handles. This affects how the **MRxCreateVNetRoot** routine is executed. If the request to **MRxCreateVNetRoot** was issued in the context of the RDBSS system process, then this call can be executed immediately and does not need to be posted to a work queue. However, in order to avoid problems, if the request to **MRxCreateVNetRoot** is from any other process, the request would be posted to a system work queue using [**RxDispatchToWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread) for later execution. RDBSS will later use one of its system threads to process the work queue request and execute **MRxCreateVNetRoot**. This ensures that any transport handles will be owned by a system process.

A network mini-redirector can determine if a call to **MRxCreateVNetRoot** was received directly from RDBSS by calling [**RxGetRDBSSProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxstruc/nf-rxstruc-rxgetrdbssprocess). **RxGetRDBSSProcess** returns the RDBBS process and this value can be compared with the current process returned by calling [**IoGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess). If the call to **MRxCreateVNetRoot** was not initiated in the context of the RDBSS system process, then **MRxCreateVNetRoot** can return STATUS_PENDING and post the call to a work queue using [**RxDispatchToWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread) for later execution by RDBSS. Normally, these calls would be posted to the [**DelayedWorkQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_work_queue_type).

It is up to the network mini-redirector to decide how **MRxCreateVNetRoot** is implemented. If this process can take a considerable amount of time, then this call should be completed asynchronously. If transport handles are needed, then the network mini-redirector may want a system process that is long-lived to establish these handles.

In case the connection cannot be established, the network mini-redirector can try to transition the NET_ROOT and V_NET_ROOT structures into a disconnected mode (if this is supported) and establish the connection offline.

When **MRxCreateVNetRoot** completes, the **Context** parameter should be modified with the appropriate NET_ROOT and V_NET_ROOT structure information that is updated from the network mini-redirector.

## See also

[**IoGetCurrentProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentprocess)

[**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall)

[**MRxExtractNetRootName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extract_netroot_name)

[**MRxFinalizeNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_net_root_calldown)

[**MRxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_srvcall_calldown)

[**MRxFinalizeVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

[**MRxPreparseName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_preparse_name)

[**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify)

[**RxDispatchToWorkerThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxworkq/nf-rxworkq-rxdispatchtoworkerthread)

[**RxGetRDBSSProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxstruc/nf-rxstruc-rxgetrdbssprocess)