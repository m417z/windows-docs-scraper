# IComQCEvents::OnQCReceiveFail

## Description

Generated when the receive message fails.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `QueueID` [in]

The unique identifier for the queue.

### `msmqhr` [in]

The status from Queued Components processing of the received message.

## Return value

The user verifies the return values from this method.

## See also

[IComQCEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomqcevents)