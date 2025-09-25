# IComActivityEvents::OnActivityTimeout

## Description

Generated when a call into an activity times out.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidCurrent` [in]

The GUID associated with the current activity.

### `guidEntered` [in]

The causality identifier for the caller.

### `dwThread` [in]

The identifier of the thread executing the call.

### `dwTimeout` [in]

The time-out period.

## Return value

The user verifies the return values from this method.

## See also

[IComActivityEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomactivityevents)