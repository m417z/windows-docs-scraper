# IClassFactory2::GetLicInfo

## Description

Retrieves information about the licensing capabilities of this class factory.

## Parameters

### `pLicInfo` [in, out]

A pointer to the caller-allocated [LICINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-licinfo) structure to be filled on output.

## Return value

This method can return the standard return values E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The [LICINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-licinfo) structure was successfully filled in. |
| **E_POINTER** | The address in *pLicInfo* is not valid. For example, it may be **NULL**. |

## Remarks

### Notes to Implementers

E_NOTIMPL is not allowed as a return value because this method provides critical information for the client of a licensed class factory.

## See also

[IClassFactory2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iclassfactory2)

[LICINFO](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-licinfo)