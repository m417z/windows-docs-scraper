# IPortableDeviceValues::GetIPortableDeviceValuesValue

## Description

Retrieves an **IPortableDeviceValues** value (type VT_UNKNOWN) that is specified by a key.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** key that specifies the item to retrieve.

### `ppValue` [out]

Address of a variable that receives a pointer to the retrieved [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) interface. The caller is responsible for calling **Release** on the retrieved interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DISP_E_TYPEMISMATCH** | The property specified by *key* is not an **IPortableDeviceValues** interface. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The property specified by *key* is not in the collection. |

## Remarks

None.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::SetIPortableDeviceValuesValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setiportabledevicevaluesvalue)