# IComSecurityEvents::OnAuthenticate

## Description

Generated when a method call level authentication succeeds. When you set an authentication level for an application, you determine what degree of authentication is performed when clients call into the application.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidActivity` [in]

The identifier of the activity in which the object is created.

### `ObjectID` [in]

The just-in-time activated object.

### `guidIID` [in]

The IID of the method.

### `iMeth` [in]

The v-table index of the method.

### `cbByteOrig` [in]

The number of bytes in the security identifier for the original caller.

### `pSidOriginalUser` [in]

The security identifier for the original caller.

### `cbByteCur` [in]

The number of bytes in the security identifier for the current caller.

### `pSidCurrentUser` [in]

The security identifier for the current caller.

### `bCurrentUserInpersonatingInProc` [in]

Indicates whether the current user is impersonating.

## Return value

The user verifies the return values from this method.

## See also

[IComSecurityEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomsecurityevents)