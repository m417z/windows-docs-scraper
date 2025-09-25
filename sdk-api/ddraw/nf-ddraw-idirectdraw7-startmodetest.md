# IDirectDraw7::StartModeTest

## Description

Initiates a test to update the system registry with refresh rate information for the current display adapter and monitor combination. A call to this method is typically followed by calls to [IDirectDraw7::EvaluateMode](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-evaluatemode) to pass or fail modes displayed by the test.

## Parameters

### `unnamedParam1` [in]

An array of SIZE elements that describe, in terms of screen resolutions, the modes that should be tested.

### `unnamedParam2` [in]

The number of elements in the array that the *lpModesToTest* parameter specifies.

### `unnamedParam3` [in]

Flags that specify options for starting a test. The only flag value that is currently valid is DDSMT_ISTESTREQUIRED. When this flag is specified, **StartModeTest** does not initiate a test, but instead returns a value that indicates whether it is possible or necessary to test the resolutions that the *lpModesToTest* and *dwNumEntries* parameters identify.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_CURRENTLYNOTAVAIL
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOEXCLUSIVEMODE
* DDERR_NOTFOUND
* DDERR_TESTFINISHED

When the method is called with the DDSMT_ISTESTREQUIRED flag, it can return one of the following values:

* DDERR_NEWMODE
* DDERR_NODRIVERSUPPORT
* DDERR_NOMONITORINFORMATION
* DDERR_TESTFINISHED

## Remarks

You can use the **StartModeTest** method together with the [IDirectDraw7::EvaluateMode](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-evaluatemode) method to determine the maximum refresh rate that an EDID monitor and display adapter combination can support for each screen resolution. The results of the testing are stored in the system registry and affect the operation of [IDirectDraw7::EnumDisplayModes](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-enumdisplaymodes) when that method is called with the DDEDM_REFRESHRATES flag set.

Specifically, a call to **StartModeTest** directs DirectDraw to establish a set of testable resolutions and to display a mode based on the first resolution in the set. Subsequent calls to [IDirectDraw7::EvaluateMode](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-evaluatemode) can be used to pass or fail each mode and to advance the test to the next display mode.

**StartModeTest** succeeds only with monitors that contain EDID data. If the monitor is not EDID-compliant, **StartModeTest** returns DDERR_TESTFINISHED without testing any modes. If the EDID table does not contain values higher than 60 Hz, no modes are tested. Refresh rates higher than 100 Hz are tested only if the EDID table contains values higher than 85 Hz.

If you call **StartModeTest** with an argument list of (NULL, 0, 0), **StartModeTest** clears existing refresh rate information from the registry.

The test does not guarantee to display only the resolutions in the array described by the *lpModesToTest* and *dwNumEntries* parameters. For example, the 640×480 resolution is used to obtain a maximum viewable refresh rate for the 320×200 resolution.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)