# D3D11_AUTHENTICATED_QUERY_OUTPUT structure

## Description

Contains a response from the [ID3D11VideoContext::QueryAuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-queryauthenticatedchannel) method.

## Members

### `omac`

A [D3D11_OMAC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_omac) structure that contains a Message Authentication Code (MAC) of the data. The driver uses AESbased one-key CBC MAC (OMAC) to calculate this value for the block of data that appears after this structure member.

### `QueryType`

A GUID that specifies the query. For a list of possible values, see [D3D11_AUTHENTICATED_QUERY_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_input)

### `hChannel`

A handle to the authenticated channel. To get the handle, call the [ID3D11AuthenticatedChannel::GetChannelHandle](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11authenticatedchannel-getchannelhandle) method.

### `SequenceNumber`

The query sequence number.

### `ReturnCode`

The result code for the query.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)