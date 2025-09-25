## Description

PosCxRemoteRequestRelease is called whenever a remote device asks for the device to release. This initiates claim negotiation.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `deviceInterfaceTag` [in]

The device interface that initiated the release request.

## Return value

Possible return values are:

| Value | Description |
|---|---|
| **STATUS_SUCCESS** | The device will now start resolving the remote request to release. |
| **STATUS_DEVICE_NOT_READY** | The PosCx library was not successfully initialized. |