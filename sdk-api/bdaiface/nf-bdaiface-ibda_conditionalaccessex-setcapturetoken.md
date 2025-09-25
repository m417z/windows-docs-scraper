# IBDA_ConditionalAccessEx::SetCaptureToken

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Requests special events that are identified by a capture token.

A *capture token* is a binary blob that indicates a specific purchase option for content.

## Parameters

### `ulcbCaptureTokenLen` [in]

The size, in bytes, of the *pbCaptureToken* array.

### `pbCaptureToken` [in]

Pointer to a byte array that contains the capture token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_ConditionalAccessEx](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccessex)