# StorPortPoFxSetComponentResidency function

## Description

The **StorPortPoFxSetComponentResidency** routine sets the estimated time for how long a storage device component is likely to remain idle after the component enters the idle condition.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA). This is the device extension used to register the device in a prior call to [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower).

### `Address` [in, optional]

The address of a storage device unit. This parameter is **NULL** when setting the residency of a storage adapter component.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [STOR_POFX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device) structure that the miniport driver registered for the device with a call to [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower). If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Residency` [in]

The estimated residency time, in 100-nanosecond units. This parameter is a hint to power management framework (PoFx) about how long the component is likely to remain idle after a transition from the active condition to the idle condition.

## Return value

The **StorPortPoFxSetComponentResidency** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The component residency is successfully set. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *Device* is NULL.<br><br>-or-<br><br>*Address* points to an invalid unit address structure.<br><br>-or-<br><br>The storage device specified by *Address* is not found.<br><br>-or-<br><br>The index in *Component* specifies a component greater than the component count for the device. |
| **STOR_STATUS_INVALID_DEVICE_REQUEST** | The storage device is not registered with the PoFx. |
| **STOR_STATUS_INVALID_IRQL** | The current IRQL > DISPATCH_LEVEL. |

## See also

[PoFxSetComponentResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxsetcomponentresidency)