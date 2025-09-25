# IEnhancedStorageACT::Authorize

## Description

Associates the Addressable Command Target (ACT) with the **Authorized** state defined by [ACT_AUTHORIZATION_STATE](https://learn.microsoft.com/windows/desktop/api/ehstorapi/ns-ehstorapi-act_authorization_state), and ensures the authentication of each individual silo according to the required sequence and logical combination necessary to authorize access to the ACT.

## Parameters

### `hwndParent` [in]

Not used.

### `dwFlags` [in]

Not used.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Authorization completed successfully. |
| **E_FAIL** | The authorization operation has failed. |

## Remarks

This interface method can be used when an application wants to change the ACT to the 'Authorized' state.

## See also

[IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact)