# ITDirectory::Connect

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**Connect** method establishes a connection to the directory server.

## Parameters

### `fSecure` [in]

Boolean indicator of whether to use SSL connection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **RND_ALREADY_CONNECTED** | A successful connection has already been made. |
| **RND_NULL_SERVER_NAME** | The server name is **NULL**, probably because [ITConferenceBlob::Init](https://learn.microsoft.com/windows/desktop/Tapi/itconferenceblob-init) has not been run or did not succeed. |

## Remarks

The
**Connect** method must be successfully called before any other function except
[get_DirectoryType](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itdirectory-get_directorytype).

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)