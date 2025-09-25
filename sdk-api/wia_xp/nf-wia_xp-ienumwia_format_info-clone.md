# IEnumWIA_FORMAT_INFO::Clone

## Description

The **IEnumWIA_FORMAT_INFO::Clone** method creates an additional instance of the [IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info) interface and returns an interface pointer to the new interface.

## Parameters

### `ppIEnum` [out]

Type: **[IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info)****

Pointer to a new [IEnumWIA_FORMAT_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_format_info) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIEnum* parameter.