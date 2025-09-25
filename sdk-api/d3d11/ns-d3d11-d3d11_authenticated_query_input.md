# D3D11_AUTHENTICATED_QUERY_INPUT structure

## Description

Contains input data for the [ID3D11VideoContext::QueryAuthenticatedChannel](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-queryauthenticatedchannel) method.

## Members

### `QueryType`

A GUID that specifies the query. The following GUIDs are defined.

| Value | Meaning |
| --- | --- |
| **D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ATTRIBUTES** | Returns the type of I/O bus that is used to send data to the GPU.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_authenticated_query_accessibility_output) |
| **D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE** | Returns the type of authenticated channel.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_channel_type_output) |
| **D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION** | Returns handles to the cryptographic session and Direct3D device that are associated with a specified decoder device.<br><br>Input data structure: [D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_crypto_session_input)<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_crypto_session_output) |
| **D3D11_AUTHENTICATED_QUERY_CURRENT_ENCRYPTION_WHEN_ACCESSIBLE** | Returns the encryption type that is applied before content becomes accessible to the CPU or bus.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_accessibility_encryption_guid_count_output) |
| **D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE** | Returns a handle to the device that is associated with this authenticated channel.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_device_handle_output) |
| **D3D11_AUTHENTICATED_QUERY_ENCRYPTION_WHEN_ACCESSIBLE_GUID** | Returns one of the encryption types that can be used to encrypt content before it becomes accessible to the CPU or bus.<br><br>Input data structure: [D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_accessibility_encryption_guid_input)<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_accessibility_encryption_guid_output) |
| **D3D11_AUTHENTICATED_QUERY_ENCRYPTION_WHEN_ACCESSIBLE_GUID_COUNT** | Returns the number of encryption types that can be used to encrypt content before it becomes accessible to the CPU or bus.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ENCRYPTION_GUID_COUNT_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_accessibility_encryption_guid_count_output) |
| **D3D11_AUTHENTICATED_QUERY_OUTPUT_ID** | Returns one of the output identifiers that is associated with a specified cryptographic session and Direct3D device.<br><br>Input data structure: [D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output_id_input)<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output_id_output) |
| **D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT** | Returns the number of output identifiers that are associated with a specified cryptographic session and Direct3D device.<br><br>Input data structure: [D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output_id_count_input)<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_output_id_count_output) |
| **D3D11_AUTHENTICATED_QUERY_PROTECTION** | Returns the current protection level for the device.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_PROTECTION_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_protection_output) |
| **D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS** | Returns information about a process that is allowed to open shared resources with restricted access.<br><br>Input data structure: [D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_INPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_restricted_shared_resource_process_input)<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_restricted_shared_resource_process_output) |
| **D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT** | Returns the number of processes that are allowed to open shared resources with restricted access.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_restricted_shared_resource_process_count_output) |
| **D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT** | Returns the number of protected shared resources that can be opened by any process with no restrictions.<br><br>Output data structure: [D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT_OUTPUT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_authenticated_query_unrestricted_protected_shared_resource_count_output) |

### `hChannel`

A handle to the authenticated channel. To get the handle, call the [ID3D11AuthenticatedChannel::GetChannelHandle](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11authenticatedchannel-getchannelhandle) method.

### `SequenceNumber`

The query sequence number. At the start of the session, generate a cryptographically secure 32-bit random number to use as the starting sequence number. For each query, increment the sequence number by 1.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)