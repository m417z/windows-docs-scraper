# IPortableDeviceValues::GetFloatValue

## Description

The **GetFloatValue** method retrieves a **FLOAT** value (type VT_R4) specified by a key.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** key that specifies the item to retrieve.

### `pValue` [out]

Pointer to the retrieved **FLOAT** value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DISP_E_TYPEMISMATCH** | The property specified by *key* is not a **FLOAT** type. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The property specified by *key* is not in the collection. |

## Remarks

None.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::SetFloatValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setfloatvalue)