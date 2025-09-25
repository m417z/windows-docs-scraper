# IFhConfigMgr::GetLocalPolicy

## Description

Retrieves the numeric parameter for a local policy for the File History feature.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `LocalPolicyType` [in]

Specifies the local policy.

### `PolicyValue` [out]

Receives the value of the numeric parameter for the specified local policy.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** value on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

Each local policy contains a numeric parameter that specifies how or when the File History feature backs up files and folders. See the [FH_LOCAL_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_local_policy_type) enumeration for more information about the local policies that can be specified.

To set the numeric parameter value for a local policy, use the [IFhConfigMgr::SetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setlocalpolicy) method.

## See also

[FH_LOCAL_POLICY_TYPE](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_local_policy_type)

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)

[IFhConfigMgr::SetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setlocalpolicy)