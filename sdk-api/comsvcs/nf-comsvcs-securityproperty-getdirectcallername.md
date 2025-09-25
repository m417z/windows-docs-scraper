# SecurityProperty::GetDirectCallerName

## Description

Retrieves the user name associated with the external process that called the currently executing method.

## Parameters

### `bstrUserName` [out]

A reference to the user name associated with the external process that called the currently executing method.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The following scenarios illustrate the functionality of this method:

* A base process, running on server A as user A, calls into object X on server B, running as user B. Then object X calls into object Y, running on server C. If object Y calls **GetDirectCallerName**, the name of user B is retrieved.
* A base process, running on server A as user A, calls into object X on server B, running as user B. Then object X calls into object Y, running in the same process as object X, also on server B. When object Y calls **GetDirectCallerName**, the name of user A is returned, not the name of user B.

## See also

[SecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-securityproperty)