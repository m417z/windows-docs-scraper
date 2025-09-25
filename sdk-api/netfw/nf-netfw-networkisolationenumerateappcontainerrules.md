# NetworkIsolationEnumerateAppContainerRules function

## Description

The **NetworkIsolationEnumerateAppContainerRules** function enumerates all of the rules related to app containers.

## Parameters

### `newEnum` [out]

Type: **IEnumVARIANT****

Enumerator interface of an [INetFwRule3](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwrule3) object that represents the rules enforcing app containers.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.