# IComApp2Events::OnAppActivation2

## Description

Generated when the server application process is loaded.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidApp` [in]

The GUID of the application.

### `guidProcess` [in]

The process ID.

## Return value

The user verifies the return values from this method.

## See also

[IComApp2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomapp2events)