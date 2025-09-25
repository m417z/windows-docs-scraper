# IPortableDeviceValues::CopyValuesFromPropertyStore

## Description

Copies the contents of an **IPropertyStore** into the collection.

## Parameters

### `pStore` [in]

Pointer to an **IPropertyStore** to copy into the collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method automatically converts all VT_**BSTR** values to VT_**LPWSTR** values.

Many external applications or components that communicate with your application, such as some shell applications, use the IPropertyStore interface. This method provides an efficient way to exchange data with these programs.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)

[IPortableDeviceValues::CopyValuesToPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nf-portabledevicetypes-iportabledevicevalues-copyvaluestopropertystore)