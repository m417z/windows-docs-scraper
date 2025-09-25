# IPortableDeviceKeyCollection::GetAt

## Description

Retrieves a **PROPERTYKEY** from the collection by index.

## Parameters

### `dwIndex` [in]

**DWORD** that contains the zero-based index of the key to be retrieved.

### `pKey` [out]

Pointer to a **PROPERTYKEY**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The index passed in was out of range. |
| **E_POINTER** | A required pointer argument was **NULL**. |

## Remarks

None.

## See also

[IPortableDeviceKeyCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicekeycollection)