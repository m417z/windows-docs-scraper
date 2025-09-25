# IDiscRecorder::GetPath

## Description

Retrieves a path to the device within the operating system. This path should be used in conjunction with the display name to completely identify an available disc recorder.

## Parameters

### `pbstrPath` [out]

Path to the disc recorder. This path may be of the form \Device\CdRom*X*, but you should not rely on the path following this convention.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)