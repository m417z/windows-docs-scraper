# IFileOperation::SetProperties

## Description

Declares a set of properties and values to be set on an item or items.

## Parameters

### `pproparray` [in]

Type: **[IPropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychangearray)***

Pointer to an [IPropertyChangeArray](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychangearray), which accesses a collection of [IPropertyChange](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertychange) objects that specify the properties to be set and their new values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not set the new property values, it merely declares them. To set property values on an item or a group of items, you must make at least the sequence of calls detailed here:

1. Call **IFileOperation::SetProperties** to declare the specific properties to be set and their new values.
2. Call [IFileOperation::ApplyPropertiesToItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-applypropertiestoitem) or [IFileOperation::ApplyPropertiesToItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-applypropertiestoitems) to declare the item or items whose properties are to be set.
3. Call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to apply the properties to the item or items.