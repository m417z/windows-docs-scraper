# D3DPERF_BeginEvent function

Marks the beginning of a user-defined event. PIX can use this event to trigger an action.

## Parameters

`col`

Event color. This is the color to display the event in the event view.

`wszName`

Event name.

## Return value

The zero-based level of the hierarchy that this event is starting in. If an error occurs, the return value will be negative.

## Remarks

User-defined events group together other events in a way that is meaningful to the target program so that they can be better represented in performance profiling tools. For example, a *Draw Spaceship* event might bracket a number of Direct3D calls that handle drawing a spaceship in a game. Events can be nested.

Each **D3DPERF_BeginEvent** call should have a matching **D3DPERF_EndEvent** call. Instantaneous events (which do not bracket other events) should be labeled by using **D3DPERF_SetMarker** rather than by **D3DPERF_BeginEvent** and **D3DPERF_EndEvent**.

## Requirements
|   |   |
| ---- |:---- |
| **Target Platform** | Windows |
| **Header** | d3d9.h |
| **Library** | d3d9.lib |
| **DLL** | d3d9.dll |