# WDEnable function

## Description

Changes Windows Defender status to on or off.

**Note**

**WDEnable** is no longer available for use as of Windows 10, version 1607.

Beginning in Windows 10, version 1607 and Windows Server 2016, the **WDEnable** function always returns **E_NOTIMPL**.

## Parameters

### `fEnable` [in]

Type: **BOOL**

Windows Defender status that the calling application wants to set. **TRUE** enables Windows Defender. **FALSE** disables Windows Defender.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Windows Defender is configured to the state requested. |
| **E_ACCESSDENIED** | Calling application does not have sufficient permission or is flagged as a threat by Windows Defender signature database.<br><br>Calling application identity is not verifiable through digital signing. |
| **HRESULT_FROM_WIN32(ERROR_ACCESS_DISABLED_BY_POLICY)** | Calling application request contradicts with the Windows Defender status set by group policy. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

The application calling this function must run with administrator permissions on the local computer. Windows Defender also validates (1) the proper signing of the calling process and all loaded modules and (2) that the IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY flag is set on the calling process and all loaded modules before allowing the calling application to change the status. If the calling process image (or any loaded modules) is not signed or is flagged as a threat by the Windows Defender signature, then the call fails with the appropriate error code.

## See also

[WDStatus](https://learn.microsoft.com/windows/desktop/api/windowsdefender/nf-windowsdefender-wdstatus)