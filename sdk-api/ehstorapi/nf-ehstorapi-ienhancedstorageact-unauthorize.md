# IEnhancedStorageACT::Unauthorize

## Description

Associates the Addressable Command Target (ACT) with the **Unauthorized** state defined by [ACT_AUTHORIZATION_STATE](https://learn.microsoft.com/windows/desktop/api/ehstorapi/ns-ehstorapi-act_authorization_state), and ensures the deauthentication of each individual silo according to the required sequence and logical combination necessary to restrict access to the ACT.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Unauthorization completed successfully. |

## See also

[IEnhancedStorageACT](https://learn.microsoft.com/previous-versions/windows/desktop/api/ehstorapi/nn-ehstorapi-ienhancedstorageact)