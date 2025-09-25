# MFCreateSequencerSource function

## Description

Creates the sequencer source.

## Parameters

### `pReserved`

Reserved. Must be **NULL**.

### `ppSequencerSource`

Receives a pointer to the [IMFSequencerSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsequencersource) interface of the sequencer source. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/sequencer-source)