# IComThreadEvents::OnThreadAssignApartment

## Description

Generated when an activity is assigned to an apartment thread.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidActivity` [in]

The activity identifier for which the object is created.

### `AptID` [in]

The apartment identifier.

## Return value

The user verifies the return values from this method.

## See also

[IComThreadEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomthreadevents)