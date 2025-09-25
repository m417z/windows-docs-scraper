## Description

The **KSPROPERTY_TUNER_SCAN_STATUS_S** structure describes status for a scanning operation.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `LockStatus`

One of the following values from the **TunerLockType** enumeration that indicates the lock status of the scanning operation.

| Status | Meaning |
|---|---|
| **Tuner_LockType_None** (0x00) | The tuner is not locked on a signal. The driver can return this value at the end of a scan. |
| **Tuner_LockType_Within_Scan_Sensing_Range** (0x01) | The signal is nearby; however, the driver cannot report the exact frequency. |
| **Tuner_LockType_Locked** (0x02) | A fine-tune signal lock was established. The driver can return this value at the end of a scan. |

### `CurrentFrequency`

The current locked-in frequency, in Hz, on the tuning device.

## See also

[KSEVENT_TUNER_INITIATE_SCAN](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-tuner-initiate-scan)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TUNER_SCAN_STATUS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-tuner-scan-status)

[PROPSETID_TUNER](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-tuner)