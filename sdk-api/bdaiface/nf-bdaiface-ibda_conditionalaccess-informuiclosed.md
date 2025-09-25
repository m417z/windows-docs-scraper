# IBDA_ConditionalAccess::InformUIClosed

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **InformUIClosed** method informs the device that the user-interface dialog is closed.

## Parameters

### `byDialogNumber` [in]

Specifies the dialog number.

### `CloseReason` [in]

Specifies the reason for closing the dialog, as a member of the [UICloseReasonType](https://learn.microsoft.com/windows/desktop/api/bdaiface/ne-bdaiface-uiclosereasontype) enumeration.

## Return value

If the method succeeds, it returns **S_OK**. It returns **S_FALSE** if a dialog with the specified dialog number cannot be found. If the method fails, it returns an error code.

## See also

[IBDA_ConditionalAccess Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccess)