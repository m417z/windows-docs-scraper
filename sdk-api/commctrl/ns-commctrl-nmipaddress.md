# NMIPADDRESS structure

## Description

Contains information for the [IPN_FIELDCHANGED](https://learn.microsoft.com/windows/desktop/Controls/ipn-fieldchanged) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `iField`

Type: **int**

The zero-based number of the field that was changed.

### `iValue`

Type: **int**

The new value of the field specified in the
**iField** member. While processing the [IPN_FIELDCHANGED](https://learn.microsoft.com/windows/desktop/Controls/ipn-fieldchanged) notification, this member can be set to any value that is within the range of the field and the control will place this new value in the field.