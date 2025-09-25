# SeTokenSetNoChildProcessRestricted function

## Description

The **SeTokenSetNoChildProcessRestricted** routine sets the **TOKEN_NO_CHILD_PROCESS_UNLESS_SECURE** or **TOKEN_AUDIT_NO_CHILD_PROCESS**
flags in the token.

## Parameters

### `Token` [in]

Specifies a pointer to the access token.

### `UnlessSecure` [in]

A pointer to a boolean that indicates that secure process creation should always be enabled.

### `AuditOnly` [in]

A pointer to a boolean that indicates if the mitigation should be enabled in
audit-only mode.

## Remarks

Note that both flags cannot be set at the same time
and it is possible to upgrade from audit-only mode to enforcement
mode but not vice-versa.

## See also

[SeTokenGetNoChildProcessRestricted](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokengetnochildprocessrestricted)