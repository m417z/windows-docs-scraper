# IObjectContextInfo::GetActivityId

## Description

Retrieves the identifier of the current activity.

## Parameters

### `pGUID` [out]

A GUID that identifies the current activity.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

If the object is not running within a synchronization domain, COM+ returns a GUID_NULL, which consists of all zeros.

## See also

[COM+ Contexts and Threading Models](https://learn.microsoft.com/windows/desktop/cossdk/com--contexts-and-threading-models)

[IObjectContextInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontextinfo)