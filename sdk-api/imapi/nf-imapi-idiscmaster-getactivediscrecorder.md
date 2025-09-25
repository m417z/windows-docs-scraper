# IDiscMaster::GetActiveDiscRecorder

## Description

Retrieves an interface pointer to the active disc recorder. The active disc recorder is the recorder where a burn will occur when
[RecordDisc](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-recorddisc) is called.

## Parameters

### `ppRecorder` [out]

Pointer to the
[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder) interface of the currently selected disc recorder.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

There is no default active disc recorder. An application using this method must specifically select both an active mastering format and an active disc recorder before initiating a burn.

> [!NOTE]
> The active disc recorder can be invalidated by removing the device or changing the active disc mastering format. For example, a USB CD-R device may be disconnected from the machine while the application is still running (the application is alerted to this condition by a call to
[IDiscMasterProgressEvents::NotifyPnPActivity](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmasterprogressevents-notifypnpactivity)). In either case, you must select a new active disc recorder.

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)