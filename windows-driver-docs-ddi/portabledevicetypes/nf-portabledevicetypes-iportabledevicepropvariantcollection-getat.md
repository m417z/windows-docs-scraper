# IPortableDevicePropVariantCollection::GetAt

## Description

Retrieves an item from the collection by a zero-based index.

## Parameters

### `dwIndex` [in]

**DWORD** that contains the zero-based index of the item to retrieve.

### `pValue` [out]

Pointer to a **PROPVARIANT** structure. The caller is responsible for freeing this memory by calling **PropVariantClear**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |
| **E_INVALIDARG** | The zero-based index that was passed in was out of range. |

## Remarks

None.

## See also

[IPortableDevicePropVariantCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicepropvariantcollection)