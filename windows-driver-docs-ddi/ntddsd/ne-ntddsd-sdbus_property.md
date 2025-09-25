# SDBUS_PROPERTY enumeration

## Description

The SDBUS_PROPERTY enumeration lists the properties of a Secure Digital (SD) card that an SD device driver can set with an SD request.

## Constants

### `SDP_MEDIA_CHANGECOUNT`

Indicates that the operation applies to the media change count property. This property includes 4 bytes of data (ULONG) that describe SD storage functions. This property is read-only.

### `SDP_MEDIA_STATE`

Indicates that the operation applies to the media state property. Provided for compatibility with SD storage-only host controllers. Valid only for SD storage functions. For a list of valid media states, see [SDPROP_MEDIA_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sdprop_media_state). This property is read-only.

### `SDP_WRITE_PROTECTED`

Indicates that the operation applies to the write-protected property and the state of the WriteProtect switch on the SD card. This property is read-only.

### `SDP_FUNCTION_NUMBER`

Indicates that the operation applies to the function number property. This property is read-only.

### `SDP_FUNCTION_TYPE`

v2.0 SDBUS_FUNCTION_TYPE

### `SDP_BUS_DRIVER_VERSION`

Indicates that the operation applies to the driver version property. This property is read-only. This property is only supported in version 2.0 or later of the driver.

### `SDP_BUS_WIDTH`

Indicates that the operation applies to the bus width property. The value of this property is either 1 or 4. This property is only supported in version 2.0 or later of the driver.

### `SDP_BUS_CLOCK`

Indicates that the operation applies to the bus clock speed property. The value of this property is in KHz. This property is only supported in version 2.0 or later of the driver.

### `SDP_BUS_INTERFACE_CONTROL`

Indicates that the operation applies to the SDIO bus interface control property.This property is corresponding to CCCR[7], which is defined in the *Secure Digital I/O (SDIO) Card Specification*. For setting bus width, SDP_BUS_WIDTH should be used to synchronize the memory function of a combination card. This property is only supported in version 2.0 or later of the driver.

### `SDP_HOST_BLOCK_LENGTH`

Indicates that the operation applies to the host block length property, which is the maximum block length that is supported by the controller. This property is read-only. This property is only supported in version 2.0 or later of the driver.

### `SDP_FUNCTION_BLOCK_LENGTH`

Indicates that the operation applies to the SDIO function block length property. This property is only supported in version 2.0 or later of the driver.

### `SDP_FN0_BLOCK_LENGTH`

Indicates that the operation applies to the SDIO function zero block length property. This property is shared by all functions of the SDIO card. This property is only supported in version 2.0 or later of the driver.

### `SDP_FUNCTION_INT_ENABLE`

Indicates that the operation applies to the SDIO function interrupt enable property. It is a Boolean-type property and only applies to the current function. This property is only supported in version 2.0 or later of the driver.

### `SDP_SET_CARD_INTERRUPT_FORWARD`

### `SDP_SET_WAKE_INTERRUPT_FORWARD`

### `SDP_HIGH_CAPACITY_SUPPORTED`

### `SDP_CHAINED_MDL_SUPPORTED`

### `SDP_HPI_SUPPORTED`

## Remarks

To read or set a property on an SD device, a device driver must do the following:

1. Set the **RequestFunction** member of [SDBUS_REQUEST_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85)) to an [SD_REQUEST_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function) enumeration value of either SDRF_GET_PROPERTY or SDRF_SET_PROPERTY.
2. Set the **Property** member of SDBUS_REQUEST_PACKET to the SDBUS_PROPERTY enumeration value that specifies the property to read or change.
3. Send the request to the bus driver by passing the initialized SDBUS_REQUEST_PACKET structure to either [SdBusSubmitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) or [SdBusSubmitRequestAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync).

## See also

[SDBUS_REQUEST_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537931(v=vs.85))

[SD_REQUEST_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function)

[SdBusSubmitRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest)

[SdBusSubmitRequestAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync)