# StorPortInitializePoFxPower function

## Description

A miniport driver calls **StorPortInitializePoFxPower** to register a storage device with the power management framework (PoFx).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Address` [in, optional]

The address of a storage device unit. This parameter is **NULL** when registering for a storage adapter.

### `Device` [in]

A pointer to a **STOR_POFX_DEVICE_V2** structure cast to a pointer to [STOR_POFX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device). This structure contains a component list with F-states for a storage device.

### `D3ColdEnabled` [in, out]

A pointer to a **BOOLEAN** value which the Storport driver will set to indicate whether the D3 Cold state is enabled for the storage device.

## Return value

The **StorPortInitializePoFxPower** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *Device* is NULL.<br><br>-or-<br><br>*Address* points to an invalid unit address structure.<br><br>-or-<br><br>The storage device specified by *Address* is not found.<br><br>-or-<br><br>The [STOR_POFX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device) structure pointed to by *Device* is formatted incorrectly or contains invalid data. |
| **STOR_STATUS_SUCCESS** | The storage device was successfully registered with PoFx. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Sufficient resources are not available to register the storage device with PoFx. |
| **STOR_STATUS_UNSUCCESSFUL** | The storage device was not successfully registered with PoFx.<br><br>-or-<br><br>The storage device is already registered with PoFx. |

## Remarks

Adapter devices are always registered with a **NULL** value for *address*. Unit devices are registered by specifying a valid unit address for *address*.

If the **STOR_POFX_DEVICE_FLAG_ENABLE_D3_COLD** flag is set in the **Flags** member of *Device*, Storport will attempt to enable D3 Cold support for the device component. The D3 Cold enabled status is returned in the **BOOLEAN** value pointed to by *D3ColdEnabled*.

## See also

[STOR_POFX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device)