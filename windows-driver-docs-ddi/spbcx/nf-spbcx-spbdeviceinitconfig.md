# SpbDeviceInitConfig function

## Description

The **SpbDeviceInitConfig** method attaches the SPB framework extension (SpbCx) to the I/O-request chain for a WDFDEVICE (FDO or PDO) object that is to be created.

## Parameters

### `DeviceInit` [in, out]

A pointer to the [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that is to be configured.

## Return value

**SpbDeviceInitConfig** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error code.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Cannot allocate the required system resources. |

## Remarks

This method associates the configuration information for SpbCx with the [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure for the device object (PDO or FDO) that is to be created. Your driver's [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback routine should call **SpbDeviceInitConfig** before it calls the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) method to create the device object.

#### Examples

The following code example shows how to use the **SpbDeviceInitConfig** method to associate the SpbCx framework extension's configuration information with the **WDFDEVICE_INIT** structure.

```
//
// FxDeviceInit is a pointer to a WDFDEVICE_INIT structure that comes as a
// parameter for an EvtDriverDeviceAdd handler, or from WdfPdoInitAllocate.
//

status = SpbDeviceInitConfig(FxDeviceInit);

if (!NT_SUCCESS(status))
{
    return status;
}

//
// Set WDF and SpbCx device-level configuration options.
//

...

//
// Call WdfDeviceCreate
//

status = WdfDeviceCreate(&FxDeviceInit,...);

```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[WdfPdoInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate)