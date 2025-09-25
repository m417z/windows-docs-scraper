# ITextInputPanelRunInfo::IsTipRunning

## Description

Indicates if the Tablet PC Input Panel is running at the time the method is called.

## Parameters

### `pfRunning` [out]

**TRUE** if the Input Panel was running, otherwise **FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The *pfRunning* parameter has been set appropriately. |
| **E_POINTER** | The *pfRunning* parameter was **NULL**. |

## See also

[ITextInputPanelRunInfo Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanelruninfo)