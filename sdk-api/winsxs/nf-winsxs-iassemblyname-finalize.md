# IAssemblyName::Finalize

## Description

The **Finalize** method prevents a side-by-side assembly name from being changed. After **Finalize** is called, additional calls to the [SetProperty](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblyname-setproperty) returns **E_UNEXPECTED**.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname)