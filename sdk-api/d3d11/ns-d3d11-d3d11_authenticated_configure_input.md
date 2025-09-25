# D3D11_AUTHENTICATED_CONFIGURE_INPUT structure

## Description

Contains input data for the [ID3D11VideoContext::ConfigureAuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-configureauthenticatedchannel) method.

## Members

### `omac`

A [D3D11_OMAC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_omac) structure that contains a Message Authentication Code (MAC) of the data. The driver uses AES-based one-key CBC MAC (OMAC) to calculate this value for the block of data that appears after this structure member.

### `ConfigureType`

A GUID that specifies the command. The following GUIDs are defined.

| Value | Meaning |
| --- | --- |
| **D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION** | Associates a cryptographic session with a decoder device and a Direct3D device.<br><br>Input data: [D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_crypto_session_input) |
| **D3D11_AUTHENTICATED_CONFIGURE_ENCRYPTION_WHEN_ACCESSIBLE** | Sets the level of encryption that is performed before protected content becomes accessible to the CPU or bus.<br><br>Input data: [D3D11_AUTHENTICATED_CONFIGURE_ACCESSIBLE_ENCRYPTION_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_accessible_encryption_input) |
| **D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE** | Initializes the authenticated channel.<br><br>Input data: [D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_initialize_input) |
| **D3D11_AUTHENTICATED_CONFIGURE_PROTECTION** | Enables or disables protection for the device.<br><br>Input data: [D3D11_AUTHENTICATED_CONFIGURE_PROTECTION_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_protection_input) |
| **D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE** | Enables a process to open a shared resource, or disables a process from opening shared resources.<br><br>Input data: [D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_configure_shared_resource_input) |

### `hChannel`

A handle to the authenticated channel. To get the handle, call the [ID3D11AuthenticatedChannel::GetChannelHandle](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11authenticatedchannel-getchannelhandle) method.

### `SequenceNumber`

The query sequence number. At the start of the session, generate a cryptographically secure 32-bit random number to use as the starting sequence number. For each query, increment the sequence number by 1.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)