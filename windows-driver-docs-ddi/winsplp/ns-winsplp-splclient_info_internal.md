## Description

The **SPLCLIENT_INFO_INTERNAL** structure is a super set of the information in splclient_info_1, splclient_info2 and splclient_info3 and contains additional information needed by the Device Control Defender code.

## Members

### `cbSize`

Size in bytes of this structure.

### `dwFlags`

Open printer additional flags to the provider.

### `dwSize`

Reserved for compatibility with a info 1 structure.

### `pMachineName`

Client machine name

### `pUserName`

Client user name

### `dwBuildNum`

Client build number

### `dwMajorVersion`

Client machine major version

### `dwMinorVersion`

Client machine minor version

### `wProcessorArchitecture`

Client machine architecture

### `hSplPrinter`

Server side handle to be used for direct calls.

### `dwProcessId`

ProcessId of the app that is calling OpenPrinter.

### `dwSessionId`

SessionId of the app session that is calling OpenPrinter.

## Remarks

## See also