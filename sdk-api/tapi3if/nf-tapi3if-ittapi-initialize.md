# ITTAPI::Initialize

## Description

The
**Initialize** method initializes TAPI. This method must be called before calling any other TAPI 3 method. The application must call the
[Shutdown](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-shutdown) method when ending a TAPI session.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **S_FALSE** | TAPI has already been initialized. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)