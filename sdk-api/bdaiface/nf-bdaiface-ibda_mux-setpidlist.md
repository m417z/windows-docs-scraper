# IBDA_MUX::SetPidList

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sets the list of packet identifiers (PIDs) that are enabled to go across the Protected Broadcast Driver Architecture (PBDA) interface.

## Parameters

### `ulPidListCount` [in]

The number of elements in the *pbPidListBuffer* array.

### `pbPidListBuffer` [in]

Pointer to an array of [BDA_MUX_PIDLISTITEM](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-mux-pidlistitem) structures.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_MUX](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_mux)