## Description

This method is for internal use only.

The **IStiDevice::Initialize** method initializes an instance of the COM object that defines the **IStiDevice** interface.

## Parameters

### `hinst` [in]

Caller-supplied instance handle of the calling process. This handle is obtained by calling **GetModuleName**(NULL).

### `pwszDeviceName` [in]

Caller-supplied pointer to a string representing an internal device name, obtained by calling [IStillImage::GetSTILaunchInformation](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543790(v=vs.85)).

### `dwVersion`

Caller-supplied STI version number. This value must be STI_VERSION, defined in *Sti.h*.

### `dwMode`

Caller-supplied constant value indicating the [Transfer Modes](https://learn.microsoft.com/windows-hardware/drivers/image/transfer-modes) in which the device is to be used. The following values are valid.

| Mode | Description |
|---|---|
| STI_DEVICE_CREATE_BOTH | The device is being opened for both obtaining status and transferring data. |
| STI_DEVICE_CREATE_DATA | The device is being opened only for data transfers. |
| STI_DEVICE_CREATE_STATUS | The device is being opened only for obtaining status information. |

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStiDevice::Initialize** method initializes the COM object instance that was created by calling [IStillImage::CreateDevice](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543778(v=vs.85)).

Because **IStiDevice::Initialize** is called by **IStillImage::CreateDevice**, clients of the **IStiDevice** interface do not typically call this method directly.