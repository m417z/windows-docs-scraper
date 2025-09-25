# _DXGK_INHERITED_TIMING_INFO structure

## Description

Structure passed to the driver in the pPrivateDriverData argument of DxgkDdiRecommendFunctionalVidPn, which the driver should use to describe the color space and wire format which cannot be described easily in the VidPn the DDI builds

## Members

### `OutputColorSpace`

A D3DDDI_COLOR_SPACE_TYPE value which describes the output color space currently being applied for the transported pixels. The driver is responsible for sending appropriate metadata to ensure the display device is set up to interpret pixels correctly for this color space.

### `OutputWireColorSpace`

### `SelectedWireFormat`

A D3DKMDT_WIRE_FORMAT_AND_PREFERENCE value which indicates the wire format which is actually being used. Although the target mode pinned in the VidPn returned by the call to DxgkDdiRecommendFunctionalVidPn could be required to describe exactly one wire format, that might require the driver to prepare a special target mode just for the boot case. Instead, this field should be used to report the current wire color encoding format and bits per color channel. Whichever format is reported in this field should also have been reported as supported in the target mode reported through DxgkDdiRecommendFunctionalVidPn.

### `GlitchCause`

A DXGK_GLITCH_CAUSE value which indicates what underlying change or changes in the display pipeline caused a user perceptible glitch.

### `GlitchEffect`

A DXGK_GLITCH_EFFECT value which indicates what the glitch looked like to a user.

### `GlitchDuration`

A DXGK_GLITCH_DURATION value which indicates approximately how long the glitch lasted. Note, this is intended to reflect how long the underlying issue was present but the visible effect may be longer in some cases. For example, when sync is lost long enough for a monitor to have to redetect, the display device will likely take many frames to recover. It is the length of the underlying issue which should be reported, not the recovery time as that will vary between devices.

### `Reserved`

This value is reserved for system use.

### `DiagnosticInfo`

Set of information filled out by the driver for the boot display to describe any side-effects of the DxgkDdiStartDevice.

In many cases, glitches are inevitable so these fields attempt to understand the underlying cause and the extend of the user impact. OEMs and customers often complain about glitches during boot so having the driver report the glitch to the OS should help to investigate such issues quickly.