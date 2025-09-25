# ITMultiTrackTerminal::EnumerateTrackTerminals

## Description

The
**EnumerateTrackTerminals** method creates and returns an enumeration containing the terminals contained by the multitrack terminal on which this method was called.

## Parameters

### `ppEnumTerminal` [out]

Pointer to the
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) interface enumerating terminals contained in the multitrack terminal.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppTerminalEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) interface returned by **ITMultiTrackTerminal::EnumerateTrackTerminals**. The application must call **Release** on the
**IEnumTerminal** interface to free resources associated with it.

## See also

[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal)

[ITMultiTrackTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itmultitrackterminal)