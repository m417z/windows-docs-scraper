# IFileOperation::ApplyPropertiesToItem

## Description

Declares a single item whose property values are to be set.

## Parameters

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to the item to receive the new property values.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not apply the properties to the item, it merely declares the item. To set property values on an item, you must make at least the sequence of calls detailed here:

1. Call [IFileOperation::SetProperties](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-setproperties) to declare the specific properties to be set and their new values.
2. Call **IFileOperation::ApplyPropertiesToItem** to declare the item whose properties are to be set.
3. Call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to apply the properties to the item.

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[IFileOperation::ApplyPropertiesToItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-applypropertiestoitems)