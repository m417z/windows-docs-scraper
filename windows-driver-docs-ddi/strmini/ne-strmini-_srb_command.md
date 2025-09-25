# _SRB_COMMAND enumeration

## Description

## Constants

### `SRB_READ_DATA`

Stream-specific code that specifies to read data from hardware.

### `SRB_WRITE_DATA`

Stream-specific code that specifies to write data to the hardware.

### `SRB_GET_STREAM_STATE`

Stream-specific code that specifies to get the state of the stream.

### `SRB_SET_STREAM_STATE`

Stream-specific code that specifies to set the state of the stream.

### `SRB_SET_STREAM_PROPERTY`

Stream-specific code that specifies to set a property of the stream.

### `SRB_GET_STREAM_PROPERTY`

Stream-specific code that specifies to get a property value for the stream.

### `SRB_OPEN_MASTER_CLOCK`

Stream-specific code that indicates that the master clock is on this stream.

### `SRB_INDICATE_MASTER_CLOCK`

Stream-specific code that specifies that the handle is supplied to the master clock.

### `SRB_UNKNOWN_STREAM_COMMAND`

Stream-specific code that specifies that the IRP function is unknown to the class driver.

### `SRB_SET_STREAM_RATE`

Stream-specific code that specifies that the rate is set at which the stream should run.

### `SRB_PROPOSE_DATA_FORMAT`

Stream-specific code that specifies that a new rate is proposed, it does not change the rate.

### `SRB_CLOSE_MASTER_CLOCK`

Stream-specific code that indicates that the master clock is closed.

### `SRB_PROPOSE_STREAM_RATE`

Stream-specific code that indicates a new rate is proposed, it does not change the rate.

### `SRB_SET_DATA_FORMAT`

Stream-specific code that sets a new data format.

### `SRB_GET_DATA_FORMAT`

Stream-specific code that returns the current data format.

### `SRB_BEGIN_FLUSH`

Stream-specific code that begins the flush state.

### `SRB_END_FLUSH`

Stream-specific code that ends the flush state.

### `SRB_GET_STREAM_INFO`

Device instance-specific code that gets the stream information structure.

### `SRB_OPEN_STREAM`

Device instance-specific code that opens the specified stream.

### `SRB_CLOSE_STREAM`

Device instance-specific code that closes the specific stream.

### `SRB_OPEN_DEVICE_INSTANCE`

Device instance-specific code that opens an instance of the device.

### `SRB_CLOSE_DEVICE_INSTANCE`

Device instance-specific code that closes an instance of the device.

### `SRB_GET_DEVICE_PROPERTY`

Device instance-specific code that gets the property of the device.

### `SRB_SET_DEVICE_PROPERTY`

Device instance-specific code that sets the property of the device.

### `SRB_INITIALIZE_DEVICE`

Device instance-specific code that initializes the device.

### `SRB_CHANGE_POWER_STATE`

Device instance-specific code that changes the power state.

### `SRB_UNINITIALIZE_DEVICE`

Device instance-specific code that uninitializes the device.

### `SRB_UNKNOWN_DEVICE_COMMAND`

Device instance-specific code that specifies that the IRP function is unknown to the class driver.

### `SRB_PAGING_OUT_DRIVER`

Device instance-specific code that indicates that the driver is to be paged out only if it is enabled in the registry. Board ints should be disabled and STATUS_SUCCESS returned.

### `SRB_GET_DATA_INTERSECTION`

Device instance-specific code that returns stream data intersection.

### `SRB_INITIALIZATION_COMPLETE`

Device instance-specific code that indicates that the initialization sequence has completed.

### `SRB_SURPRISE_REMOVAL`

Device instance-specific code that indicates a surprise removal of hardware has occurred.

### `SRB_DEVICE_METHOD`

### `SRB_STREAM_METHOD`

### `SRB_NOTIFY_IDLE_STATE`

Device instance-specific code that specifies to call on first open and last close.