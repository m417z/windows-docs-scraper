# IComQCEvents::OnQCQueueOpen

## Description

Generated when a queued components queue is opened. This method is used to generate the *QueueID* parameter.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `szQueue` [in]

The name of the queue.

### `QueueID` [in]

The unique identifier for the queue.

### `hr` [in]

The status from Message Queuing queue open.

## Return value

The user verifies the return values from this method.

## See also

[IComQCEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomqcevents)