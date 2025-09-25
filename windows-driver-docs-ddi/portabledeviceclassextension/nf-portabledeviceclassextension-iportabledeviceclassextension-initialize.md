# IPortableDeviceClassExtension::Initialize

## Description

The Initialize interface initializes a portable device by registering the device, device service, and private interfaces. This method also enables the WIA or WMDM compatibility layers (if they are required). For multiple transport devices, this method initializes the transport settings.

A WPD driver calls this method one time during driver initialization (for example, in the driver’s implementation of the **IPnpCallbackHardware::OnPrepareHardware** method).

## Parameters

### `pWdfDeviceUnknown` [in]

A pointer to the **IWDFDevice** object that represents the devnode for that device.

### `pOptions` [in]

An **IPortableDeviceValues** object that contains one or more of the initialization options described in the [Class Extension Properties](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597738(v=vs.85)) section.

## Return value

The method returns an **HRESULT**. Possible return values are shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |

## See also

[IPortableDeviceClassExtension Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledeviceclassextension/nn-portabledeviceclassextension-iportabledeviceclassextension)

[WPD Class Extension Properties](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff597738(v=vs.85))