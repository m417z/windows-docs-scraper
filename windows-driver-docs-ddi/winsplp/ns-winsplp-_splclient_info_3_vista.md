# _SPLCLIENT_INFO_3_VISTA structure

## Description

Contains a super-set of the information in both a [SPLCLIENT_INFO_1](https://learn.microsoft.com/dotnet/core/rid-catalog) and **SPLCLIENT_INFO_2** structure. It also contains additional information needed by the provider.

## Members

### `cbSize`

Specifies the size in bytes of this structure.

### `dwFlags`

Specifies open printer additional flags to the provider.

### `dwSize`

Reserved. Used for compatibility with the [SPLCLIENT_INFO_1](https://learn.microsoft.com/dotnet/core/rid-catalog) structure.

### `pMachineName`

Specifies the client machine name.

### `pUserName`

Specifies the client user name.

### `dwBuildNum`

Specifies the client build number.

### `dwMajorVersion`

Specifies the major version of the client machine.

### `dwMinorVersion`

Specifies the minor version of the client machine.

### `wProcessorArchitecture`

Specifies the client machine architecture.

### `hSplPrinter`

Specifies the server-side handle to be used for direct calls.