# IFsrmMutableCollection::Add

## Description

Adds an object to the collection.

## Parameters

### `item` [in]

A **VARIANT** that contains the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface of the object to add to the collection. Set the variant type to **VT_DISPATCH** and the **pdispVal** member to the **IDispatch** interface of the object.

## Return value

The method returns the following return values.

## Remarks

All items in the collection must be of the same type.

#### Examples

For an example, see [Using Templates to Define File Screens](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/using-templates-to-define-file-screens).

## See also

[IFsrmMutableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmmutablecollection)