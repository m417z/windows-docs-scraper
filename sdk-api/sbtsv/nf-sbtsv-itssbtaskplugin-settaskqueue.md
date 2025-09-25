# ITsSbTaskPlugin::SetTaskQueue

## Description

Updates a task in the queue of a Remote Desktop Connection Broker plugin.

## Parameters

### `pszHostName` [in]

### `SbTaskInfoSize` [in]

### `pITsSbTaskInfo` [in]

An array of pointers to [ITsSbTaskInfo](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskinfo) objects.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbTaskPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtaskplugin)