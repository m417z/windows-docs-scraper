# IPortableDeviceValues::GetIPortableDeviceValuesCollectionValue

## Description

Retrieves an **IPortableDeviceValuesCollection** (type VT_UNKNOWN) value specified by a key.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** key that specifies the item to retrieve.

### `ppValue` [out]

Address of a variable that receives a pointer to the retrieved [IPortableDeviceValuesCollection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevaluescollection) interface. The caller is responsible for calling **Release** on the retrieved interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DISP_E_TYPEMISMATCH** | The property specified by *key* is not an **IPortableDeviceValuesCollection** interface. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The property specified by *key* is not in the collection. |

## Remarks

None.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[SetIPortableDeviceValuesCollectionValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setiportabledevicevaluescollectionvalue)