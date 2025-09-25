# ITCallingCard::get_NumberOfDigits

## Description

The
**get_NumberOfDigits** method gets the number of digits in the existing card number.

## Parameters

### `plDigits` [out]

Pointer to number of digits in the card number.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *plDigits* parameter is not a valid pointer. |
| **E_POINTER** | The *plDigits* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The card number itself is not returned for security reasons. The application can use this information to insert filler bytes into a text control in "password" mode to show that a number exists.

## See also

[ITCallingCard](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallingcard)