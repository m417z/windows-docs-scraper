# EVT_SENSOR_DRIVER_DEVICE_IO_CONTROL callback function

## Description

Callback to handle IOCTL.

## Parameters

### `Sensor`

A reference to the sensor object.

### `Request`

The I/O request.

### `OutputBufferLength`

The output buffer length.

### `InputBufferLength`

The input buffer length.

### `IoControlCode`

The I/O control code.

## Return value

Returns NTSTATUS.

## Prototype

```cpp
//Declaration

EVT_SENSOR_DRIVER_DEVICE_IO_CONTROL EvtSensorDriverDeviceIoControl;

// Definition

NTSTATUS EvtSensorDriverDeviceIoControl
(
	SENSOROBJECT Sensor
	WDFREQUEST Request
	size_t OutputBufferLength
	size_t InputBufferLength
	ULONG IoControlCode
)
{...}

```