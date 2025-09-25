# IEnumWiaItem::Next

## Description

The **IEnumWiaItem::Next** method fills an array of pointers to [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interfaces.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of array elements in the array indicated by the *ppIWiaItem* parameter.

### `ppIWiaItem` [out]

Type: **[IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem)****

Receives the address of an array of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface pointers. **IEnumWiaItem::Next** fills this array with interface pointers.

### `pceltFetched` [in, out]

Type: **ULONG***

On output, this parameter receives the number of interface pointers actually stored in the array indicated by the *ppIWiaItem* parameter. When the enumeration is complete, this parameter will contain zero.

## Return value

Type: **HRESULT**

If the method succeeds, the method returns S_OK. When the enumeration is complete, it returns S_FALSE. If the method fails, it returns a standard COM error code.

## Remarks

The Windows Image Acquisition (WIA) run-time system represents WIA hardware devices as a hierarchical tree of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects. Applications use the **IEnumWiaItem::Next** method to obtain an **IWiaItem** interface pointer for each item in the current folder of a hardware device's **IWiaItem** object tree.

To obtain the list of pointers, the application passes an array of [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) interface pointers that it allocates. It also passes the number of array elements in the *celt* parameter. The **IEnumWiaItem::Next** method fills the array with pointers to **IWiaItem** interfaces.

Until the enumeration process completes, the **IEnumWiaItem::Next** method returns S_OK. Each time it does, it sets the value pointed to by *pceltFetched* to the number of items it inserted into the array. When **IEnumWiaItem::Next** finishes the process of enumerating [IWiaItem](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitem) objects, it returns S_FALSE and sets the memory location pointed to by *pceltFetched* to zero.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *ppIWiaItem* parameter.