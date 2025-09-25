# IsNetDrive function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows. Use [GetDriveType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdrivetypea) or [WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona) instead.]

Tests whether a drive is a network drive.

## Parameters

### `iDrive` [in]

Type: **int**

An integer that indicates which drive letter you want to test. Set it to 0 for A:, 1 for B:, and so on.

## Return value

Type: **int**

This function returns one of the following values.

| Return value | Description |
| --- | --- |
| 0 | The specified drive is not a network drive. |
| 1 | The specified drive is a network drive that is properly connected. |
| 2 | The specified drive is a network drive that is disconnected or in an error state. |