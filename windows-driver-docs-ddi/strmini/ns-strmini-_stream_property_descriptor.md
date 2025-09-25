# _STREAM_PROPERTY_DESCRIPTOR structure

## Description

STREAM_PROPERTY_DESCRIPTOR specifies the parameters of property get/set requests that the class driver passes to the minidriver.

## Members

### `Property`

Specifies the property to be read/written.

### `PropertySetID`

Specifies the index of the property set within either the [HW_STREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_header)'s **DevicePropertiesArray** (for minidriver properties) or the [HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information)'s **StreamPropertiesArray** (for stream properties).

### `PropertyInfo`

Points to a buffer that the property data will be read from or written to.

### `PropertyInputSize`

Size of the **Property** buffer.

### `PropertyOutputSize`

Size of the **PropertyInfo** buffer.