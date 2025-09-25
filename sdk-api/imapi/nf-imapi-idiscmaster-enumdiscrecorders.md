# IDiscMaster::EnumDiscRecorders

## Description

Retrieves an enumerator for all disc recorders supported by the active disc master format.

## Parameters

### `ppEnum` [out]

Address of a pointer to the **IEnumDiscRecorders** enumerator.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

**IEnumDiscRecorders** is a standard COM enumerator, as documented in
**IEnumXXXX**. Each call to **Next** returns an array of pointers to
[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder). Each recorder interface represents a single available recorder already associated with an underlying physical disc recorder.

The list of available recorders may change due to Plug and Play arrivals or departures, or a call to
[SetActiveDiscMasterFormat](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-setactivediscmasterformat). An application is notified of these changes when it receives a call to
[IDiscMasterProgressEvents::NotifyPnPActivity](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmasterprogressevents-notifypnpactivity). When a change occurs, the application should call this method again to retrieve a new enumerator, because each enumerator contains a snapshot of the devices supported at the time of the enumeration.

When a device is removed, its pointer and
[IDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscrecorder) interface must remain valid even though the underlying physical device is missing. In this case, operations on an
**IDiscRecorder** or a request to record a disc may return IMAPI_E_DEVICE_NOTPRESENT.

The **MaxWriteSpeed** property is updated when this method is called. The default setting is the highest available write speed.

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)