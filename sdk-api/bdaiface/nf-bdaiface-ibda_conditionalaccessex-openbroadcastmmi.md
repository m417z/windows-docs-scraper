# IBDA_ConditionalAccessEx::OpenBroadcastMmi

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Responds to a BroadcastMMI event.

When a device receives a BroadcastMMI event, it calls this method one time for each user interface (MMI) dialog box that is displayed to the user.

## Parameters

### `ulDialogRequest` [in]

A logical link with the MMI dialog box that was triggered by the action.

### `bstrLanguage` [in]

The language of the dialog box. This string contains an ISO 639-2 language code with a dash followed by an ISO 3166 country/region code.

### `EventId` [in]

The event identifier of the BroadcastMMI event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_ConditionalAccessEx](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccessex)