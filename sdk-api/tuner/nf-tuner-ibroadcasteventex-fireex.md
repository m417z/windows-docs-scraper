# IBroadcastEventEx::FireEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **FireEx** method fires a broadcast event.

## Parameters

### `EventID` [in]

GUID that specifies the event.

### `Param1` [in]

Specifies the first implementation-dependent parameter.

### `Param2` [in]

Specifies the second implementation-dependent parameter.

### `Param3` [in]

Specifies the third implementation-dependent parameter.

### `Param4` [in]

Specifies the fourth implementation-dependent parameter.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is similar to [IBroadcastEvent::Fire](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ibroadcastevent-fire), but it includes four additional parameters for passing implementation-dependent information between the object that fires the event and the objects that wait on the event. The designer who implements the objects must determine what meaning, if any, to assign to these parameters.

## See also

[IBroadcastEventEx Interface](https://learn.microsoft.com/previous-versions/dd376295(v=vs.85))

[Video Control Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/video-control-interfaces)