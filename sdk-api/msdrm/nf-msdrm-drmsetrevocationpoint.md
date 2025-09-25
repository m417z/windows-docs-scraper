# DRMSetRevocationPoint function

## Description

[The AD RMS SDK leveraging functionality exposed by

the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or

unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal),

which leverages functionality exposed by the client in Msipc.dll.]

The **DRMSetRevocationPoint** function sets a refresh rate and location to obtain a revocation list.

## Parameters

### `hIssuanceLicense` [in]

A handle to an issuance license.

### `fDelete` [in]

Flag indicating whether the existing item should be deleted: **TRUE** indicates it should be deleted; **FALSE** indicates it should be added.

### `wszId` [in]

ID of the revocation authority posting the revocation list. This must match the ID given in the **ISSUER** node of the revocation list.

### `wszIdType` [in]

Type of ID used by *wszId*.

### `wszURL` [in]

URL of revocation file list.

### `pstFrequency` [in]

How often the list must be updated.

### `wszName` [in]

Optional human-readable name for a revocation list site.

### `wszPublicKey` [in]

Public key of key pair used to sign and verify the revocation list.

## Return value

If the function succeeds, the function returns S_OK.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A revocation list can revoke end-user licenses, server licensor certificates, or almost anything else with an identifying GUID. For a list of the items that can be revoked, see [Revocation](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/revocation). The URL provided should refer to the list file itself. The rights management system handles checking for a valid revocation list. This function should only be called once, since subsequent calls will overwrite the previous revocation point in the issuance license.

The public key must be a base-64 encoded string.

Note that if there is no revocation point set in the license, the license can still be revoked by a revocation list signed by the issuer of the license.

## See also

[AD RMS Functions](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-functions)

[DRMGetRevocationPoint](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmgetrevocationpoint)

[Revoking a Certificate](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/revoking-a-certificate)