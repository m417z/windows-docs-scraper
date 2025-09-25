# ITTerminal::get_TerminalClass

## Description

The
**get_TerminalClass** method gets the
[Terminal Class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class) of the terminal.

## Parameters

### `ppTerminalClass` [out]

Pointer to **BSTR** representation of the
[Terminal Class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class) of the terminal.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppTerminalClass* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppTerminalClass* parameter.

## See also

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)