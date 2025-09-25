# IPortableDeviceValues::GetBufferValue

## Description

The GetBufferValue interface retrieves a **byte array** value (type VT_VECTOR or VT_UI1) that is specified by a key.

## Parameters

### `key` [in]

A **REFPROPERTYKEY** key that specifies the item to retrieve.

### `ppValue` [out]

A pointer to the retrieved **BYTE*** value. The caller must free the memory by calling **CoTaskMemFree**.

### `pcbValue` [out]

A pointer to the size of *ppValue*, in bytes.

## Return value

The method returns an **HRESULT**. Possible return values are shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DISP_E_TYPEMISMATCH** | The property that is specified by *key* is not a **BYTE*** type. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The property that is specified by *key* is not in the collection. |
| **E_INVALIDARG** | One or more arguments specified are not valid. |

## Remarks

Retrieving a **NULL** buffer or a zero-sized buffer is not supported and will return E_INVALIDARG.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::SetBufferValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-setbuffervalue)