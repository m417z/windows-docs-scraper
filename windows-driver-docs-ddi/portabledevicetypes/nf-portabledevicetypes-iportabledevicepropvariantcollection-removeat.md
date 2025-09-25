# IPortableDevicePropVariantCollection::RemoveAt

## Description

Removes the element stored at the location specified by the given index.

## Parameters

### `dwIndex` [in]

Specifies the index of the element to be removed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The specified index was out of range. |

## Remarks

You must specify a zero-based index.

## See also

[IPortableDevicePropVariantCollection Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicepropvariantcollection)