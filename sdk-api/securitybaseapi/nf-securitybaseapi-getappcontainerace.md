# GetAppContainerAce function (securitybaseapi.h)

## Description

Retrieves a value that indicates whether a package or capability SID is present.

## Parameters

### `Acl` [in]

A pointer to an [ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl) structure.

### `StartingAceIndex` [in]

Specifies the position in the ACL's list of ACEs at which to add new ACEs. A value of zero inserts the ACEs at the beginning of the list. A value of MAXDWORD appends the ACEs to the end of the list.

### `AppContainerAce` [out]

Pointer to an AppContainerAce object.

### `AppContainerAceIndex` [out, optional]

The position in the ACL's list of ACEs.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the error codes defined in WinError.h.

## Remarks

## See also