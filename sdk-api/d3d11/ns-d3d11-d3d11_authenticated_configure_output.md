# D3D11_AUTHENTICATED_CONFIGURE_OUTPUT structure

## Description

Contains the response from the [ID3D11VideoContext::ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-configureauthenticatedchannel) method.

## Members

### `omac`

A [D3D11_OMAC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_omac) structure that contains a Message Authentication Code (MAC) of the data. The driver uses AES-based one-key CBC MAC (OMAC) to calculate this value for the block of data that appears after this structure member.

### `ConfigureType`

A GUID that specifies the command. For a list of GUIDs, see [D3D11_AUTHENTICATED_CONFIGURE_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_input).

### `hChannel`

A handle to the authenticated channel.

### `SequenceNumber`

The command sequence number.

### `ReturnCode`

The result code for the command.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)