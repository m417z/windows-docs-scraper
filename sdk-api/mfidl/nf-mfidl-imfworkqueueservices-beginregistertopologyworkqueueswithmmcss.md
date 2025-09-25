# IMFWorkQueueServices::BeginRegisterTopologyWorkQueuesWithMMCSS

## Description

Registers the topology work queues with the Multimedia Class Scheduler Service (MMCSS).

## Parameters

### `pCallback` [in]

A pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pState` [in]

A pointer to the **IUnknown** interface of a state object defined by the caller. This parameter can be **NULL**. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each source node in the topology defines one branch of the topology. The branch includes every topology node that receives data from that node. An application can assign each branch of a topology its own work queue and then associate those work queues with MMCSS tasks.

To use this method, perform the following steps.

1. Create the topology.
2. Set the following attributes on the source nodes in the topology.
   * [MF_TOPONODE_WORKQUEUE_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-workqueue-id-attribute). Specifies an identifier for the work queue.
     The Media Session will allocate a new work queue.
   * [MF_TOPONODE_WORKQUEUE_MMCSS_CLASS](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-workqueue-mmcss-class-attribute). Specifies the MMCSS class.
   * [MF_TOPONODE_WORKQUEUE_MMCSS_TASKID](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-workqueue-mmcss-taskid-attribute). Specifies the MMCSS task identifier (optional). If this attribute is not set, MMCSS assigns a new task identifier.
3. Queue the topology by calling [IMFMediaSession::SetTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-settopology).
4. Wait for the [MESessionTopologyStatus](https://learn.microsoft.com/windows/desktop/medfound/mesessiontopologystatus) event with the **MF_TOPOSTATUS_READY** status.
5. Call **BeginRegisterTopologyWorkQueuesWithMMCSS**. This method registers all of the topology work queues with MMCSS.

The **BeginRegisterTopologyWorkQueuesWithMMCSS** method is asynchronous. When the operation completes, the callback object's [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method is called. Within the callback method, call [IMFWorkQueueServices::EndRegisterTopologyWorkQueuesWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-endregistertopologyworkqueueswithmmcss) to complete the asynchronous request. After this operation completes, the Media Session automatically registers the work queues for every new topology that is queued on the Media Session. The application does not need to call the method again for new topologies.

To unregister the topology work queues from MMCSS, call [IMFWorkQueueServices::BeginUnregisterTopologyWorkQueuesWithMMCSS](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfworkqueueservices-beginunregistertopologyworkqueueswithmmcss).

## See also

[IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices)