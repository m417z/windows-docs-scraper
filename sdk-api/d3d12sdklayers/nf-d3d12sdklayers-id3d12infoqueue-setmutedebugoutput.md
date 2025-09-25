# ID3D12InfoQueue::SetMuteDebugOutput

## Description

Set a boolean that turns the debug output on or off.

## Parameters

### `bMute` [in]

Type: **BOOL**

Disable/Enable the debug output (true to disable or mute the output, false to enable the output).

## Remarks

This will stop messages that pass the storage filter from being printed out in the debug output, however those messages will still be added to the message queue.

## See also

[ID3D12InfoQueue](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12infoqueue)