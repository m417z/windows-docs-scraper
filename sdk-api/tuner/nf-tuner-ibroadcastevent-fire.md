# IBroadcastEvent::Fire

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Fire** method fires a broadcast event.

## Parameters

### `EventID`

GUID that specifies the event.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

For television tuning, the following event is defined.

| Tuner Event | Description |
| --- | --- |
| EVENTID_TuningChanged | Fired when the tuner changes stations or channels. Defined in Bdamedia.h. |

For a list of events fired by the TV ratings components, see [TV Ratings Broadcast Events](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tv-ratings-broadcast-events).

## See also

[IBroadcastEvent Interface](https://learn.microsoft.com/previous-versions/dd376294(v=vs.85))

[TV Ratings Broadcast Events](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tv-ratings-broadcast-events)