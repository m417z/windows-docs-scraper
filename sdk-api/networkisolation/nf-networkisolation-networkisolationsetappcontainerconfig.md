# NetworkIsolationSetAppContainerConfig function

## Description

The **NetworkIsolationSetAppContainerConfig** function is used to set the configuration of one or more app containers.

## Parameters

### `dwNumPublicAppCs` [in]

Type: **DWORD**

The number of app containers in the **appContainerSids** member.

### `appContainerSids` [in]

Type: **[PSID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes)**

The security identifiers (SIDs) of app containers that are allowed to send loopback traffic. Used for debugging purposes.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.