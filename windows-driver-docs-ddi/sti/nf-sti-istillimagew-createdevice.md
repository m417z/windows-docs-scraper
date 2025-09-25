## Description

The **IStillImage::CreateDevice** method creates an instance of the COM object that defines the [IStiDevice COM Interface](https://learn.microsoft.com/windows-hardware/drivers/image/istidevice-com-interface), and returns a pointer to the interface.

## Parameters

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)) or [IStillImage::GetDeviceList](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543784(v=vs.85)).

### `dwMode`

Caller-supplied constant value indicating the [Transfer Modes](https://learn.microsoft.com/windows-hardware/drivers/image/transfer-modes) in which the device is to be used. The following values are valid.

| Mode | Description |
|---|---|
| STI_DEVICE_CREATE_BOTH | The device is being opened for both obtaining status and transferring data. |
| STI_DEVICE_CREATE_DATA | The device is being opened only for data transfers. |
| STI_DEVICE_CREATE_STATUS | The device is being opened only for obtaining status information. |

### `pDevice` [out]

Receives a pointer to the [IStiDevice COM Interface](https://learn.microsoft.com/windows-hardware/drivers/image/istidevice-com-interface).

### `punkOuter` [in, optional]

Optional, caller-supplied pointer to the "controlling unknown" for object aggregation. See the following **Remarks** section.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

For an application to use the **IStiDevice** interface, it must first call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to get a pointer to the **IStillImage** interface, then call **IStillImage::CreateDevice** to get a pointer to the **IStiDevice** interface. The pointer received in *pDevice* is used subsequently when calling **IStiDevice** methods, as illustrated in the sample still image code, to obtain access to the specified device.

If you want to create an aggregate COM object that includes **IStiDevice**, you must supply a pointer to the "controlling unknown" in *punkOuter*. In most cases you will not be creating an aggregate object, so *punkOuter* should be **NULL**. Object aggregation and the controlling unknown are described in the Microsoft Windows SDK documentation and in the *Component Object Model Specification*.

## See also

[IStiDevice::Release](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/nf-sti-istidevice-release)

[IStillImageW](https://learn.microsoft.com/windows-hardware/drivers/ddi/_image/)