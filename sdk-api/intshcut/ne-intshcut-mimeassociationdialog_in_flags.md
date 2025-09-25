# MIMEASSOCIATIONDIALOG_IN_FLAGS enumeration

## Description

Used with the [MIMEAssociationDialog](https://learn.microsoft.com/windows/desktop/api/intshcut/nf-intshcut-mimeassociationdialoga) function to determine how it executes.

## Constants

### `MIMEASSOCDLG_FL_REGISTER_ASSOC:0x0001`

If this bit is set, the selected application is registered as the handler for the given MIME type. If this bit is clear, no association is registered.

## Remarks

An application is registered only if this flag is set and the user indicates that a persistent association is to be made.