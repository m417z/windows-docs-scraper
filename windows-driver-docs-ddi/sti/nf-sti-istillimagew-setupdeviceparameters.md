## Description

The **IStillImage::SetupDeviceParameters** method allows clients of the **IStillImage** COM interface to modify a still image device's stored characteristics, if the device's bus type is unknown.

## Parameters

### `unnamedParam1` [in, out]

Defines the **PSTI_DEVICE_INFORMATIONW** parameter *unnamedParam1*.

## Return value

If the operation succeeds, the method returns S_OK. Otherwise, it returns one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

The **IStillImage::SetupDeviceParameters** method only allows modification of device parameters associated with still image devices for which a bus has not been identified. For such devices, the still image server sets the **dwHardwareConfiguration** member of the device's [STI_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/sti/ns-sti-_sti_device_informationw) structure to STI_HW_CONFIG_UNKNOWN when [IStillImage::GetDeviceInfo](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543782(v=vs.85)) is called.

Currently, the only device parameter that can be modified is the device's port name. When calling this method to modify the port name, the **dwSize**, **szDeviceInternalName**, and **pszPortName** members of the STI_DEVICE_INFORMATION must be specified. All other members are ignored.

Before calling **IStillImage::SetupDeviceParameters**, clients of the **IStillImage** COM interface must call [IStillImage::StiCreateInstance](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff543804(v=vs.85)) to obtain an **IStillImage** interface pointer.