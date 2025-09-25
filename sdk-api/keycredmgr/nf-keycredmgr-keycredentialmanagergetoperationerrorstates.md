# KeyCredentialManagerGetOperationErrorStates function

## Description

Prerequisite API to call to determine if the operation will be successful prior.

## Parameters

### `keyCredentialManagerOperationType` [in]

The intended operation from the [KeyCredentialManagerOperationType](https://learn.microsoft.com/windows/win32/api/keycredmgr/ne-keycredmgr-keycredentialmanageroperationtype).

### `isReady` [out]

If the operational prerequisite will succeed (True) or (False).

### `keyCredentialManagerOperationErrorStates` [out]

Additional feedback about isReady represented by [KeyCredentialManagerOperationErrorStates](https://learn.microsoft.com/windows/win32/api/keycredmgr/ne-keycredmgr-keycredentialmanageroperationerrorstates).

## Return value

Returns an HRESULT.