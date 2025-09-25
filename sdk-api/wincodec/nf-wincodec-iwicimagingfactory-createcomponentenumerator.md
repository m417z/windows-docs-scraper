# IWICImagingFactory::CreateComponentEnumerator

## Description

Creates an [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown) object of the specified component types.

## Parameters

### `componentTypes` [in]

Type: **DWORD**

The types of [WICComponentType](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccomponenttype) to enumerate.

### `options` [in]

Type: **DWORD**

The [WICComponentEnumerateOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wiccomponentenumerateoptions) used to enumerate the given component types.

### `ppIEnumUnknown` [out]

Type: **[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)****

A pointer that receives a pointer to a new component enumerator.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Component types must be enumerated separately. Combinations of component types and **WICAllComponents** are unsupported.