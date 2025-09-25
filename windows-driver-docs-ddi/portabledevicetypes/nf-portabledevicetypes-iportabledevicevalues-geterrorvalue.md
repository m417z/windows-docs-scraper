# IPortableDeviceValues::GetErrorValue

## Description

Retrieves an **HRESULT** value (type VT_ERROR) specified by a key.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** key that specifies the item to retrieve.

### `pValue` [out]

Pointer to the retrieved **HRESULT** value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DISP_E_TYPEMISMATCH** | The property specified by *key* is not an **HRESULT** type. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The property specified by *key* is not in the collection. |

## Remarks

None.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::SetErrorValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-seterrorvalue)