# PsGetEffectiveServerSilo function

## Description

This routine traverses the parent chain of the *Silo* until finding the effective server silo or host silo.

## Parameters

### `Silo` [in]

 A pointer to a silo.

## Return value

The effective server silo. If a server silo is not found, the host silo is returned. In that case, `PsIsHostSilo(ReturnValue)` would return **TRUE**.

## Remarks

This routine does not fail because it always returns a silo: the server silo or the host silo.

## See also

[PsIsHostSilo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psishostsilo)