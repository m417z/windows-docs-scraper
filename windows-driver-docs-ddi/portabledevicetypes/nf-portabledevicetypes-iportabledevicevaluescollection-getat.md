# IPortableDeviceValuesCollection::GetAt

## Description

Retrieves an item from the collection by a zero-based index.

## Parameters

### `dwIndex` [in]

**DWORD** that specifies a zero-based index in the collection.

### `ppValues` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues) interface from the collection. The caller is responsible for calling **Release** on this interface when done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The zero-based index that was passed in was out of range. |
| **E_POINTER** | A required pointer argument was **NULL**. |
| **E_UNEXPECTED** | The collection contains a **NULL** **IPortableDeviceValues** pointer. |

## Remarks

Any changes that are made to values in the retrieved interface will be made to the version stored in the collection.

## See also

[IPortableDeviceValuesCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevaluescollection)