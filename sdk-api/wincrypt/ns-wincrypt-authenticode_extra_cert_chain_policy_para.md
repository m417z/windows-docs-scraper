# AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA structure

## Description

The **AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA** structure holds policy information used in the verification of certificate chains for files.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwRegPolicySettings`

Flags set during installation that can be modified by a user. The SetReg tool found in the Authenticode Tool Pack can be used to select or cancel the selection of each value. These flags can be combined using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **WTPF_TRUSTTEST** | Trust any "TEST" certificate. |
| **WTPF_TESTCANBEVALID** | Check any "TEST" certificate for validity. |
| **WTPF_IGNOREEXPIRATION** | Ignore the expiration date on certificates. |
| **WTPF_IGNOREREVOKATION** | Ignore revocation checks. |
| **WTPF_OFFLINEOK_IND** | If the source is offline, trust any individual certificates. |
| **WTPF_OFFLINEOK_COM** | If the source is offline, trust any commercial certificates. |
| **WTPF_OFFLINEOKNBU_IND** | If the source is offline, trust any individual certificates. Do not use UI. |
| **WTPF_OFFLINEOKNBU_COM** | If the source is offline, trust any commercial certificates. Do not use checking UI. |
| **WTPF_VERIFY_V1_OFF** | Turn off verification of v1 certificates. |
| **WTPF_IGNOREREVOCATIONONTS** | Ignore time stamp revocation checks. |
| **WTPF_ALLOWONLYPERTRUST** | Allow only items in personal trust database. |

### `pSignerInfo`

A pointer to a
[CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_info) structure that contains information on the signer of the file.