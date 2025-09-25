# ISdoMachine::IsDirectoryAvailable

## Description

The
**IsDirectoryAvailable** method tests whether an Active Directory service is available on the SDO computer.

## Parameters

### `boolDirectoryAvailable` [out]

Specifies whether the Active Directory is available. If the Active Directory is available, this parameter is **TRUE**. Otherwise, it is **FALSE**.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Before calling this method, use the
[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach) method to attach to the SDO computer.

**Important** Always returns **VARIANT_FALSE** in the current implementation.

## See also

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach)