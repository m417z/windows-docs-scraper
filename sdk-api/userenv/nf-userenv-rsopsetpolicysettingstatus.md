# RsopSetPolicySettingStatus function

## Description

The
**RSoPSetPolicySettingStatus** function creates an instance of
[RSOP_PolicySettingStatus](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysettingstatus) and an instance of
[RSOP_PolicySettingLink](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysettinglink). The function links (associates)
**RSOP_PolicySettingStatus** to its
[RSOP_PolicySetting](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysetting) instance.

## Parameters

### `dwFlags` [in]

This parameter is currently unused.

### `pServices` [in]

Specifies a WMI services pointer to the RSoP namespace to which the policy data is to be written. This parameter is required.

### `pSettingInstance` [in]

Pointer to an instance of
[RSOP_PolicySetting](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysetting) containing the policy setting. This parameter is required and can point to the instance's children.

### `nInfo` [in]

Specifies the number of elements in the *pStatus* array.

### `pStatus` [in]

Pointer to an array of
[POLICYSETTINGSTATUSINFO](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-policysettingstatusinfo) structures.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

To unlink an
[RSOP_PolicySettingStatus](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysettingstatus) instance from its
[RSOP_PolicySetting](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/rsop-policysetting) instance, you can call the
[RSoPResetPolicySettingStatus](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopresetpolicysettingstatus) function.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[RSoPResetPolicySettingStatus](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopresetpolicysettingstatus)