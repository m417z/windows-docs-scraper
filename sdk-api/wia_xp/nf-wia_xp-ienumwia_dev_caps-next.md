# IEnumWIA_DEV_CAPS::Next

## Description

The **IEnumWIA_DEV_CAPS::Next** method fills an array of pointers to [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structures.

## Parameters

### `celt` [in]

Type: **ULONG**

Specifies the number of array elements in the array indicated by the *rgelt* parameter.

### `rgelt` [out]

Type: **[WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap)***

Pointer to an array of [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structures. **IEnumWIA_DEV_CAPS::Next** fills this array of structures.

### `pceltFetched` [in, out]

Type: **ULONG***

On output, this parameter contains the number of structure pointers actually stored in the array indicated by the *rgelt* parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications use this method to query the capabilities of each available Windows Image Acquisition (WIA) hardware device. To do so, the application passes a pointer to an array of [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structures that it allocates. It also passes in the number of array elements in the parameter *celt*. The **IEnumWIA_DEV_CAPS::Next** method fills the array with structures. Applications then use the structures to enumerate WIA hardware device capabilities.

WIA device capabilities are defined as events and commands that the device supports. Using the *rgelt* array, **IEnumWIA_DEV_CAPS::Next** passes a single structure to the application for each event and command that the device supports.

Note that **IEnumWIA_DEV_CAPS::Next** dynamically allocates the [WIA_DEV_CAP](https://learn.microsoft.com/windows/desktop/api/wia_xp/ns-wia_xp-wia_dev_cap) structures it provides to applications. Therefore, applications must delete the **WIA_DEV_CAP** structures they receive through the *rgelt* parameter. Applications should use [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the *bstrName*, *bstrDescription*, and *bstrIcon* fields of all **WIA_DEV_CAP** structures.