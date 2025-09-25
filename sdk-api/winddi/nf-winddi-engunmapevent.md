# EngUnmapEvent function

## Description

The **EngUnmapEvent** function cleans up the kernel-mode resources allocated for a mapped user-mode event.

## Parameters

### `pEvent` [in]

Pointer to an event object returned from a previous call to [EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent).

## Return value

**EngUnmapEvent** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## Remarks

The display driver should call **EngUnmapEvent** when it is notified that the process (typically [EngCreateDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedriverobj)) that created the user-mode event has terminated. The display driver can also call **EngUnmapEvent** to perform its own cleanup. The display and miniport drivers should not touch the event object after **EngUnmapEvent** has been called.

The display driver can call **EngUnmapEvent** only for an event object returned by [EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent). It must not call this function for an event object returned by [EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent).

## See also

[EngCreateDriverObj](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedriverobj)

[EngCreateEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreateevent)

[EngMapEvent](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapevent)