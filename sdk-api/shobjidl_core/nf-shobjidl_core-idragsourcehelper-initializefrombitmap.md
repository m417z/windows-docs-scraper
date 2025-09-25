# IDragSourceHelper::InitializeFromBitmap

## Description

Initializes the drag-image manager for a windowless control.

## Parameters

### `pshdi` [in]

Type: **LPSHDRAGIMAGE**

The [SHDRAGIMAGE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-shdragimage) structure that contains information about the bitmap.

### `pDataObject` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to the data object's [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Because **InitializeFromBitmap** always performs the RGB multiplication step in calculating the alpha value, you should always pass a bitmap without premultiplied alpha blending. Note that no error will result from passing the method a bitmap with premultiplied alpha blending, but this method will multiply it again, doubling the resulting alpha value.

## See also

[IDragSourceHelper](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idragsourcehelper)