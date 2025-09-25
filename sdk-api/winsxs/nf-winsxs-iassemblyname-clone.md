# IAssemblyName::Clone

## Description

The **Clone** method copies the current side-by-side assembly name to a new instance of [IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname).

## Parameters

### `pName` [out]

Pointer to the location that contains the pointer to the new instance of [IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname).

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname)