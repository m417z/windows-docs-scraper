# SeTokenGetNoChildProcessRestricted function

## Description

The **SeTokenGetNoChildProcessRestricted** routine determines the state of the no child process mitigation. It is
not possible to be enforced and audit-only at the same time.

## Parameters

### `Token` [in]

Specifies a pointer to the access token.

### `Enforced` [out]

A pointer to a boolean that returns whether the mitigation is in enforcement mode.

### `UnlessSecure` [out]

A pointer to a boolean that returns whether secure process creation is enabled even if
process creation is restricted.

### `AuditOnly` [out]

A pointer to a boolean that returns whether the mitigation is in audit-only mode.

## See also

[SeTokenSetNoChildProcessRestricted](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-setokensetnochildprocessrestricted)