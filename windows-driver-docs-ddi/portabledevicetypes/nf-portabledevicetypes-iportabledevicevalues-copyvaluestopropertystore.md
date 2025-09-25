# IPortableDeviceValues::CopyValuesToPropertyStore

## Description

Copies all the values from a collection into an **IPropertyStore** interface.

## Parameters

### `pStore` [in]

Pointer to a store object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Many external applications or components that communicate with your application, such as some shell applications, use the **IPropertyStore** interface. This method provides an efficient way to exchange data with these programs.

## See also

[IPortableDeviceValues Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledevicetypes/nn-portabledevicetypes-iportabledevicevalues)