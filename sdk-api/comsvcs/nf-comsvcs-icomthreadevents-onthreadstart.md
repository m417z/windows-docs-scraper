# IComThreadEvents::OnThreadStart

## Description

Generated when a single-threaded apartment (STA) thread is started.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `ThreadID` [in]

The unique thread identifier.

### `dwThread` [in]

The Windows thread identifier.

### `dwTheadCnt` [in]

The number of threads in the STA thread pool.

## Return value

The user verifies the return values from this method.

## See also

[IComThreadEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomthreadevents)