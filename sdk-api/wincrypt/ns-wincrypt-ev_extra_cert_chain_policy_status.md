# EV_EXTRA_CERT_CHAIN_POLICY_STATUS structure

## Description

The **EV_EXTRA_CERT_CHAIN_POLICY_STATUS** structure is returned in the **pvExtraPolicyStatus** member of a [CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_policy_status) structure. The structure contains policy flags returned from a call to the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwQualifiers`

### `dwIssuanceUsageIndex`

A **DWORD** value that specifies an index in the array of the resultant set of policy OIDs for the chain. The index corresponds to the EV policy OID for which the chain is valid. The policy OID is retrieved by using
the index, as shown in the following pseudocode:

`pChainContext->rgpChain[0]->rgpElement[0]->pIssuanceUsage->rgpszUsageIdentifier[dwIssuanceUsageIndex];`

#### - fQualifiers

A **DWORD** value that specifies which of the EV policy qualifiers are set corresponding to the policy [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) for which the chain is valid.

| Value | Meaning |
| --- | --- |
| **CERT_ROOT_PROGRAM_FLAG_ORG**<br><br>0x80 | Validation of the Organization (O) field in the subject name meets Root Program Requirements for display. |
| **CERT_ROOT_PROGRAM_FLAG_LSC**<br><br>0x40 | Validation of the Locale (L), State (S), and Country (C) fields in the subject name meets Program Requirements for display. |
| **CERT_ROOT_PROGRAM_FLAG_SUBJECT_LOGO**<br><br>0x20 | Validation of the Subject logotype meets Program Requirements for display. |