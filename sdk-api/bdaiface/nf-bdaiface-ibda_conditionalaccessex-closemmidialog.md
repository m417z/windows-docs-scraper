# IBDA_ConditionalAccessEx::CloseMmiDialog

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Notifies the Conditional Access Service (CAS) that the media sink device (MSD) has closed a user interface (MMI) dialog.

## Parameters

### `ulDialogRequest` [in]

A logical link with the user interface (MMI) dialog that was triggered by the action.

### `bstrLanguage` [in]

The language for any dialogs resulting from this action. This string contains an ISO 639-2 language code with a dash followed by an ISO 3166 country/region code.

### `ulDialogNumber` [in]

The dialog number of the dialog that was closed.

### `ReasonCode` [in]

The reason for closing the dialog, specified as a member of the [BDA_CONDITIONALACCESS_MMICLOSEREASON](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-conditionalaccess-mmiclosereason) enumeration.

### `pulSessionResult` [out]

Receives the result code for the MMI session. For more information, see *Protected Broadcast Driver Architecture, Part 1: Core Services - CAS*, section 2.6.6.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_ConditionalAccessEx](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccessex)