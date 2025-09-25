# IEnumWIA_DEV_INFO::Clone

## Description

The **IEnumWIA_DEV_INFO::Clone** method creates an additional instance of the [IEnumWIA_DEV_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_info) interface and sends back a pointer to it.

## Parameters

### `ppIEnum` [out]

Type: **[IEnumWIA_DEV_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_info)****

Pointer to an [IEnumWIA_DEV_INFO](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwia_dev_info) interface. This parameter contains a pointer to the **IEnumWIA_DEV_INFO** interface instance that **IEnumWIA_DEV_INFO::Clone** creates.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the pointers they receive through the *ppIEnum* parameter.