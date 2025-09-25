# PFN_TRSECUREDEVICEHANDOFFMASTERDEVICECONTROL callback function

## Description

## Parameters

### `BindContextObject`

### `DeviceInit`

### `Callbacks`

### `MasterDevice`

## Return value

Returns WDFAPI

## Syntax

```cpp
//Declaration

PFN_TRSECUREDEVICEHANDOFFMASTERDEVICECONTROL PfnTrsecuredevicehandoffmasterdevicecontrol;

// Definition

WDFAPI PfnTrsecuredevicehandoffmasterdevicecontrol
(
    WDFOBJECT BindContextObject
    PWDFDEVICE_INIT DeviceInit
    PTR_SECURE_DEVICE_CALLBACKS Callbacks
    WDFDEVICE *MasterDevice
)
{...}

```

## Remarks

## See also