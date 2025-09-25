# IDXGIOutput1::FindClosestMatchingMode1

## Description

Finds the display mode that most closely matches the requested display mode.

## Parameters

### `pModeToMatch` [in]

A pointer to the [DXGI_MODE_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_mode_desc1) structure that describes the display mode to match. Members of **DXGI_MODE_DESC1** can be unspecified, which indicates no preference for
that member. A value of 0 for **Width** or **Height** indicates that the value is unspecified. If either **Width** or
**Height** is 0, both must be 0. A numerator and denominator of 0 in **RefreshRate** indicate it is unspecified. Other members
of **DXGI_MODE_DESC1** have enumeration values that indicate that the member is unspecified. If *pConcernedDevice* is **NULL**, the **Format** member of **DXGI_MODE_DESC1** cannot be **DXGI_FORMAT_UNKNOWN**.

### `pClosestMatch` [out]

A pointer to the [DXGI_MODE_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_mode_desc1) structure that receives a description of the display mode that most closely matches the display mode described at *pModeToMatch*.

### `pConcernedDevice` [in, optional]

A pointer to the Direct3D device interface. If this parameter is **NULL**, **FindClosestMatchingMode1** returns only modes whose format matches that of *pModeToMatch*; otherwise, **FindClosestMatchingMode1** returns only those formats that are supported for scan-out by the device. For info about the formats that are supported for scan-out by the device at each feature level:

* [DXGI Format Support for Direct3D Feature Level 12.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-1-formats)
* [DXGI Format Support for Direct3D Feature Level 12.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/hardware-support-for-direct3d-12-0-formats)
* [DXGI Format Support for Direct3D Feature Level 11.1 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-1-feature-level-hardware)
* [DXGI Format Support for Direct3D Feature Level 11.0 Hardware](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-11-0-feature-level-hardware)
* [Hardware Support for Direct3D 10Level9 Formats](https://learn.microsoft.com/previous-versions/ff471324(v=vs.85))
* [Hardware Support for Direct3D 10.1 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-1-hardware)
* [Hardware Support for Direct3D 10 Formats](https://learn.microsoft.com/windows/desktop/direct3ddxgi/format-support-for-direct3d-feature-level-10-0-hardware)

## Return value

Returns one of the error codes described in the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) topic.

## Remarks

Direct3D devices require UNORM formats.

**FindClosestMatchingMode1** finds the closest matching available display mode to the mode that you specify in *pModeToMatch*.

If you set the **Stereo** member in the [DXGI_MODE_DESC1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_mode_desc1) structure to which *pModeToMatch* points to specify a stereo mode as input, **FindClosestMatchingMode1** considers only stereo modes. **FindClosestMatchingMode1** considers only mono modes if **Stereo** is not set.

**FindClosestMatchingMode1** resolves similarly ranked members of display modes (that is, all specified, or all unspecified, and so on) in the following order:

1. **ScanlineOrdering**
2. **Scaling**
3. **Format**
4. **Resolution**
5. **RefreshRate**

When **FindClosestMatchingMode1** determines the closest value for a particular member, it uses previously matched members to filter the display mode list choices, and
ignores other members. For example, when **FindClosestMatchingMode1** matches **Resolution**, it already filtered the display mode list by a certain **ScanlineOrdering**,
**Scaling**, and **Format**, while it ignores **RefreshRate**. This ordering doesn't define the absolute ordering for every usage scenario of **FindClosestMatchingMode1**, because
the application can choose some values initially, which effectively changes the order of resolving members.

**FindClosestMatchingMode1** matches members of the display mode one at a time, generally in a specified order.

If a member is unspecified, **FindClosestMatchingMode1** gravitates toward the values for the desktop related to this output.
If this output is not part of the desktop, **FindClosestMatchingMode1** uses the default desktop output to find values. If an application uses a fully unspecified
display mode, **FindClosestMatchingMode1** typically returns a display mode that matches the desktop settings for this output.
Because unspecified members are lower priority than specified members, **FindClosestMatchingMode1** resolves unspecified members later than specified members.

## See also

[IDXGIOutput1](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgioutput1)