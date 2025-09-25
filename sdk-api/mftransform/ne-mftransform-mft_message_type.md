# MFT_MESSAGE_TYPE enumeration

## Description

Defines messages for a Media Foundation transform (MFT). To send a message to an MFT, call [IMFTransform::ProcessMessage](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processmessage).

## Constants

### `MFT_MESSAGE_COMMAND_FLUSH:0`

Requests the MFT to flush all stored data.
Should only be called after streaming has started using the MFT_MESSAGE_NOTIFY_BEGIN_STREAMING message.

See [MFT_MESSAGE_COMMAND_FLUSH](https://learn.microsoft.com/windows/desktop/medfound/mft-message-command-flush).

### `MFT_MESSAGE_COMMAND_DRAIN:0x1`

Requests the MFT to drain any stored data.
Should only be called after streaming has started using the MFT_MESSAGE_NOTIFY_BEGIN_STREAMING message.

See [MFT_MESSAGE_COMMAND_DRAIN](https://learn.microsoft.com/windows/desktop/medfound/mft-message-command-drain).

### `MFT_MESSAGE_SET_D3D_MANAGER:0x2`

Sets or clears the [Direct3D Device Manager](https://learn.microsoft.com/windows/desktop/medfound/direct3d-device-manager) for DirectX Video Acceleration (DXVA).
Must be called before SetInputType or SetOutputType.

See [MFT_MESSAGE_SET_D3D_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mft-message-set-d3d-manager).

### `MFT_MESSAGE_DROP_SAMPLES:0x3`

**Note** Requires Windows 7.

### `MFT_MESSAGE_COMMAND_TICK:0x4`

**Note** Requires Windows 8.

### `MFT_MESSAGE_NOTIFY_BEGIN_STREAMING:0x10000000`

Notifies the MFT that streaming is about to begin.
Must be called after SetInputType and SetOutputType.

See [MFT_MESSAGE_NOTIFY_BEGIN_STREAMING](https://learn.microsoft.com/windows/desktop/medfound/mft-message-notify-begin-streaming).

### `MFT_MESSAGE_NOTIFY_END_STREAMING:0x10000001`

Notifies the MFT that streaming is about to end.

See [MFT_MESSAGE_NOTIFY_END_STREAMING](https://learn.microsoft.com/windows/desktop/medfound/mft-message-notify-end-streaming).

### `MFT_MESSAGE_NOTIFY_END_OF_STREAM:0x10000002`

Notifies the MFT that an input stream has ended.

See [MFT_MESSAGE_NOTIFY_END_OF_STREAM](https://learn.microsoft.com/windows/desktop/medfound/mft-message-notify-end-of-stream).

### `MFT_MESSAGE_NOTIFY_START_OF_STREAM:0x10000003`

Notifies the MFT that the first sample is about to be processed.
Must be called after SetInputType and SetOutputType.

See
[MFT_MESSAGE_NOTIFY_START_OF_STREAM](https://learn.microsoft.com/windows/desktop/medfound/mft-message-notify-start-of-stream).

### `MFT_MESSAGE_NOTIFY_RELEASE_RESOURCES:0x10000004`

### `MFT_MESSAGE_NOTIFY_REACQUIRE_RESOURCES:0x10000005`

### `MFT_MESSAGE_NOTIFY_EVENT:0x10000006`

### `MFT_MESSAGE_COMMAND_SET_OUTPUT_STREAM_STATE:0x10000007`

### `MFT_MESSAGE_COMMAND_FLUSH_OUTPUT_STREAM:0x10000008`

### `MFT_MESSAGE_COMMAND_MARKER:0x20000000`

Marks a point in the stream. This message applies only to asynchronous MFTs.

See [MFT_MESSAGE_COMMAND_MARKER](https://learn.microsoft.com/windows/desktop/medfound/mft-message-command-marker).

**Note** Requires Windows 7

## Remarks

Some messages require specific actions from the MFT. These events have "MESSAGE" in the message name. Other messages are informational; they notify the MFT of some action by the client, and do not require any particular response from the MFT. These messages have "NOTIFY" in the messages name. Except where noted, an MFT should not rely on the client sending notification messages.

## See also

[IMFTransform::ProcessMessage](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processmessage)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)