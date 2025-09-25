# IFsrmCollection::get__NewEnum

## Description

Retrieves the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer of a new
[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) enumeration for the items in
the collection.

This property is read-only.

## Parameters

## Remarks

C/C++ users use this method to enumerate items in the collection. Call the
[QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) of the
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface to get the
[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface. Use the
[IEnumVARIANT::Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-ienumvariant-next) method to enumerate
the items of the collection. The items are returned as **VARIANT** values.

If the collection contains interfaces, the variant type is **VT_DISPATCH**. Call the
[QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on the
**pdispVal** member of the variant to get an interface to the specific object. For example,
if the collection contains report objects, you would query the **pdispVal** member for the
[IFsrmReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreport) interface.

If the item is an **HRESULT** value, the variant type is
**VT_I4**. Use the **lVal** member of the variant to get the
**HRESULT** value.

## See also

[IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection)