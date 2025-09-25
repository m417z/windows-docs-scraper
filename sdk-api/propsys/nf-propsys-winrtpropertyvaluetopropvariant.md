# WinRTPropertyValueToPropVariant function

## Description

Copies the content from a Windows runtime property value to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

## Parameters

### `punkPropertyValue` [in, optional]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface from which this function can access the contents of a Windows runtime property value by retrieving and using the [Windows::Foundation::IPropertyValue](https://learn.microsoft.com/windows/desktop/api/windows.foundation/nn-windows-foundation-ipropertyvalue) interface.

### `ppropvar` [out]

Pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. When this function returns, the **PROPVARIANT** contains the converted info.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[PropVariantToWinRTPropertyValue](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-propvarianttowinrtpropertyvalue)