# IComQCEvents::OnQCReceive

## Description

Generated when a message is successfully de-queued even though the queued components service might find something wrong with the contents.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `QueueID` [in]

The unique identifier for the queue.

### `guidMsgId` [in]

The unique identifier for the queued message.

### `guidWorkFlowId` [in]

This parameter is reserved.

### `hr` [in]

The status from Queued Components processing of the received message.

## Return value

The user verifies the return values from this method.

## See also

[IComQCEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomqcevents)