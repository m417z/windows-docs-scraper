# PIBIO_ENGINE_SET_ACCOUNT_POLICY_FN callback function

## Description

Called by the Windows Biometric Framework to set the extended default and per-user antispoofing policies used by the engine adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `PolicyItemArray` [in]

Address of an array of [WINBIO_ACCOUNT_POLICY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-account-policy) structures, which the routine should use to update the policies it is applying to any identities it detects.

### `PolicyItemCount` [in]

The number of elements in the array pointed to by the *PolicyItemArray* parameter.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_some_error** | Errors return by the method are logged but ignored. |

## Remarks

This method is called each time the biometric unit is activated.

This method executes in the context of the same thread that activated the biometric unit and that processed all other requests for the unit.

The Identity.Type field of the first element in the *PolicyItemArray* will always be **WINBIO_ID_TYPE_WILDCARD**. This indicates that the policy item contains a default AntiSpoofBehavior value which should be applied to any user account that isn’t explicitly listed in the rest of the array.

If the *PolicyItemArray* contains more than one element, the Identity.Type field of the remaining items will be **WINBIO_ID_TYPE_WILDCARD**, and the Identity.Value.AccountSid.Data field will contain the SID of a user account that requires the antispoof policy behavior specified in the AntiSpoofBehavior field of the array element.