# NMCOMBOBOXEXW structure

## Description

Contains information specific to ComboBoxEx items for use with notification codes.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

The [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification code.

### `ceItem`

Type: **[COMBOBOXEXITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-comboboxexitema)**

The [COMBOBOXEXITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-comboboxexitema) structure that holds item information specific to the current notification. Upon receiving a notification code, the **COMBOBOXEXITEM** structure holds information required for the owner to respond. The members of this structure are often used as fields for the owner to return values in response to the notification.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMCOMBOBOXEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).