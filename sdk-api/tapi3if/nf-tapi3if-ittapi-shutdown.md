# ITTAPI::Shutdown

## Description

The
**Shutdown** method shuts down a TAPI session.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **S_FALSE** | TAPI session has already been shut down. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

One reason why
**Shutdown** might fail is if
[Initialize](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-initialize) was not previously called successfully.

## See also

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)