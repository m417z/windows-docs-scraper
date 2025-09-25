# IEnhancedStorageACT::GetAuthorizationState

## Description

Returns the current authorization state of the ACT.

## Parameters

### `pState` [out]

Pointer to a [ACT_AUTHORIZATION_STATE](https://learn.microsoft.com/windows/desktop/api/ehstorapi/ns-ehstorapi-act_authorization_state) that specifies the current authorization state of the ACT.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The current authorization state was retrieved successfully. |
| **E_INVALIDARG** | *pState* is **NULL**. |

## See also

[IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact)