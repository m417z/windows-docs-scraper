# PFN_WdsTransportClientReceiveContents callback function

## Description

The PFN_WdsTransportClientReceiveContents callback is used by the multicast client to indicate that a block of data is ready to be used.

## Parameters

### `hSessionKey` [in]

The handle belonging to the session that is being started.

### `pCallerData` [in]

Pointer to the user data for this session. This data was specified in the call to the [WdsTransportClientStartSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientstartsession) function.

### `pContents`

### `ulSize` [in]

The size of the data in *pCallerData*.

### `pullContentOffset`

#### - pContentOffset [in]

The offset in the data stream where this block of data starts.

#### - pMetadata [in]

Pointer to the buffer location that has received the content. The size of this buffer in bytes is given by *ulSize*.