# IBDA_ConditionalAccess::GetModuleUI

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetModuleUI** method retrieves the URL for a user interface dialog.

## Parameters

### `byDialogNumber` [in]

Specifies the dialog number.

### `pbstrURL` [out]

Pointer to a pointer variable that receives a pointer to a string containing the URL. When the string is no longer required, call the **SysFreeString** function to free it.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IBDA_ConditionalAccess Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccess)