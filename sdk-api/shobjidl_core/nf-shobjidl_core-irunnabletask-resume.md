# IRunnableTask::Resume

## Description

Requests that a task resume.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or standard COM-defined error codes otherwise.

## Remarks

Implementation of this method is optional. If you do not wish to support this functionality, create a token implementation that simply returns E_NOTIMPL.