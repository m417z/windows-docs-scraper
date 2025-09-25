# IEnumWiaItem::Clone

## Description

The **IEnumWiaItem::Clone** method creates an additional instance of the [IEnumWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwiaitem) interface and sends back a pointer to it.

## Parameters

### `ppIEnum` [out]

Type: **[IEnumWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwiaitem)****

Pointer to the [IEnumWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-ienumwiaitem) interface. Receives the address of the **IEnumWiaItem** interface instance that **IEnumWiaItem::Clone** creates.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIEnum* parameter.