# IMessageView::SetTitleText

## Description

The **IMessageView::SetTitleText** method enables a snap-in to set the title text for the result pane message displayed using the MMC message OCX control.

## Parameters

### `pszTitleText` [in]

A pointer to a null-terminated string that contains the title text for the result pane message.

## Return value

This method can return one of these values.

## Remarks

MMC creates its own copies of the strings passed to it when the snap-in calls the IMessageView::SetTitleText and IMessageView::SetBodyText methods. The snap-in can release the resources at any time after calling
**SetTitleText** and
**SetBodyText**.

## See also

[IMessageView](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-imessageview)

[Using the MMC Message OCX Control](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-mmc-message-ocx-control)