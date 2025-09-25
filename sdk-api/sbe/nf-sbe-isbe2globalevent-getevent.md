# ISBE2GlobalEvent::GetEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a global spanning event and its data from a [Stream Buffer Source](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter) filter.

## Parameters

### `idEvt` [in]

GUID identifying the event.

### `param1` [in]

First event-specific parameter.

### `param2` [in]

Second event-specific parameter.

### `param3` [in]

Third event-specific parameter.

### `param4` [in]

Fourth event-specific parameter.

### `pSpanning` [out]

Receives a flag indicating whether the event is a spanning event.

### `pcb` [in, out]

Pointer to a value specifying the buffer size. If the *pb* parameter is **NULL**, this parameter returns the required buffer size.

### `pb` [out]

Pointer to a buffer that receives the event data. If this parameter is **NULL**, the *pcb* parameter returns the required buffer size. The structure of the event data depends on the event type. For a list of event types, see the description of the [ISBE2SpanningEvent::GetEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2spanningevent-getevent) method.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return value | Description |
| --- | --- |
| S_OK | Success. |
| ERROR_INSUFFICIENT_BUFFER | Buffer was too small to hold event data. |
| ERROR_CONTEXT_EXPIRED | Too much time elapsed between the broadcast event and the call to retrieve it. |

## See also

[ISBE2GlobalEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2globalevent)

[ISBE2SpanningEvent::GetEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2spanningevent-getevent)

[Stream Buffer Source Filter](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/stream-buffer-source-filter)