# IComActivityEvents::OnActivityEnter

## Description

Generated when an activity thread is entered.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidCurrent` [in]

The GUID associated with the caller.

### `guidEntered` [in]

The GUID associated with the activity thread entered.

### `dwThread` [in]

The identifier of the activity thread.

## Return value

The user verifies the return values from this method.

## See also

[IComActivityEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomactivityevents)