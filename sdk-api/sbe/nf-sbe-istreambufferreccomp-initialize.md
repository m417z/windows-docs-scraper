# IStreamBufferRecComp::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Initialize** method sets the file name and the profile for the new recording. Call this method once, after creating the [RecComp](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/reccomp-object) object.

## Parameters

### `pszTargetFilename` [in]

Null-terminated, wide character string that specifies the file name of the new recording.

### `pszSBRecProfileRef` [in]

Null-terminated, wide character string that specifies an existing file. This file must be a complete recording, already created by the Stream Buffer Engine.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

The profile of the file specified by *pszSBRecProfileRef* will be used for the target file. All files that are appended to the target file must have the same profile. For more information about profiles, see [IStreamBufferSink::LockProfile](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffersink-lockprofile).

## See also

[IStreamBufferRecComp Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferreccomp)