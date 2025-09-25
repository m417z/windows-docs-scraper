# IWCPropertySheetCallback::AddPropertySheetPage

## Description

Adds a property page to a
[Failover Cluster Administrator](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-administrator) property sheet.

## Parameters

### `hpage` [in]

Handle to the property page to be added.

## Return value

If
**AddPropertySheetPage**
was not successful, it can return other **HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | The *hpage* parameter is invalid. |

## Remarks

Call the
**AddPropertySheetPage**
method from your
[IWEExtendPropertySheet::CreatePropertySheetPages](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendpropertysheet-createpropertysheetpages)
implementation. However, before you call
**AddPropertySheetPage**,
call the function [CreatePropertySheetPage](https://learn.microsoft.com/windows/desktop/api/prsht/nf-prsht-createpropertysheetpagea)
to retrieve a handle to pass in the *hpage* parameter.

## See also

[IWCPropertySheetCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-iwcpropertysheetcallback)

[IWEExtendPropertySheet::CreatePropertySheetPages](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-iweextendpropertysheet-createpropertysheetpages)