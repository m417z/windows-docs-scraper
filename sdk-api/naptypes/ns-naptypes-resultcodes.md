# ResultCodes structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **ResultCodes** structure defines a list of result codes.

## Members

### `count`

The number of result codes as a number between 0 and [maxDwordCountPerSoHAttribute](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants).

### `results`

A pointer to either a list of application defined 4-octet HRESULTs that specify whether the client machine is compliant, or a list of [NAP error constants](https://learn.microsoft.com/windows/desktop/NAP/nap-error-constants) that specify the cause of [SoH](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) construction or processing errors. The values must be in the byte ordering of the host system.

## See also

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)