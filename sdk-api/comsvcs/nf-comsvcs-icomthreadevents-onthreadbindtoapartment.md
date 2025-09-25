# IComThreadEvents::OnThreadBindToApartment

## Description

Generated when an apartment thread is allocated for a single-thread apartment (STA) thread that does not have an apartment thread to run in. An apartment thread is created or allocated from the pool.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `ThreadID` [in]

The unique thread identifier.

### `AptID` [in]

The apartment identifier.

### `dwActCnt` [in]

The number of activities bound to this apartment.

### `dwLowCnt` [in]

This parameter is reserved.

## Return value

The user verifies the return values from this method.

## See also

[IComThreadEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomthreadevents)