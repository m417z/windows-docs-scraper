# ITsSbTaskPluginNotifySink::OnUpdateTaskStatus

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that the status of a task has changed.

## Parameters

### `szTargetName` [in]

The name of the target.

### `TaskIdentifier` [in]

The GUID that identifies the task.

### `TaskStatus` [in]

An [RDV_TASK_STATUS](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ne-sessdirpublictypes-rdv_task_status) enumeration value representing the new state of the task.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbTaskPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskpluginnotifysink)