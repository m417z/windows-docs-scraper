# ITsSbTaskPluginNotifySink::OnDeleteTaskTime

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that a task has been removed from the queue.

## Parameters

### `szTargetName` [in]

The name of the target.

### `szTaskIdentifier` [in]

The GUID that identifies the task.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbTaskPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskpluginnotifysink)