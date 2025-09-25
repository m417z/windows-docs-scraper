# PoUnregisterPowerSettingCallback function (ntifs.h)

## Description

The **PoUnregisterPowerSettingCallback** routine unregisters a power-setting callback routine that a driver previously registered by calling the [PoRegisterPowerSettingCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterpowersettingcallback) routine.

## Parameters

### `Handle` [in, out]

A handle to a callback routine that a driver registered by calling **PoRegisterPowerSettingCallback**.

## Return value

**PoUnregisterPowerSettingCallback** returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callback routine was unregistered. |
| **STATUS_INVALID_PARAMETER** | The *Handle* value is not a valid handle to a power setting callback routine. |

## Remarks

A driver calls **PoUnregisterPowerSettingCallback** to unregister a power setting callback routine that the driver previously registered by calling **PoRegisterPowerSettingCallback**.

A driver must call **PoUnregisterPowerSettingCallback** to unregister each callback routine that it previously registered. All callback routines registered by a driver should be unregistered in the *Unload* routine of the driver.

## See also

[PoRegisterPowerSettingCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterpowersettingcallback)