# StgSetTimes function

## Description

The **StgSetTimes** function sets the creation, access, and modification times of the indicated file, if supported by the underlying file system.

## Parameters

### `lpszName` [in]

Pointer to the name of the file to be changed.

### `pctime` [in]

Pointer to the new value for the creation time.

### `patime` [in]

Pointer to the new value for the access time.

### `pmtime` [in]

Pointer to the new value for the modification time.

## Return value

The **StgSetTimes** function can also return any file system errors or system errors wrapped in an **HRESULT**. See
[Error Handling Strategies](https://learn.microsoft.com/windows/desktop/com/error-handling-strategies) and
[Handling Unknown Errors](https://learn.microsoft.com/windows/desktop/com/handling-unknown-errors).

## Remarks

The
**StgSetTimes** function sets the time values for the specified file. Each of the time value parameters can be **NULL**, indicating that no modification should occur.

It is possible that one or more of these time values are not supported by the underlying file system. This function sets the times that can be set and ignores the rest.