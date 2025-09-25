# IXamlDiagnostics::GetIInspectableFromHandle

## Description

Gets the [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) from the XAML Diagnostics
cache.

## Parameters

### `instanceHandle` [in]

A handle to the object.

### `ppInstance` [out, retval]

The object as an [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method will fail if XAML Diagnostics no longer has a reference to
the element.

## See also

[IXamlDiagnostics](https://learn.microsoft.com/previous-versions/windows/desktop/api/xamlom/nn-xamlom-ixamldiagnostics)