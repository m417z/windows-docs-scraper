# IComApp2Events::OnAppPaused2

## Description

Generated when the server application is paused or resumed to its initial state.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidApp` [in]

The GUID of the application.

### `bPaused` [in]

**TRUE** if the server application is paused. **FALSE** if the application has resumed to its original state.

## Return value

The user verifies the return values from this method.

## See also

[IComApp2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomapp2events)