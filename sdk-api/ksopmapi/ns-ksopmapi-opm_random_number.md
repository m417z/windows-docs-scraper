# OPM_RANDOM_NUMBER structure

## Description

Contains a 128-bit random number for use with [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

## Members

### `abRandomNumber`

A 128-bit array that contains a random number.

## Remarks

Always use a cryptographically secure random-number generator to fill in this structure. The **CryptGenRandom** function is recommended, although not required.

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)