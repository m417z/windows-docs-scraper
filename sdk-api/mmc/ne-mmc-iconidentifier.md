# IconIdentifier enumeration

## Description

The
**IconIdentifier** enumeration is introduced in MMC 1.2.

The
**IconIdentifier** enumeration defines the types of icons that can appear in error messages displayed by the snap-in when
[using the MMC message OCX control](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-mmc-message-ocx-control).

## Constants

### `Icon_None:0`

No icon displayed in error message.

### `Icon_Error:32513`

Error icon displayed in error message.

### `Icon_Question:32514`

Question icon displayed in error message.

### `Icon_Warning:32515`

Warning icon displayed in error message.

### `Icon_Information:32516`

Information icon displayed in error message.

### `Icon_First:Icon_Error`

Used internally by MMC.

### `Icon_Last`

Used internally by MMC.

## See also

[IMessageView](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-imessageview)

[Using the MMC Message OCX Control](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-the-mmc-message-ocx-control)