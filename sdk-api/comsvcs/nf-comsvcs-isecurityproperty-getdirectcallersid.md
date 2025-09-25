# ISecurityProperty::GetDirectCallerSID

## Description

Retrieves the security identifier of the external process that called the currently executing method.
You can also obtain this information using [ISecurityCallContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecuritycallcontext).

## Parameters

### `pSID` [out]

A reference to the security ID of the process from which the current method was invoked.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The security ID of the process that called the current method is returned in the parameter *pSid*. |
| **CONTEXT_E_NOCONTEXT** | The current object does not have a context associated with it because either the component was not imported into an application or the object was not created with one of the COM+ CreateInstance methods. |

## Remarks

Use the **GetDirectCallerSID** method to determine the security ID of the process that called the object's currently executing method. Security is enforced across process boundaries. This means that the security ID returned by **GetDirectCallerSID** is the security ID associated with the process that called into the process in which the current object is running, not necessarily the immediate caller into the object itself. If an object calls into another object within the same process, when the second object calls **GetDirectCallerSID** it gets the security ID of the most immediate caller outside its own process boundary, not the security ID of the object that directly called into it.

The following scenarios illustrate the functionality of the **GetDirectCallerSID** method:

* A base process running on Server A, as user A, calls into Object X on Server B, running as user B. Then Object X calls into Object Y, running on Server C. If Object Y calls **GetDirectCallerSID**, the security ID of user B is returned.
* A base process, running on Server A as user A, calls into Object X on Server B, running as user B. Then Object X calls into Object Y, running in the same process as Object X, also on Server B. When Object Y calls **GetDirectCallerSID**, the security ID of user A is returned, not the security ID of user B.

You must call [ISecurityProperty::ReleaseSID](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-isecurityproperty-releasesid) on a security ID when you finish using it.

## See also

[ISecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecurityproperty)