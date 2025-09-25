# ID3D10InfoQueue::SetMuteDebugOutput

## Description

Set a boolean that turns the debug output on or off.

## Parameters

### `bMute` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Disable/Enable the debug output (**TRUE** to disable or mute the output, **FALSE** to enable the output).

## Remarks

This will stop messages that pass the storage filter from being printed out in the debug output, however those messages will still be added to the message queue.

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)