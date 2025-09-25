# ITsSbTaskPluginNotifySink::OnSetTaskTime

## Description

Notifies Remote Desktop Connection Broker (RD Connection Broker) that a task has been scheduled.

## Parameters

### `szTargetName` [in]

The name of the target.

### `TaskStartTime` [in]

A **FILETIME** structure specifying the start time (UTC).

### `TaskEndTime` [in]

A **FILETIME** structure specifying the end time (UTC).

### `TaskDeadline` [in]

A **FILETIME** structure specifying the deadline (UTC).

### `szTaskLabel` [in]

A label describing the purpose of the task.

### `szTaskIdentifier` [in]

Identifies the target.

### `szTaskPlugin` [in]

The display name of the task agent.

### `dwTaskStatus` [in]

An [RDV_TASK_STATUS](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ne-sessdirpublictypes-rdv_task_status) enumeration value that represents the state of the task.

### `saContext` [in]

The context bytes associated with the task.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbTaskPluginNotifySink](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskpluginnotifysink)