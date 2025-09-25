# KeyCredentialManagerFreeInformation function

## Description

API to free the [KeyCredentialManagerInfo](https://learn.microsoft.com/windows/win32/api/keycredmgr/ns-keycredmgr-keycredentialmanagerinfo) pointer variable from the [KeyCredentialManagerGetInformation](https://learn.microsoft.com/windows/win32/api/keycredmgr/nf-keycredmgr-keycredentialmanagergetinformation) call.

## Parameters

### `keyCredentialManagerInfo` [in]

Pointer variable to [KeyCredentialManagerInfo](https://learn.microsoft.com/windows/win32/api/keycredmgr/ns-keycredmgr-keycredentialmanagerinfo) data structure returned by the [KeyCredentialManagerGetInformation](https://learn.microsoft.com/windows/win32/api/keycredmgr/nf-keycredmgr-keycredentialmanagergetinformation) API.