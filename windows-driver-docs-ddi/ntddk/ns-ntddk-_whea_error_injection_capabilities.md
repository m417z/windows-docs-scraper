# _WHEA_ERROR_INJECTION_CAPABILITIES structure

## Description

The WHEA_ERROR_INJECTION_CAPABILITIES union describes the types of hardware errors that can be injected into a hardware platform.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.ProcessorCorrectable`

A single bit that indicates that a correctable processor error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.ProcessorUncorrectableNonFatal`

A single bit that indicates that an uncorrectable nonfatal processor error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.ProcessorUncorrectableFatal`

A single bit that indicates that an uncorrectable fatal processor error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.MemoryCorrectable`

A single bit that indicates that a correctable memory error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.MemoryUncorrectableNonFatal`

A single bit that indicates that an uncorrectable nonfatal memory error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.MemoryUncorrectableFatal`

A single bit that indicates that an uncorrectable fatal memory error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.PCIExpressCorrectable`

A single bit that indicates that a correctable PCI Express (PCIe) error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.PCIExpressUncorrectableNonFatal`

A single bit that indicates that an uncorrectable nonfatal PCI Express (PCIe) error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.PCIExpressUncorrectableFatal`

A single bit that indicates that an uncorrectable fatal PCI Express (PCIe) error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.PlatformCorrectable`

A single bit that indicates that a correctable platform error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.PlatformUncorrectableNonFatal`

A single bit that indicates that an uncorrectable nonfatal platform error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.PlatformUncorrectableFatal`

A single bit that indicates that an uncorrectable fatal platform error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.IA64Corrected`

A single bit that indicates that a corrected IA64 error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.IA64Recoverable`

A single bit that indicates that a recoverable IA64 error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.IA64Fatal`

A single bit that indicates that a fatal IA64 error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.IA64RecoverableCache`

A single bit that indicates that a recoverable IA64 cache error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.IA64RecoverableRegFile`

A single bit that indicates that a recoverable IA64 register file error can be injected into the hardware platform.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `AsULONG`

A ULONG representation of the contents of the WHEA_ERROR_INJECTION_CAPABILITIES union.

## Remarks

A user-mode WHEA management application calls the [WHEAErrorInjectionMethods::GetErrorInjectionCapabilitiesRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/) method to retrieve a WHEA_ERROR_INJECTION_CAPABILITIES union that describes the types of hardware errors that can be injected into the hardware platform. If a PSHED plug-in is registered to participate in error injection, the PSHED plug-in's [GetInjectionCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_injection_capabilities) callback function is called to provide this information back to the calling application. The application uses this information when it calls the [WHEAErrorInjectionMethods::InjectErrorRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/) method to inject a hardware error into the hardware platform.

## See also

[GetInjectionCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-pshed_pi_get_injection_capabilities)

[WHEAErrorInjectionMethods::GetErrorInjectionCapabilitiesRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/)

[WHEAErrorInjectionMethods::InjectErrorRtn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_whea/)