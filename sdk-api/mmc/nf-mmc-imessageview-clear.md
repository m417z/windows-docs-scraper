# IMessageView::Clear

## Description

The **IMessageView::Clear** method enables a snap-in to clear the title, text, and icon of the result pane message displayed using the MMC message OCX control.

## Return value

This method can return one of these values.

## Remarks

The
Clear method provides a way to reset the content of the message, but the snap-in is not required to call this method to release resources. MMC creates its own copies of the strings passed to it when the snap-in calls the [IMessageView::SetTitleText](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-imessageview-settitletext) and [IMessageView::SetBodyText](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-imessageview-setbodytext) methods. The snap-in can release the resources after calling
SetTitleText and
SetBodyText.

## See also

[IMessageView](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-imessageview)

[Using the MMC Message OCX Control](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-mmc-message-ocx-control)