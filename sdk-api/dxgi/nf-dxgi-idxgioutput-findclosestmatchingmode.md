# IDXGIOutput::FindClosestMatchingMode

## Description

[Starting with Direct3D 11.1, we recommend not to use **FindClosestMatchingMode** anymore to find the display mode that most closely matches the requested display mode. Instead, use [IDXGIOutput1::FindClosestMatchingMode1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-findclosestmatchingmode1), which supports stereo display mode.]

Finds the display mode that most closely matches the requested display mode.

## Parameters

### `pModeToMatch` [in]

Type: **const [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85))***

The desired display mode (see [DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85))). Members of **DXGI_MODE_DESC** can be unspecified indicating no preference for
that member. A value of 0 for **Width** or **Height** indicates the value is unspecified. If either **Width** or
**Height** are 0, both must be 0. A numerator and denominator of 0 in **RefreshRate** indicate it is unspecified. Other members
of **DXGI_MODE_DESC** have enumeration values indicating the member is unspecified. If *pConcernedDevice* is **NULL**, **Format** cannot be DXGI_FORMAT_UNKNOWN.

### `pClosestMatch` [out]

Type: **[DXGI_MODE_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173064(v=vs.85))***

The mode that most closely matches *pModeToMatch*.

### `pConcernedDevice` [in, optional]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the Direct3D device interface. If this parameter is **NULL**, only modes whose format matches that of *pModeToMatch* will
be returned; otherwise, only those formats that are supported for scan-out by the device are returned. For info about the formats that are supported for scan-out by the device at each feature level:

* [DXGI Format Support for Direct3D Feature Level 12.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-1-formats)
* [DXGI Format Support for Direct3D Feature Level 12.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-0-formats)
* [DXGI Format Support for Direct3D Feature Level 11.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-1-feature-level-hardware)
* [DXGI Format Support for Direct3D Feature Level 11.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-0-feature-level-hardware)
* [Hardware Support for Direct3D 10Level9 Formats](https://learn.microsoft.com/previous-versions/ff471324(v=vs.85))
* [Hardware Support for Direct3D 10.1 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-1-hardware)
* [Hardware Support for Direct3D 10 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-0-hardware)

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

**FindClosestMatchingMode** behaves similarly to the [IDXGIOutput1::FindClosestMatchingMode1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-findclosestmatchingmode1) except **FindClosestMatchingMode** considers only the mono display modes. **IDXGIOutput1::FindClosestMatchingMode1** considers only stereo modes if you set the **Stereo** member in the [DXGI_MODE_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_mode_desc1) structure that *pModeToMatch* points to, and considers only mono modes if **Stereo** is not set.

[IDXGIOutput1::FindClosestMatchingMode1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgioutput1-findclosestmatchingmode1) returns a matched display-mode set with only stereo modes or only mono modes.
**FindClosestMatchingMode** behaves as though you specified the input mode as mono.

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)