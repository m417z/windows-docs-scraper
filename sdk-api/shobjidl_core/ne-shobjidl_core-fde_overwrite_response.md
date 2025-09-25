# FDE_OVERWRITE_RESPONSE enumeration

## Description

Specifies the values used by the [IFileDialogEvents::OnOverwrite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogevents-onoverwrite) method to indicate an application's response to an overwrite request during a save operation using the common file dialog.

## Constants

### `FDEOR_DEFAULT:0`

The application has not handled the event. The dialog displays a UI asking the user whether the file should be overwritten and returned from the dialog.

### `FDEOR_ACCEPT:1`

The application has determined that the file should be returned from the dialog.

### `FDEOR_REFUSE:2`

The application has determined that the file should not be returned from the dialog.