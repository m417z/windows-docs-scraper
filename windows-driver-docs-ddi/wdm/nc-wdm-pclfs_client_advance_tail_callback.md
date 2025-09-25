# PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK callback function

## Description

The *ClfsAdvanceTailCallback* function advances the base log sequence number (LSN) of the client's log.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log stream whose tail should be advanced.

### `TargetLsn` [in]

A pointer to a [CLFS_LSN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_lsn) structure that contains the LSN that the client should advance its tail to or beyond.

### `ClientData` [in]

A pointer to client-supplied information. You specify this data in the **AdvanceTailCallbackData** member of the [CLFS_MGMT_CLIENT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_client_registration) structure.

## Return value

The *ClfsAdvanceTailCallback* function should return either STATUS_PENDING or an error status. A return value of STATUS_PENDING indicates that the request to move the client's log tail will be completed asynchronously. The **ClfsMgmtAdvanceTailCallback** function must not return STATUS_SUCCESS, even if it completes synchronously.

## Remarks

The *ClfsAdvanceTailCallback* function is called when CLFS management requests that the client advance its log tail.

The *ClfsAdvanceTailCallback* function must only perform a minimal amount of processing before returning. For example, the *ClfsAdvanceTailCallback* function might follow this procedure:

1. If the request cannot be processed, return an error status.
2. If the request can be processed, create and queue a work item to perform the actions that are required to move the client's tail, and then return STATUS_PENDING. For more information on queuing a worker thread, see [System Worker Threads](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-worker-threads).

When a client calls the [ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient) routine to register with CLFS management, the client provides both a pointer to the *ClfsAdvanceTailCallback* function and the custom data that will be passed as a parameter to the *ClfsAdvanceTailCallback* function when this function is called.

## See also

[CLFS_MGMT_CLIENT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_client_registration)

[ClfsAdvanceLogBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsadvancelogbase)

[ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient)

[ClfsMgmtTailAdvanceFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmttailadvancefailure)