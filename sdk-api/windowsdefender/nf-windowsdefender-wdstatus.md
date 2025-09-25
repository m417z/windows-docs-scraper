# WDStatus function

## Description

Returns the current status of Windows Defender.

## Parameters

### `pfEnabled` [out]

Type: **BOOL***

The status of Windows Defender as a boolean. **TRUE** means Windows Defender is in enabled status. **FALSE** means Windows Defender is in disabled status.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[WDEnable](https://learn.microsoft.com/windows/desktop/api/windowsdefender/nf-windowsdefender-wdenable)