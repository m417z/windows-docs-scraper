# StorPortIsCurrentOsInstallationUpgrade function

## Description

The **StorPortIsCurrentOsInstallationUpgrade** routine checks if the current installation of Windows is an upgrade from a previous version or not.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Upgraded` [out]

The value pointed to by *Upgraded* is set to **TRUE** if the current operating system installation was upgraded from a previous version. Otherwise, it is set to **FALSE**.

## Return value

The **StorPortIsCurrentOsInstallationUpgrade** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | An upgrade status is returned in the value pointed to by the *Upgraded* parameter. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer value in *Upgraded* is NULL. |
| **STOR_STATUS_INVALID_IRQL** | The current IRQL > PASSIVE_LEVEL. |