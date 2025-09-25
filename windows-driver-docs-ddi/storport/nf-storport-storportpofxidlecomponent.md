# StorPortPoFxIdleComponent function

## Description

The **StorPortPoFxIdleComponent** routine decrements the activation reference count of a specified component of a storage device.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address` [in, optional]

The address of a storage device unit. This parameter is **NULL** when idling a storage adapter component.

### `Srb` [in, optional]

The SRB triggering the component deactivation. This parameter is **NULL** if the miniport is idling a device component internally.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the [STOR_POFX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device) structure that the miniport driver registered for the device with a call to [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower). If the **Components** array contains N elements, component indexes range from 0 to N–1.

### `Flags` [in]

Not used. Set to 0.

## Return value

The **StorPortPoFxIdleComponent** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The storage device activation reference was successfully decremented and the component is idle. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *Device* is NULL.<br><br>-or-<br><br>*Address* points to an invalid unit address structure.<br><br>-or-<br><br>The storage device specified by *Address* is not found.<br><br>-or-<br><br>The storage device is not registered with the power management framework (PoFx).<br><br>-or-<br><br>The SRB pointed to by *Srb* is not sent from Storport.<br><br>-or-<br><br>The *Flags* parameter is nonzero. |
| **STOR_STATUS_INVALID_DEVICE_REQUEST** | The adapter or unit does not support PoFx.<br><br>-or-<br><br>**StorPortPoFxIdleComponent** was called with an inactive *Component* and an *Srb* for which a previous call to [StorPortPoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxactivatecomponent) was not performed. |
| **STOR_STATUS_INVALID_IRQL** | The current IRQL > DISPATCH_LEVEL. |
| **STOR_STATUS_BUSY** | The active reference for the device component was decremented but the component is still active. |

## Remarks

Currently, both adapter devices and unit devices have maximum component count of 1. The index in *Component* must always be set to 0.

Each call to **StorPortPoFxIdleComponent** must be matched with a previous call to [StorPortPoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxactivatecomponent).

## See also

[STOR_POFX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device)

[StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower)

[StorPortPoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxactivatecomponent)