# IFhConfigMgr::SetLocalPolicy

## Description

Changes the numeric parameter value of a local policy in an [FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr) object.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `LocalPolicyType` [in]

Specifies the local policy.

### `PolicyValue` [in]

Specifies the new value of the numeric parameter for the specified local policy.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

Each local policy contains a numeric parameter that specifies how or when the File History feature backs up files and folders. See the [FH_LOCAL_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_local_policy_type) enumeration for more information about the local policies that can be specified.

To retrieve the numeric parameter value for a local policy, use the [IFhConfigMgr::GetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getlocalpolicy) method.

## See also

[FH_LOCAL_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_local_policy_type)

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::GetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getlocalpolicy)