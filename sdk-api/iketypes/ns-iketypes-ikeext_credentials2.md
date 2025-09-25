# IKEEXT_CREDENTIALS2 structure

## Description

The **IKEEXT_CREDENTIALS2** structure is used to store multiple credential pairs.
[IKEEXT_CREDENTIALS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials1) is available. For Windows Vista, [IKEEXT_CREDENTIALS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials0) is available.

## Members

### `numCredentials`

Type: **UINT32**

Number of [IKEEXT_CREDENTIAL_PAIR2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair2) structures in the array.

### `credentials`

Type: [IKEEXT_CREDENTIAL_PAIR2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair2)*

[size_is(numCredentials)]

Pointer to an array of [IKEEXT_CREDENTIAL_PAIR2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair2) structures.

## Remarks

IKE and IKEv2 have only 1 pair.

AuthIP
has 1 pair, or 2 pairs if EM was enabled.

MM authentication is always index 0.

EM authentication, if it occurs,
is index 1.

## See also

[IKEEXT_CREDENTIAL_PAIR2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair2)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)