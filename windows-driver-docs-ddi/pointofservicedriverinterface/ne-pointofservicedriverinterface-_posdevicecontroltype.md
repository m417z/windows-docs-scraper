## Description

This enumeration defines values for the IOCTLs of the scanner driver and magnetic stripe reader (MSR) driver.

## Constants

### `_MinDeviceControlType`

Reserved for internal use.

### `Invalid`

The event code is not valid.

### `GetProperty`

Represents [IOCTL_POINT_OF_SERVICE_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_get_property).

### `SetProperty`

Represents [IOCTL_POINT_OF_SERVICE_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_set_property).

### `ClaimDevice`

Represents [IOCTL_POINT_OF_SERVICE_CLAIM_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_claim_device).

### `ReleaseDevice`

Represents [IOCTL_POINT_OF_SERVICE_RELEASE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_release_device).

### `RetainDevice`

Represents [IOCTL_POINT_OF_SERVICE_RETAIN_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_retain_device).

### `RetrieveStatistics`

Represents [IOCTL_POINT_OF_SERVICE_RETRIEVE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_retrieve_statistics).

### `ResetStatistics`

Represents [IOCTL_POINT_OF_SERVICE_RESET_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_reset_statistics).

### `UpdateStatistics`

Represents [IOCTL_POINT_OF_SERVICE_UPDATE_STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_update_statistics).

### `CheckHealth`

Represents [IOCTL_POINT_OF_SERVICE_CHECK_HEALTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_check_health).

### `GetDeviceBasics`

Represents [IOCTL_POINT_OF_SERVICE_GET_DEVICE_BASICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_get_device_basics).

### `BarcodeScannerInjectEvent`

Defines the **BarcodeScannerInjectEvent** constant.

### `MsrRetrieveDeviceAuthentication`

Represents [IOCTL_POINT_OF_SERVICE_MSR_RETRIEVE_DEVICE_AUTHENTICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_msr_retrieve_device_authentication).

### `MsrAuthenticateDevice`

Represents [IOCTL_POINT_OF_SERVICE_MSR_AUTHENTICATE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_msr_authenticate_device).

### `MsrDeAuthenticateDevice`

Represents [IOCTL_POINT_OF_SERVICE_MSR_DEAUTHENTICATE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_msr_deauthenticate_device).

### `MsrUpdateKey`

Represents [IOCTL_POINT_OF_SERVICE_MSR_UPDATE_KEY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pointofservicedriverinterface/ni-pointofservicedriverinterface-ioctl_point_of_service_msr_update_key).

### `StartBarcodeScannerSoftwareTrigger`

Defines the **StartBarcodeScannerSoftwareTrigger** constant.

### `StopBarcodeScannerSoftwareTrigger`

Defines the **StopBarcodeScannerSoftwareTrigger** constant.

### `BarcodeScannerGetSymbologyAttributes`

Defines the **BarcodeScannerGetSymbologyAttributes** constant.

### `BarcodeScannerSetSymbologyAttributes`

Defines the **BarcodeScannerSetSymbologyAttributes** constant.

### `_MaxDeviceControlType`

Reserved for internal use.

## Remarks

This enumeration provides values for each IOCTL that you can send to the device driver. It is a convenient way to indicate which IOCTL to dispatch when calling functions like **SendDeviceCommand()**.