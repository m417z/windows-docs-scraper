# PEPCALLBACKPOWERONCRASHDUMPDEVICE callback function (pep_x.h)

## Description

The *PowerOnDumpDeviceCallback* callback routine turns on the crash-dump device.

## Parameters

### `CrashdumpInformation` [in]

A pointer to a [PEP_CRASHDUMP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_crashdump_information) structure that contains information about the crash-dump device.

## Return value

This routine returns TRUE if it succeeds in turning on power to the crash-dump device. Otherwise, it returns FALSE.

## Remarks

This routine is implemented by the platform extension plug-in (PEP). The routine handles requests from the Windows kernel to turn on the crash-dump device so that a crash dump can be saved to disk.

The PEP registers its *PowerOnDumpDeviceCallback* routine in response to a [PEP_DPM_REGISTER_CRASHDUMP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification from the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx).

The *PowerOnDumpDeviceCallback* routine is called at IRQL = HIGH_LEVEL with interrupts disabled. Thus, this routine cannot use timers, events, or any synchronization primitives other than spin locks.

## See also

[PEP_CRASHDUMP_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_crashdump_information)

[PEP_DPM_REGISTER_CRASHDUMP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)