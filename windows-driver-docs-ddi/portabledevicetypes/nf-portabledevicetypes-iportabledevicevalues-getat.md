# IPortableDeviceValues::GetAt

## Description

Retrieves a value from the collection, by a zero-based index.

## Parameters

### `index` [in]

A **DWORD** that specifies a zero-based index in the collection.

### `pKey` [in, out]

An optional **PROPERTYKEY** pointer that retrieves the key of the specified item.

### `pValue` [in, out]

An optional **PROPVARIANT** that retrieves the value of the specified item. The caller must free the memory by calling **PropVariantClear** when done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | An invalid index number was specified. |

## Remarks

If a property indicates a value of type VT_UNKNOWN, the property will be one of the Windows Portable Devices interfaces ([IPortableDeviceKeyCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection), [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicepropvariantcollection), [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues), or [IPortableDeviceValuesCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevaluescollection)). No other interfaces can be returned by Windows Portable Devices.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::GetStringValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-getstringvalue)