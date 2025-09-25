# IComQCEvents::OnQCMoveToDeadQueue

## Description

Generated when a message is moved to the dead letter queue and cannot be delivered.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidMsgId` [in]

The unique identifier for the message.

### `guidWorkFlowId` [in]

This parameter is reserved.

## Return value

The user verifies the return values from this method.

## See also

[IComQCEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomqcevents)