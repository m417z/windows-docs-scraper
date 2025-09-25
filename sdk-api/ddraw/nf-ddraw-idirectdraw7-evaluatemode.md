# IDirectDraw7::EvaluateMode

## Description

Used after a call to [IDirectDraw7::StartModeTest](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-startmodetest) to pass or fail each mode that the test presents and to step through the modes until the test is complete.

## Parameters

### `unnamedParam1` [in]

One of the following flags that indicate the status of the mode being tested:

#### DDEM_MODEPASSED

The mode being tested has passed.

#### DDEM_MODEFAILED

The mode being tested has failed.

### `unnamedParam2` [out]

A pointer to a variable that receives a value that denotes the seconds that remain before the current mode is failed automatically unless it is explicitly passed or failed.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails or on completion, the method can return one of the following error values:

* DDERR_TESTFINISHED
* DDERR_NEWMODE
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTFOUND

## Remarks

You can use **EvaluateMode** in conjunction with the [IDirectDraw7::StartModeTest](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-startmodetest) method to determine the maximum refresh rate that an EDID monitor and display adapter combination can support for each screen resolution.

Specifically, a call to [IDirectDraw7::StartModeTest](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-startmodetest) directs DirectDraw to establish a set of testable resolutions and to display a mode based on the first resolution in the set. Subsequent calls to **EvaluateMode** can be used to pass or fail each mode and to advance the test to the next display mode. The method steps through the testable resolutions starting with the highest refresh rate supported for a given resolution. After a refresh rate for a given resolution passes, testing of lower refresh rates for that resolution is skipped.

When the test is initiated, or whenever a mode is passed or failed, DirectDraw begins a 15 second timeout. An application can monitor the time remaining without passing or failing the current mode by calling **EvaluateMode** with a value of 0 for the dwFlags argument. Note that DirectDraw only changes modes or terminates the test when **EvaluateMode** is called. However, if an application calls **EvaluateMode** after the timeout period has elapsed, the current mode fails, regardless of the value passed to the *dwFlags* parameter.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)