# UpdateExceptionContext enumeration

## Description

Defines the context in which an [IUpdateException](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateexception) object can be provided.

## Constants

### `uecGeneral:1`

The [IUpdateException](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateexception) is not tied to any context.

### `uecWindowsDriver:2`

The [IUpdateException](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateexception) is related to one or more Windows drivers.

### `uecWindowsInstaller:3`

The [IUpdateException](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateexception) is related to Windows Installer.

### `uecSearchIncomplete:4`

## See also

[IUpdateException.Context](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateexception-get_context)