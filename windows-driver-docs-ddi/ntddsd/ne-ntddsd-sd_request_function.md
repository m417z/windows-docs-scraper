# SD_REQUEST_FUNCTION enumeration

## Description

The SD_REQUEST_FUNCTION enumeration indicates the type of request packet that a Secure Digital (SD) card driver sends to the bus driver.

## Constants

### `SDRF_GET_PROPERTY`

Indicates a get property request. The [SDBUS_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sdbus_property) enumeration lists the properties that an SD driver can get or set.

### `SDRF_SET_PROPERTY`

Indicates a set property request. The SDBUS_PROPERTY enumeration lists the properties that an SD driver can get or set.

### `SDRF_DEVICE_COMMAND`

Indicates a device-specific command.

### `SDRF_ERASE_COMMAND`

### `SDRF_MMC_SOFT_RESET`

### `SDRF_MMC_HPI`

## Remarks

The caller of the [SdBusSubmitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) routine assigns a value from the SD_REQUEST_FUNCTION enumeration to the **RequestFunction** member of the [SDBUS_REQUEST_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85)) structure to specify the type of request.

## See also

[SDBUS_REQUEST_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85))

[SdBusSubmitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest)