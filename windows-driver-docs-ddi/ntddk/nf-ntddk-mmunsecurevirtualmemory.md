# MmUnsecureVirtualMemory function

## Description

The **MmUnsecureVirtualMemory** routine unsecures a memory address range secured by the [MmSecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmsecurevirtualmemory) routine.

## Parameters

### `SecureHandle` [in]

Specifies the value returned by [MmSecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmsecurevirtualmemory) for the memory address range.

## See also

[MmSecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmsecurevirtualmemory)