# IOCTL_BTHHFP_DEVICE_GET_KSNODETYPES IOCTL

## Description

The **IOCTL_BTHHFP_DEVICE_GET_KSNODETYPES**
IOCTL Gets the KSNODE types that best describe the Bluetooth device’s input and output.

**Note** This IOCTL has been deprecated for Windows 8.1, so you should use [IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor) instead.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

```cpp
struct
{
    GUID OutputType;
    GUID InputType;
}

```

### Output buffer length

The size of the specified structure.

### Input/output buffer

### Input/output buffer length

### Status block

N/A

## -InputType

 The KSNODE type for the input.

## -OutputType

 The KSNODE type for the output.

## Remarks

This request completes immediately.

## See also

[Bluetooth HFP DDI IOCTLs](https://learn.microsoft.com/windows-hardware/drivers/audio/bluetooth-hfp-ddi-ioctls)

[IOCTL_BTHHFP_DEVICE_GET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthhfpddi/ni-bthhfpddi-ioctl_bthhfp_device_get_descriptor)