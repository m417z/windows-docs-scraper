# CfExecute function

## Description

The main entry point for all connection key based placeholder operations. It is intended to be used by a sync provider to respond to various callbacks from the platform.

## Parameters

### `OpInfo` [in]

Information about an operation on a placeholder.

### `OpParams` [in, out]

Parameters of an operation on a placeholder.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

A valid call to **CfExecute** will reset the timers of all pending callback requests that belong to the same sync provider process.

**CfExecute** takes two variable-sized arguments, i.e., [CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info) and [CF_OPERATION_PARAMETERS](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_parameters), with one identifying the operation type and the other supplying detailed operation parameters.
Both arguments start with a **StructSize** field at the beginning of the corresponding structures. Callers of **CfExecute** are responsible for accurate accounting of the structure size.

The platform provides **ConnectionKey**, **TransferKey**, and **CorrelationVector** to all callback functions registered with [CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot). Additionally, sync providers can obtain **TransferKey** using **CfGetTransferKey** and **CorrelationVector** using [CfGetCorrelationVector](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetcorrelationvector).

Optionally, sync providers can supply a sync status blob to the platform. If a non-null pointer is set in the **SyncStatus** field in **CF_OPERATION_INFO**, its content will be retained on the file until the last handle on it is removed. The platform will query this information upon any failed operations on a cloud file placeholder. If one is available, the platform will use the information provided to construct a more meaningful and actionable message to the user.

If a null pointer is set in the **SyncStatus** field in **CF_OPERATION_INFO**, the platform will clear the previously set sync status (if one exists).

All operations can be performed in an arbitrary thread context in the sync provider process.

## See also

[CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot)

[CfGetCorrelationVector](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetcorrelationvector)

[CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info)

[CF_OPERATION_PARAMETERS](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_parameters)