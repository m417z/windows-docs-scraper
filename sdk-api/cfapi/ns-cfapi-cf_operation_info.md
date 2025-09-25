# CF_OPERATION_INFO structure

## Description

Information about an operation on a placeholder file or folder.

## Members

### `StructSize`

The size of the **CF_OPERATION_INFO** structure.

### `Type`

The type of operation being performed. See [CF_OPERATION_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_operation_type) for more information.

### `ConnectionKey`

A connection key obtained for the communication channel.

### `TransferKey`

An opaque handle to the placeholder.

### `CorrelationVector`

A correlation vector on a placeholder used for telemetry purposes.

### `SyncStatus`

>[!NOTE]
>This member is new for Windows 10, version 1803.

The current [CF_SYNC_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_sync_status) of the platform.

The platform queries this information upon any failed operations on a cloud file placeholder. If a structure is available, the platform will use the information provided to construct a more meaningful and actionable message to the user. The platform will keep this information on the file until the last handle on it goes away. If *SyncStatus* is **null**, the platform will clear the previously set sync status, if there is one.

### `RequestKey`

An opaque id that uniquely identifies a cloud file operation on a particular cloud file.

## Remarks

The platform provides the *ConnectionKey*, *TransferKey*, and *CorrelationVector* to all callback functions registered via [CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot). Additionally, sync providers can obtain a *TransferKey* using [CfGetTransferKey](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgettransferkey) and a *CorrelationVector* using [CfGetCorrelationVector](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetcorrelationvector).

## See also

[CF_OPERATION_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_operation_type)

[CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot)

[CfGetTransferKey](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgettransferkey)

[CfGetCorrelationVector](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetcorrelationvector)

[CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute)

[CF_SYNC_STATUS](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_sync_status)