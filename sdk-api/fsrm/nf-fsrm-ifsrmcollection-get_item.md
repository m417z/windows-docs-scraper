# IFsrmCollection::get_Item

## Description

Retrieves the requested item from the collection.

This property is read-only.

## Parameters

## Remarks

If the item is an interface, the variant type is **VT_DISPATCH**. Call the
[QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on the
**pdispVal** member of the variant to get an interface to the specific object.

If the item is an **HRESULT** value, the variant type is
**VT_I4**. Use the **lVal** member of the variant to get the
**HRESULT** value.

#### Examples

For examples, see
[Updating a File Screen](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/updating-a-file-screen) and
[Classifying Files](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/classifying-files).

## See also

[IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection)