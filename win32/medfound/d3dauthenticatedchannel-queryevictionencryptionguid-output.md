# D3DAUTHENTICATEDCHANNEL\_QUERYEVICTIONENCRYPTIONGUID\_OUTPUT structure

Contains the response to a [**D3DAUTHENTICATEDQUERY\_ENCRYPTIONWHENACCESSIBLEGUID**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedquery-encryptionwhenaccessibleguid) query.

To send this query, call [**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query).

## Members

**D3DAUTHENTICATEDCHANNEL\_QUERY\_OUTPUT**

A [**D3DAUTHENTICATEDCHANNEL\_QUERY\_OUTPUT**](https://learn.microsoft.com/windows/win32/medfound/d3dauthenticatedchannel-query-output) structure that contains a Message Authentication Code (MAC) and other data.

**EncryptionGuidIndex**

The index of the encryption GUID.

**EncryptionGuid**

A GUID that specifies a supported encryption type.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h |

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-structures)

[**IDirect3DAuthenticatedChannel9::Query**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dauthenticatedchannel9-query)

