# IComThreadEvents::OnThreadUnBind

## Description

Generated when the lifetime of the configured component is over and the activity count on the apartment thread can be decremented.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `ThreadID` [in]

The unique thread identifier.

### `AptID` [in]

The apartment identifier.

### `dwActCnt` [in]

The number of current activities on the apartment thread.

## Return value

The user verifies the return values from this method.

## See also

[IComThreadEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomthreadevents)