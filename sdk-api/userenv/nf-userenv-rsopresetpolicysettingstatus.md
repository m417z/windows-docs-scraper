# RsopResetPolicySettingStatus function

## Description

The
**RSoPResetPolicySettingStatus** function unlinks the
[RSOP_PolicySettingStatus](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysettingstatus) instance from its
[RSOP_PolicySetting](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysetting) instance. The function deletes the instances of
**RSOP_PolicySettingStatus** and
[RSOP_PolicySettingLink](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysettinglink). Optionally, you can also specify that the function delete the instance of
**RSOP_PolicySetting**.

## Parameters

### `dwFlags` [in]

This parameter is currently unused.

### `pServices` [in]

Specifies a WMI services pointer to the RSoP namespace to which the policy data is to be written. This parameter is required.

### `pSettingInstance` [in]

Pointer to an instance of
[RSOP_PolicySetting](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysetting) containing the policy setting. This parameter is required and can also point to the instance's children.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To link (associate) the
[RSOP_PolicySettingStatus](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysettingstatus) instance to its
[RSOP_PolicySetting](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysetting) instance, you can call the
[RSoPSetPolicySettingStatus](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopsetpolicysettingstatus) function.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[RSoPSetPolicySettingStatus](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopsetpolicysettingstatus)