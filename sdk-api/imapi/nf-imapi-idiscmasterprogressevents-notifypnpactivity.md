# IDiscMasterProgressEvents::NotifyPnPActivity

## Description

Notifies the application that there is a change to the list of valid disc recorders. (For example, a USB CD-R driver is removed from the system.)

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

An application should respond by calling
[IDiscMaster::EnumDiscRecorders](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-enumdiscrecorders) to update its list of valid recorders. If the current active recorder has been invalidated, then a new recorder should be chosen.

## See also

[IDiscMasterProgressEvents](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmasterprogressevents)