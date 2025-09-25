# IWMLicenseRevocationAgent::ProcessLRB

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **ProcessLRB** method removes licenses from the license store on the client computer.

## Parameters

### `pSignedLRB` [in]

Address of the signed license revocation blob in memory. This blob is sent to your application by the license server.

### `dwSignedLRBLength` [in]

Size of the license revocation blob in bytes.

### `pSignedACK` [out]

Address of a buffer that receives the signed acknowledgment of license revocation. Your application must send the acknowledgment to the license server.

### `pdwSignedACKLength` [out]

Size of the acknowledgment in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The license server sends the signed license revocation blob after receiving a response to its initial challenge message. For more information, see [GetLRBChallenge](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmlicenserevocationagent-getlrbchallenge).

## See also

[IWMLicenseRevocationAgent Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmlicenserevocationagent)