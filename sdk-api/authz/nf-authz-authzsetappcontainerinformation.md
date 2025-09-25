# AuthzSetAppContainerInformation function

## Description

The **AuthzSetAppContainerInformation** function sets the app container and capability information in a current Authz context. If the passed in context already has an app container [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) set or if the passed in context is not a valid app container SID, this function fails.

## Parameters

### `hAuthzClientContext` [in]

 The handle to the client context to which the given app container SID and capability SIDs will be added.

### `pAppContainerSid` [in]

The app container SID.

### `CapabilityCount` [in]

The number of capability SIDs to be added. This value can be zero if no capability is to be added.

### `pCapabilitySids` [in, optional]

The capability SIDs to be added to the context. This value must be **NULL** when the *CapabilityCount* parameter is zero.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).