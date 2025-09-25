# SrpEnablePermissiveModeFileEncryption function

## Description

**Note** Windows Information Protection (WIP) policy can be applied on Windows 10, version 1607.

Enables permissive mode for file encryption on the current thread and all threads this thread will create or post work to.

Use [SrpDisablePermissiveModeFileEncryption](https://learn.microsoft.com/previous-versions/windows/desktop/api/srpapi/nf-srpapi-srpdisablepermissivemodefileencryption) to disable the mode.

This API does not attempt to handle nested calls by reference counting or such. Subsequent calls to **SrpEnablePermissiveModeFileEncryption** after the first successful call to this API will not have any effect.

## Parameters

### `enterpriseId` [in, optional]

Contains enterprise ID string. In TH2 this is not used.

## Return value

If this function succeeds, it returns S_OK.

HRESULT_FROM_WIN32 (ERROR_INVALID_STATE) indicates that thread tagging cannot be performed due to either process or thread context.