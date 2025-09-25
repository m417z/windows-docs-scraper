# WdfUsbTargetDeviceRetrieveCurrentFrameNumber function

## Description

[Applies to KMDF only]

The **WdfUsbTargetDeviceRetrieveCurrentFrameNumber** method retrieves the current USB frame number.

## Parameters

### `UsbDevice` [in]

A handle to a USB device object that was obtained from a previous call to [WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters).

### `CurrentFrameNumber` [out]

A pointer to a location that receives the current 32-bit USB frame number.

## Return value

**WdfUsbTargetDeviceRetrieveCurrentFrameNumber** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_UNSUCCESSFUL** | The frame number was unavailable, possibly because lower drivers do not provide frame numbers. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the **WdfUsbTargetDeviceRetrieveCurrentFrameNumber** method and USB I/O targets, see [USB I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/usb-i-o-targets).

#### Examples

The following code example calls **WdfUsbTargetDeviceRetrieveCurrentFrameNumber**. The example obtains a USB device object handle from driver-defined context space.

```cpp
ULONG  frameNumber;
PMY_DEVICE_CONTEXT  pMyDeviceContext;

pMyDeviceContext = GetDeviceContext(Device);

status = WdfUsbTargetDeviceRetrieveCurrentFrameNumber(
                                              pMyDeviceContext->UsbTargetDevice,
                                              &frameNumber
                                              );
```

## See also

[WdfUsbTargetDeviceCreateWithParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicecreatewithparameters)