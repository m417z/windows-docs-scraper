# IComExceptionEvents::OnExceptionUser

## Description

Generated for transactional components when an unhandled exception occurs in the user's code.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `code` [in]

The exception code.

### `address` [in]

The address of the exception.

### `pszStackTrace` [in]

The stack trace.

## Return value

The user verifies the return values from this method.

## See also

[IComExceptionEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomexceptionevents)