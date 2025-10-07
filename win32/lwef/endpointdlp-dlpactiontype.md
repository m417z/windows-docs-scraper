# DlpActionType enumeration

Specifies the action type of an endpoint Data Loss Prevention (DLP) operation.

## Constants

*DlpActionTypeCopyToRemovableMedia*

A copy operation to removable media.

*DlpActionTypeCopyToNetworkShare*

A copy operation to a shared network folder.

*DlpActionTypeCopyToClipboard*

A copy operation to the clipboard.

*DlpActionTypePrint*

A print operation.

*DlpActionTypeScreenClip*

A screen capture operation.

*DlpActionTypeAccessByUnallowedApp*

An operation performed by an unallowed app.

*DlpActionTypeCloudAppEgress*

An operation targeted to a cloud location.

*DlpActionTypeAccessByBluetoothApp*

An operation that includes access by a bluetooth app.

*DlpActionTypeAccessByRDPApp*

An operation that includes access by a remote desktop.

*DlpActionTypeCount*

The maximum value of the enumeration.

## Remarks

Values from this enumeration are used by the [DLP_APP_OP_ENLIGHTENED_LEVEL](https://learn.microsoft.com/windows/win32/lwef/endpointdlp-dlp_app_op_enlightened_level) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1809 (10.0; Build 17763) |