# AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA structure

## Description

The **AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA** structure contains time stamp policy information that can be used in certificate chain verification of files.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwRegPolicySettings`

Flag set during installation that can be modified by a user. The SetReg tool found in the Authenticode Tool Pack can be used to select or cancel the selection of each value. Flag values can be combined using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **WTPF_TRUSTTEST** | Trust any "TEST" certificate. |
| **WTPF_TESTCANBEVALID** | Check any "TEST" certificate for validity. |
| **WTPF_IGNOREEXPIRATION** | Use expiration date. |
| **WTPF_IGNOREREVOKATION** | Do revocation check. |
| **WTPF_OFFLINEOK_IND** | If the source is offline, trust any individual certificates. |
| **WTPF_OFFLINEOK_COM** | If the source is offline, trust any commercial certificates. |
| **WTPF_OFFLINEOKNBU_IND** | If the source is offline, trust any individual certificates. Do not use UI. |
| **WTPF_OFFLINEOKNBU_COM** | If the source is offline, trust any commercial certificates. Do not use checking UI. |
| **WTPF_VERIFY_V1_OFF** | Turn off verification of v1 certificates. |
| **WTPF_IGNOREREVOCATIONONTS** | Ignore time stamp revocation checks. |
| **WTPF_ALLOWONLYPERTRUST** | Allow only items in personal trust database. |

### `fCommercial`

BOOL flag. If **TRUE**, a signer has been verified by a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) as meeting certain minimum financial standards.