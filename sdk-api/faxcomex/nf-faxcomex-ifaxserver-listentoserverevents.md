# IFaxServer::ListenToServerEvents

## Description

The **IFaxServer::ListenToServerEvents** method registers the [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver) object to receive notifications about one or more types of server events, or to stop these notifications.

## Parameters

### `EventTypes` [in]

Type: **[FAX_SERVER_EVENTS_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum)**

A value that contains a set of bit flags representing the types of events for which the [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver) object is registering to receive notifications. For more information, see [FAX_SERVER_EVENTS_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In Microsoft Visual Basic, if you want the fax server to receive notifications, you have to create the [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver) object using the following syntax:

```

Dim WithEvents objFaxServer As New FAXCOMEXLib.FaxServer
Set objFaxServer = CreateObject("FaxServer")

```

In Microsoft Visual C++, the [IFaxServerNotify](https://learn.microsoft.com/windows/desktop/api/faxcomex/nn-faxcomex-ifaxservernotify2) interface on the **FaxServer** object receives notifications of the events.

By default, the [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver) object does not receive notifications for any server events. If you want the **FaxServer** object to receive notifications, you must call **IFaxServer::ListenToServerEvents** and pass to it the event types for which you want to receive notifications. To stop receiving the notification, call this method with *EventTypes* equal to [fsetNONE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum).

Access rights for this method depend on which events are requested, as shown in the following table.

|  |  |
| --- | --- |
| Event | Required access rights |
| [fsetINCOMING_CALL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
| [fsetIN_QUEUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
|  | [farQUERY_JOBS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
| [fsetOUT_QUEUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
|  | [farQUERY_JOBS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
| [fsetCONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
| [fsetDEVICE_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
| [fsetACTIVITY](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
| [fsetIN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farSUBMIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
|  | [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
| [fsetOUT_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_server_events_type_enum) | [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |
|  | [farQUERY_OUT_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) |

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)

[Registering for Event Notifications](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-event-notifications)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-fax-events)