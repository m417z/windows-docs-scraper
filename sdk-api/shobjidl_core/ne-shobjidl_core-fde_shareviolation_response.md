# FDE_SHAREVIOLATION_RESPONSE enumeration

## Description

Specifies the values used by the [IFileDialogEvents::OnShareViolation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogevents-onshareviolation) method to indicate an application's response to a sharing violation that occurs when a file is opened or saved.

## Constants

### `FDESVR_DEFAULT:0`

The application has not handled the event. The dialog displays a UI that indicates that the file is in use and a different file must be chosen.

### `FDESVR_ACCEPT:1`

The application has determined that the file should be returned from the dialog.

### `FDESVR_REFUSE:2`

The application has determined that the file should not be returned from the dialog.