# IXamlDiagnostics::RegisterInstance

## Description

Adds an [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) to the XAML Diagnostics cache and returns the newly created
**InstanceHandle** for the object.

## Parameters

### `pInstance` [in]

An instance of the object.

### `pInstanceHandle` [out, retval]

A handle to the object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IXamlDiagnostics](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ixamldiagnostics)