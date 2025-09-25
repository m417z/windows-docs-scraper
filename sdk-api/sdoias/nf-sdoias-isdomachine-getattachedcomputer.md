# ISdoMachine::GetAttachedComputer

## Description

The **GetAttachedComputer** method
retrieves the name of the computer that is currently attached as an SDO computer.

## Parameters

### `bstrComputerName` [out]

Pointer to a [BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) that
receives the name of the computer that is the currently-attached SDO computer.

## Return value

If the method succeeds the return value is **S_OK**.

If no computer is currently attached, the return value is **E_FAIL**.

The method may also return one of the following error codes.

## Remarks

The **GetAttachedComputer** allocates
the memory for the [BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)
variable. The calling application should free this memory by calling
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[ISdoMachine](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdomachine)

[ISdoMachine::Attach](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-attach)