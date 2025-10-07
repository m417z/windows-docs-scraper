# D3DPERF_SetMarker function

Mark an instantaneous event. PIX can use this event to trigger an action.

## Parameters

`col`

Event color. This is the color to display the event in the event view.

`wszName`

Event name.

## Return value

This function doesn't return a value.

## Remarks

Instantaneous user events do not bracket or group other events. For example, when the user fires a weapon in a game, a *Shot Fired* event could be created by a **D3DPERF_SetMarker** call. To group together multiple events under a single, user-defined name, use **D3DPERF_BeginEvent** and **D3DPERF_EndEvent** rather than **D3DPERF_SetMarker**.

## Requirements
|   |   |
| ---- |:---- |
| **Target Platform** | Windows |
| **Header** | d3d9.h |
| **Library** | d3d9.lib |
| **DLL** | d3d9.dll |