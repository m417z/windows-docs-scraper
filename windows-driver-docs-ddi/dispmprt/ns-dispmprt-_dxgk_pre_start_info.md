# _DXGK_PRE_START_INFO structure

## Description

Structure to allow very simple data to be exchanged between the OS and driver which may be required prior to start device being called and therefore cannot be queried through normal caps or adapter info DDIs.

## Members

### `ReservedIn`

This value is reserved for system use.

### `Input`

The combined UINT value operated on.

### `SupportPreserveBootDisplay`

Flag which indicates support for preserving the timing and content of the firmware display mode across DxgkDdiStartDevice.

### `IsUEFIFrameBufferCpuAccessibleDuringStartup`

Indicates that the driver can maintain same CPU virtual address mapping to the UEFI frame buffer during driver initialization.

### `ReservedOut`

This value is reserved for system use.

### `Output`

The combined UINT value operated on.