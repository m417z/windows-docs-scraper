# IKEEXT_CREDENTIALS1 structure

## Description

The **IKEEXT_CREDENTIALS1** structure is used to store multiple credential pairs.
[IKEEXT_CREDENTIALS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials0) is available.

## Members

### `numCredentials`

Number of [IKEEXT_CREDENTIAL_PAIR1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair1) structures in the array.

### `credentials`

[size_is(numCredentials)]

Pointer to an array of [IKEEXT_CREDENTIAL_PAIR1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair1) structures.

## Remarks

IKE and IKEv2 have only 1 pair.

AuthIP
has 1 pair, or 2 pairs if EM was enabled.

MM authentication is always index 0.

EM authentication, if it occurs,
is index 1.

## See also

[IKEEXT_CREDENTIAL_PAIR1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair1)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)