# IComQCEvents::OnQCPlayback

## Description

Generated when a messages contents are replayed.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `objid` [in]

The just-in-time activated object.

### `guidMsgId` [in]

The unique identifier for the queue.

### `guidWorkFlowId` [in]

This parameter is reserved.

### `hr` [in]

The status from Message Queuing receive message.

## Return value

The user verifies the return values from this method.

## See also

[IComQCEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomqcevents)