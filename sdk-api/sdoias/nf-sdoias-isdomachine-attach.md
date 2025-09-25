# ISdoMachine::Attach

## Description

The
**Attach** method attaches to an SDO computer. Attaching to an SDO computer is the first step is using the SDO API to administer that computer.

## Parameters

### `bstrComputerName` [in]

Specifies a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) variable that contains the name of the computer to which to attach. If this parameter specifies a **NULL** string, the local computer is attached.

## Return value

If the method succeeds the return value is **S_OK**.

If a computer is already attached, the return value is **E_FAIL**.

The method may also return one of the following error codes.

## Remarks

Use the
[ISdoMachine::GetAttachedComputer](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getattachedcomputer) method to determine if a computer is already attached.

## See also

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::GetAttachedComputer](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getattachedcomputer)