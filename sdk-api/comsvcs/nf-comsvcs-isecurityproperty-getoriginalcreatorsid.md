# ISecurityProperty::GetOriginalCreatorSID

## Description

In MTS 2.0, this method retrieves the security identifier of the base process that initiated the activity in which the current object is executing. Do not use this method in COM+.

## Parameters

### `pSID` [out]

A reference to the security ID of the base process that initiated the activity in which the current object is executing.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The security ID of the original created is returned in the parameter *pSid*. |
| **CONTEXT_E_NOCONTEXT** | The current object does not have a context associated with it because either the component was not imported into an application or the object was not created with one of the COM+ CreateInstance methods. |

## See also

[IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext)

[ISecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isecurityproperty)