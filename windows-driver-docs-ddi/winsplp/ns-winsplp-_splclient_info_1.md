# _SPLCLIENT_INFO_1 structure

## Description

The SPLCLIENT_INFO_1 structure is used as input to the [GenerateCopyFilePaths](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-generatecopyfilepaths) function that is exported by [Point and Print DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/point-and-print-dlls).

## Members

### `dwSize`

Size of the SPLCLIENT_INFO_1 structure.

### `pMachineName`

Not used.

### `pUserName`

Not used.

### `dwBuildNum`

The build number of the version of the NT-based operating system running on the client, as returned by the Microsoft Window SDK **GetVersionEx** function.

### `dwMajorVersion`

The major version number of the NT-based operating system print spooler running on the client.

### `dwMinorVersion`

The minor version number of the NT-based operating system print spooler running on the client.

### `wProcessorArchitecture`

The client's processor architecture, as returned by the Window SDK **GetSystemInfo** function.

## Remarks

Values for all structure members are supplied by the print spooler before the spooler calls [GenerateCopyFilePaths](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-generatecopyfilepaths).