# IBDA_MUX::GetPidList

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the list of packet identifiers (PIDs) that are enabled to go across the Protected Broadcast Driver Architecture (PBDA) interface.

## Parameters

### `pulPidListCount` [in, out]

On input, specifies the size, in array elements, of the *pbPidListBuffer* array. On output, receives the number of PIDs.

### `pbPidListBuffer` [in, out]

Pointer to an array of [BDA_MUX_PIDLISTITEM](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-mux-pidlistitem) structures. The method fills in the array with the list of PIDs.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOT_SUFFICIENT_BUFFER** | The *pbPidListBuffer* array is too small. |

## Remarks

If the *pbPidListBuffer* array is too small, the method returns **E_NOT_SUFFICIENT_BUFFER** and sets the required size in the *pulPidListCount* parameter.

## See also

[IBDA_MUX](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_mux)