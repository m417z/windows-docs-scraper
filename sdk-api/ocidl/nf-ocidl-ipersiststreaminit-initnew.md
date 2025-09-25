# IPersistStreamInit::InitNew

## Description

Initializes an object to a default state. This method is to be called instead of [IPersistStreamInit::Load](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-load).

## Return value

This method can return the standard return valuesE_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The object requires no default initialization. This error code is allowed because an object may choose to implement [IPersistStreamInit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit) simply for orthogonality or in anticipation of a future need for this method. |

## Remarks

If the object has already been initialized with [IPersistStreamInit::Load](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipersiststreaminit-load), then this method must return E_UNEXPECTED.

## See also

[IPersistStreamInit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit)