# PcRequestNewPowerState function

## Description

The **PcRequestNewPowerState** function is used to request a new power state for the device. This function is typically not needed by adapter drivers but can occasionally be useful in working around some kinds of hardware problems.

## Parameters

### `pDeviceObject` [in]

Pointer to the adapter's [functional device object (FDO)](https://learn.microsoft.com/windows-hardware/drivers/). This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `RequestedNewState` [in]

Specifies the device power state being requested. Set this parameter to one of the following [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration values: **PowerDeviceD0**, **PowerDeviceD1**, **PowerDeviceD2**, or **PowerDeviceD3**.

## Return value

**PcRequestNewPowerState** returns STATUS_SUCCESS if the call was successful. Otherwise, returns an appropriate error message.

## Remarks

An adapter driver can call **PcRequestNewPowerState** to compensate for hardware design flaws. For example, if the functions in an audio adapter are not mutually independent and need to be shut down in a particular order, the adapter can call **PcRequestNewPowerState** to ensure that a particular subdevice is shut down first.

The **RequestedNewState** parameter can be set to one of the [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration values in the following table.

| Power State | Meaning |
| --- | --- |
| **PowerDeviceD0** | Full power state |
| **PowerDeviceD1** | The sleep state with the lowest power-up latency |
| **PowerDeviceD2** | A medium-latency sleep state |
| **PowerDeviceD3** | A full hibernation state and the sleep state with the longest power-up latency |

The hardware can be accessed only in power state **PowerDeviceD0**. In any other state, the driver must cache any attempted hardware accesses and defer those accesses until the **PowerDeviceD0** state is restored.

For more information, see [Power Management for Audio Devices](https://learn.microsoft.com/windows-hardware/drivers/audio/power-management-for-audio-devices).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)