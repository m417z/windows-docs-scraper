# ITCallingCard::get_Options

## Description

The
**get_Options** method gets the translation options for this address and card.

## Parameters

### `plOptions` [out]

Pointer to
[LINETRANSLATEOPTION](https://learn.microsoft.com/windows/desktop/Tapi/linetranslateoption--constants) flags.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plOptions* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallingcard)