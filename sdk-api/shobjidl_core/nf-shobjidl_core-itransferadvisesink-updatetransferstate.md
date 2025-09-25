# ITransferAdviseSink::UpdateTransferState

## Description

Updates the transfer state.

## Parameters

### `ts` [in]

Type: **TRANSFER_ADVISE_STATE**

The transfer state. One of the following values.

#### TS_NONE (0x00000000)

0x00000000. No transfer is in progress.

#### TS_PERFORMING (0x00000001)

0x00000001. The transfer is being performed.

#### TS_PREPARING (0x00000002)

0x00000002. The transfer is preparing to begin. For example, this flag would be set when space requirements are being calculated.

#### TS_INDETERMINATE (0x00000004)

0x00000004. Length of the transfer is unknown.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.