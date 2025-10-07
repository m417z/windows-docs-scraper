# DOSwarmStats structure

Contains fields for download and upload statistics for a file.

## Members

**fileId**

Null-terminated string that was specified with the **AddFileWithRanges** call.

**sourceURL**

Null-terminated string that contains the name of the file on the server (for example, https://<server>/<path>/file.ext).

**fileSize**

Size of the file in bytes.

**totalBytesDownloaded**

Total number of bytes transferred.

**bytesFromLanPeers**

Number of bytes transferred from LAN peers.

**bytesFromGroupPeers**

Number of bytes transferred from group peers.

**bytesFromInternetPeers**

Number of bytes transferred from Internet peers.

**bytesFromHttp**

Number of bytes transferred from http.

**bytesFromDoinc**

For internal use only.

**bytesToLanPeers**

Number of bytes transferred to LAN peers.

**bytesToGroupPeers**

Number of bytes transferred to group peers.

**bytesToInternetPeers**

Number of bytes transferred to Internet peers.

**httpConnectionCount**

Count of http connections.

**doincConnectionCount**

For internal use only.

**lanConnectionCount**

Count of LAN connections.

**groupConnectionCount**

Count of group connections.

**internetConnectionCount**

Count of Internet connections.

**downloadDuration**

Duration of the file transfer in milliseconds.

**downloadMode**

The download mode used, see [**DownloadMode**](https://learn.microsoft.com/windows/win32/delivery_optimization/downloadmode).

**status**

The status of a file transfer, see [**SwarmStatus**](https://learn.microsoft.com/windows/win32/delivery_optimization/swarmstatus).

**isBackground**

True, if this is a background transfer.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

