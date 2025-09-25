# eDiagnoseLevel enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The eDiagnoseLevel enumeration defines the diagnosis levels for adapter hang diagnosis.

## Constants

### `DiagnoseLevelNone`

No diagnostic information should be collected.

### `DiagnoseLevelHardwareRegisters`

Dump the hardware registers. This information is included in the LiveKD dump.

### `DiagnoseLevelFirmwareImageDump`

Dump the full firmware image and hardware registers. The firmware image should dump to a file.

### `DiagnoseLevelDriverStateDump`

Dump the driver state, full firmware image, and hardware registers. The driver state and full firmware image should dump to files.

## See also

[MiniportWdiAdapterHangDiagnose](https://learn.microsoft.com/windows-hardware/drivers/ddi/dot11wdi/nc-dot11wdi-miniport_wdi_adapter_hang_diagnose)