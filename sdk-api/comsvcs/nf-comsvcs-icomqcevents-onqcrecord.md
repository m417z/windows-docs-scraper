# IComQCEvents::OnQCRecord

## Description

Generated when the queued components recorder creates the queued message.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `objid` [in]

The just-in-time activated object.

### `szQueue` [in]

The name of the queue.

### `guidMsgId` [in]

The unique identifier for the queued message.

### `guidWorkFlowId` [in]

This parameter is reserved.

### `msmqhr` [in]

The Message Queuing return status for the queued message.

## Return value

The user verifies the return values from this method.

## See also

[IComQCEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomqcevents)