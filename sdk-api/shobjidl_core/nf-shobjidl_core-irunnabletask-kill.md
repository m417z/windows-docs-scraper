# IRunnableTask::Kill

## Description

Requests that a task be stopped.

## Parameters

### `bWait`

Type: **BOOL**

Not currently used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Implementation of this method is optional. If you do not wish to support this functionality, create a token implementation that simply returns E_NOTIMPL.