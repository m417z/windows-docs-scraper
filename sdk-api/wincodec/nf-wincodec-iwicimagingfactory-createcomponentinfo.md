# IWICImagingFactory::CreateComponentInfo

## Description

Creates a new instance of the [IWICComponentInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccomponentinfo) class for the given component class identifier (CLSID).

## Parameters

### `clsidComponent` [in]

Type: **REFCLSID**

The CLSID for the desired component.

### `ppIInfo` [out]

Type: **[IWICComponentInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccomponentinfo)****

A pointer that receives a pointer to a new [IWICComponentInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwiccomponentinfo).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.