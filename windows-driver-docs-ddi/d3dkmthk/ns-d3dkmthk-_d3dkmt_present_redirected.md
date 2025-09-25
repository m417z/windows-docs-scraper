# _D3DKMT_PRESENT_REDIRECTED structure

## Description

Used to give information on the status of the present history token.

## Members

### `hDevice` [in]

Device associated with the present

### `hSyncObj` [in]

The sync object that the PHT waits on.

### `WaitedFenceValue` [in]

The fence value of hSyncObj that PHT waits on

### `PresentHistoryToken` [in]

The present history token.

### `Flags`

The flags needed to give the status of the present history token.

### `hSource` [in]

Source allocation to present from

### `PrivateDriverDataSize` [in]

The size of pPrivateDriverData.

### `pPrivateDriverData` [in]

Private driver data to pass to DdiPresent and DdiSetVidPnSourceAddress