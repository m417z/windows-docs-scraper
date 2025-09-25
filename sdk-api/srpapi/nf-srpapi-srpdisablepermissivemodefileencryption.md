# SrpDisablePermissiveModeFileEncryption function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Disables permissive mode for file encryption on the current thread.

Use [SrpEnablePermissiveModeFileEncryption](https://learn.microsoft.com/previous-versions/windows/desktop/api/srpapi/nf-srpapi-srpenablepermissivemodefileencryption) to enable the mode.

This API does not attempt to handle nested calls by reference counting or such. The first call to **SrpDisablePermissiveModeFileEncryption** will disable the permissive mode.

## Return value

If this function succeeds, it returns S_OK.

HRESULT_FROM_WIN32 (ERROR_INVALID_STATE) indicates that thread tagging cannot be performed due to either process or thread context.