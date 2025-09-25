# IEnumWIA_DEV_INFO::Next

## Description

The **IEnumWIA_DEV_INFO::Next** method fills an array of pointers to [IWiaPropertyStorage](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage) interfaces.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of array elements in the array indicated by the *rgelt* parameter.

### `rgelt` [out]

Type: **[IWiaPropertyStorage](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage)****

Receives the address of an array of [IWiaPropertyStorage](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage) interface pointers. **IEnumWIA_DEV_INFO::Next** fills this array with interface pointers.

### `pceltFetched` [in, out]

Type: **ULONG***

On output, this parameter contains the number of interface pointers actually stored in the array indicated by the *rgelt* parameter.

## Return value

Type: **HRESULT**

While there are devices left to enumerate, this method returns S_OK. It returns S_FALSE when the enumeration is finished. If the method fails, it returns a standard COM error code.

## Remarks

Applications use this method to query the properties of each available Windows Image Acquisition (WIA) hardware device. To do so, the application passes an array of [IWiaPropertyStorage](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiapropertystorage) interface pointers that it allocates. It also passes the number of array elements in the parameter *celt*. The **IEnumWIA_DEV_INFO::Next** method fills the array with pointers to **IWiaPropertyStorage** interfaces. Applications can query the interfaces for the properties that the device supports.

Applications must call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the interface pointers they receive through the *rgelt* parameter.