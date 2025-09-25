# _WHEA_XPF_CMC_DESCRIPTOR structure

## Description

The WHEA_XPF_CMC_DESCRIPTOR structure describes a corrected machine check (CMC) error source for an x86 or x64 processor.

## Members

### `Type`

The type of error source descriptor. This member is always set to WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFCMC.

### `Enabled`

A Boolean value that indicates if the error source is enabled.

### `NumberOfBanks`

The number of [WHEA_XPF_MC_BANK_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mc_bank_descriptor) structures contained in the **Banks** member.

### `Reserved`

Reserved for system use.

### `Notify`

A [WHEA_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_notification_descriptor) structure that describes the notification mechanism that is used by the error source.

### `Banks`

An array of [WHEA_XPF_MC_BANK_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mc_bank_descriptor) structures that describe the banks of machine check registers.

## Remarks

A WHEA_XPF_CMC_DESCRIPTOR structure is contained within the [WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor) structure.

## See also

[WHEA_ERROR_SOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_source_descriptor)

[WHEA_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_notification_descriptor)

[WHEA_XPF_MC_BANK_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_mc_bank_descriptor)