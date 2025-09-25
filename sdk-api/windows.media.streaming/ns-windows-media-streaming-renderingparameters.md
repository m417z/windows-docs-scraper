# RenderingParameters structure

## Description

Contains the current values of rendering parameters on the DMR.

## Members

### `streaming.RenderingParameters.volume`

### `streaming.RenderingParameters.mute`

### `mute`

This value is **True** if audio is currently muted on the DMR, and is **False** otherwise.

### `volume`

The current audio volume level of the device, in the range 0 to 100, or -1 if the device does not support controlling the volume level. A value of 0 is the lowest volume and a value of 100 is the highest.