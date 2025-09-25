# IShellIconOverlayIdentifier::GetPriority

## Description

Specifies the priority of an icon overlay.

## Parameters

### `pPriority` [out]

Type: **int***

The address of a value that indicates the priority of the overlay identifier. Possible values range from zero to 100, with zero the highest priority.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error code otherwise.

## Remarks

If more than one icon overlay is available for an object, the one with highest priority is chosen. The Shell has a set of internal rules that determine priority for many cases. The value returned by **GetPriority** is used for those cases in which the Shell's internal rules do not apply. Typically, you should set the value to zero. However, the priority value is useful when you have implemented two or more icon overlay handlers that can request icon overlay icons for the same object. By setting the priority values appropriately, you can specify which of the requested icon overlays will be displayed.

## See also

[IShellIconOverlayIdentifier](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelliconoverlayidentifier)