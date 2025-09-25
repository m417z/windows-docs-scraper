# IPortableDeviceClassExtension::Uninitialize

## Description

The Uninitialize interface disables the WPD interface, any private interfaces, and device service interfaces that were initialized by the given driver. This method also disables the WIA or WMDM compatibility layers if they are enabled.

## Return value

The method returns an **HRESULT**. Possible return values are shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To be supplied.

## See also

[IPortableDeviceClassExtension Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledeviceclassextension/nn-portabledeviceclassextension-iportabledeviceclassextension)