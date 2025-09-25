# StorPortPoFxSetComponentLatency function

## Description

The **StorPortPoFxSetComponentLatency** routine specifies the maximum latency that can be tolerated in the transition from the idle condition to the active condition in the specified storage device component.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA). This is the device extension used to register the device in a prior call to [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower).

### `Address` [in, optional]

The address of a storage device unit. This parameter is **NULL** when setting the latency of a storage adapter component.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [STOR_POFX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device) structure that the miniport driver registered for the device with a call to [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower). If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Latency` [in]

The time, in units of 100 nanoseconds, that the storage device component can tolerate for a transition from an idle state the active state.

## Return value

The **StorPortPoFxSetComponentLatency** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The component latency successfully set. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *Device* is NULL.<br><br>-or-<br><br>*Address* points to an invalid unit address structure.<br><br>-or-<br><br>The storage device specified by *Address* is not found.<br><br>-or-<br><br>The index in *Component* specifies a component greater than the component count for the device. |
| **STOR_STATUS_INVALID_DEVICE_REQUEST** | The storage device is not registered with the power management framework (PoFx). |
| **STOR_STATUS_INVALID_IRQL** | The current IRQL > DISPATCH_LEVEL. |

## See also

[PoFxSetComponentLatency](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxsetcomponentlatency)