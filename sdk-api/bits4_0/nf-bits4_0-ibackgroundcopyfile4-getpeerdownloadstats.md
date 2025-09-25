# IBackgroundCopyFile4::GetPeerDownloadStats

## Description

Specifies statistics about the amount of data downloaded from peers and origin servers.

## Parameters

### `pFromOrigin` [out]

Specifies the amount of file data downloaded from the originating server.

### `pFromPeers` [out]

Specifies the amount of file data downloaded from a peer-to-peer source.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBackgroundCopyFile4](https://learn.microsoft.com/windows/desktop/api/bits4_0/nn-bits4_0-ibackgroundcopyfile4)