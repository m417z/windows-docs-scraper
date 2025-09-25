# DWM_TIMING_INFO structure

## Description

Specifies Desktop Window Manager (DWM) composition timing information. Used by the [DwmGetCompositionTimingInfo](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmgetcompositiontiminginfo) function.

## Members

### `cbSize`

The size of this **DWM_TIMING_INFO** structure.

### `rateRefresh`

The monitor refresh rate.

### `qpcRefreshPeriod`

The monitor refresh period.

### `rateCompose`

The composition rate.

### `qpcVBlank`

The query performance counter value before the vertical blank.

### `cRefresh`

The DWM refresh counter.

### `cDXRefresh`

The DirectX refresh counter.

### `qpcCompose`

The query performance counter value for a frame composition.

### `cFrame`

The frame number that was composed at **qpcCompose**.

### `cDXPresent`

The DirectX present number used to identify rendering frames.

### `cRefreshFrame`

The refresh count of the frame that was composed at **qpcCompose**.

### `cFrameSubmitted`

The DWM frame number that was last submitted.

### `cDXPresentSubmitted`

The DirectX present number that was last submitted.

### `cFrameConfirmed`

The DWM frame number that was last confirmed as presented.

### `cDXPresentConfirmed`

The DirectX present number that was last confirmed as presented.

### `cRefreshConfirmed`

The target refresh count of the last frame confirmed as completed by the GPU.

### `cDXRefreshConfirmed`

The DirectX refresh count when the frame was confirmed as presented.

### `cFramesLate`

The number of frames the DWM presented late.

### `cFramesOutstanding`

The number of composition frames that have been issued but have not been confirmed as completed.

### `cFrameDisplayed`

The last frame displayed.

### `qpcFrameDisplayed`

The QPC time of the composition pass when the frame was displayed.

### `cRefreshFrameDisplayed`

The vertical refresh count when the frame should have become visible.

### `cFrameComplete`

The ID of the last frame marked as completed.

### `qpcFrameComplete`

The QPC time when the last frame was marked as completed.

### `cFramePending`

The ID of the last frame marked as pending.

### `qpcFramePending`

The QPC time when the last frame was marked as pending.

### `cFramesDisplayed`

The number of unique frames displayed. This value is valid only after a second call to the [DwmGetCompositionTimingInfo](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmgetcompositiontiminginfo) function.

### `cFramesComplete`

The number of new completed frames that have been received.

### `cFramesPending`

The number of new frames submitted to DirectX but not yet completed.

### `cFramesAvailable`

The number of frames available but not displayed, used, or dropped. This value is valid only after a second call to [DwmGetCompositionTimingInfo](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmgetcompositiontiminginfo).

### `cFramesDropped`

The number of rendered frames that were never displayed because composition occurred too late. This value is valid only after a second call to [DwmGetCompositionTimingInfo](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmgetcompositiontiminginfo).

### `cFramesMissed`

The number of times an old frame was composed when a new frame should have been used but was not available.

### `cRefreshNextDisplayed`

The frame count at which the next frame is scheduled to be displayed.

### `cRefreshNextPresented`

The frame count at which the next DirectX present is scheduled to be displayed.

### `cRefreshesDisplayed`

The total number of refreshes that have been displayed for the application since the [DwmSetPresentParameters](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetpresentparameters) function was last called.

### `cRefreshesPresented`

The total number of refreshes that have been presented by the application since [DwmSetPresentParameters](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetpresentparameters) was last called.

### `cRefreshStarted`

The refresh number when content for this window started to be displayed.

### `cPixelsReceived`

The total number of pixels DirectX redirected to the DWM.

### `cPixelsDrawn`

The number of pixels drawn.

### `cBuffersEmpty`

The number of empty buffers in the flip chain.

## Remarks

Both DWM_FRAME_COUNT and QPC_TIME are defined in Dwmapi.h as **ULONGLONG**.