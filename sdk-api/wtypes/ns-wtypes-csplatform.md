# CSPLATFORM structure

## Description

Contains an operating system platform and processor architecture.

## Members

### `dwPlatformId`

The operating system platform. See the **dwPlatformId** member of [OSVERSIONINFO](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-osversioninfoa).

### `dwVersionHi`

The major version of the operating system.

### `dwVersionLo`

The minor version of the operating system.

### `dwProcessorArch`

The processor architecture.
See the **wProcessorArchitecture** member of [SYSTEM_INFO](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-system_info).

## See also

[QUERYCONTEXT](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-querycontext)