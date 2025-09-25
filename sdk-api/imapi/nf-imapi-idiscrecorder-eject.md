# IDiscRecorder::Eject

## Description

Unlocks and ejects the tray of the disc recorder, if possible.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

Not all recorders support calls to eject their media. However, this method attempts to eject media.

## See also

[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder)