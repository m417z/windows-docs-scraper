# D3DKMTReleaseProcessVidPnSourceOwners function

## Description

The **D3DKMTReleaseProcessVidPnSourceOwners** function releases the video present network source owners for a process.

## Parameters

### `unnamedParam1` [in]

*hProcess*

A handle to the process that video present network source owners are released from.

## Return value

**D3DKMTReleaseProcessVidPnSourceOwners** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The video present network source owners for a process were successfully released.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.