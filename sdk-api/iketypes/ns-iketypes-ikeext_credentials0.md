# IKEEXT_CREDENTIALS0 structure

## Description

The **IKEEXT_CREDENTIALS0** structure is used to store multiple credential pairs.
[IKEEXT_CREDENTIALS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials1) is available. For Windows 8, [IKEEXT_CREDENTIALS2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials2) is available.

## Members

### `numCredentials`

Number of [IKEEXT_CREDENTIAL_PAIR0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair0) structures in the array.

### `credentials`

[size_is(numCredentials)]

Pointer to an array of [IKEEXT_CREDENTIAL_PAIR0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair0) structures.

## Remarks

IKE has only 1 pair.

AuthIP
has 1 pair, or 2 pairs if EM was enabled.

MM authentication is always index 0.

EM authentication, if it occurs,
is index 1.

## See also

[IKEEXT_CREDENTIAL_PAIR0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credential_pair0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)