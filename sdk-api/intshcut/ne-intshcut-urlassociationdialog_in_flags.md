# URLASSOCIATIONDIALOG_IN_FLAGS enumeration

## Description

The **URLASSOCIATIONDIALOG_IN_FLAGS** enumerated values are used with [URLAssociationDialog](https://learn.microsoft.com/windows/desktop/api/intshcut/nf-intshcut-urlassociationdialoga) to determine how it executes.

## Constants

### `URLASSOCDLG_FL_USE_DEFAULT_NAME:0x0001`

Use the default file name (that is, "Internet Shortcut").

### `URLASSOCDLG_FL_REGISTER_ASSOC:0x0002`

Register the selected application as the handler for the protocol specified in the *pcszURL* parameter of [URLAssociationDialog](https://learn.microsoft.com/windows/desktop/api/intshcut/nf-intshcut-urlassociationdialoga). The application is registered only if this flag is set and the user indicates that a persistent association is desired.