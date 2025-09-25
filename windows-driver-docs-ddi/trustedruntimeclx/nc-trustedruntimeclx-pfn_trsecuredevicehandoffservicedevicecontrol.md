# PFN_TRSECUREDEVICEHANDOFFSERVICEDEVICECONTROL callback function

## Description

## Parameters

### `BindContextObject`

### `DeviceInit`

### `ServiceGuid`

### `Callbacks`

### `ServiceDevice`

## Return value

Returns WDFAPI

## Syntax

```cpp
//Declaration

PFN_TRSECUREDEVICEHANDOFFSERVICEDEVICECONTROL PfnTrsecuredevicehandoffservicedevicecontrol;

// Definition

WDFAPI PfnTrsecuredevicehandoffservicedevicecontrol
(
    WDFOBJECT BindContextObject
    PWDFDEVICE_INIT DeviceInit
    LPGUID ServiceGuid
    PTR_SECURE_SERVICE_CALLBACKS Callbacks
    WDFDEVICE *ServiceDevice
)
{...}

```

## Remarks

## See also