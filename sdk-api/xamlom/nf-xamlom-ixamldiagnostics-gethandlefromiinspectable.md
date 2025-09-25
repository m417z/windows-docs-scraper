# IXamlDiagnostics::GetHandleFromIInspectable

## Description

Gets an **InstanceHandle** representation of an [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable).

## Parameters

### `pInstance` [in]

An instance of the object as an [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable).

### `pHandle` [out, retval]

A handle to the object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IXamlDiagnostics](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ixamldiagnostics)