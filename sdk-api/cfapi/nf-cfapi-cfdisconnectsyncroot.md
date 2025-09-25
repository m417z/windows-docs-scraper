# CfDisconnectSyncRoot function

## Description

Disconnects a communication channel created by [CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot).

## Parameters

### `ConnectionKey` [in]

The connection key returned from [CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot) that is now used to disconnect the sync root.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

This removes the communication channel with the platform that was previously established using [CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot).

A sync provider can still receive callbacks during the **CfDisconnectSyncRoot** call, and the provider is free to choose whether the call needs to fail or be serviced. Either choice will not cause disruptions to the sync provider.

After a call to **CfDisconnectSyncRoot** returns, the sync provider will no longer receive callbacks and the platform will fail any operation that depends on said callbacks.

A sync provider should have **WRITE_DATA** or **WRITE_DAC** access to the sync root to be disconnected or a call to **CfDisconnectSyncRoot** will be failed with **HRESULT(ERROR_CLOUD_FILE_ACCESS_DENIED)**. Also, if the sync root has not been previously connected, the call will be failed with invalid parameters. This API could be called as part of gracefully shutting down the sync provider. However, if the sync provider process chooses to terminate without calling this API, or unexpectedly crashes, the platform will detect this and perform the necessary cleanup.

## See also

[CfConnectSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconnectsyncroot)