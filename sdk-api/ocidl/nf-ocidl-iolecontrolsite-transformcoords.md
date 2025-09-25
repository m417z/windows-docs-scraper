# IOleControlSite::TransformCoords

## Description

Converts coordinates expressed in **HIMETRIC** units (as is standard in OLE) to the units specified by the container.

## Parameters

### `pPtlHimetric` [in, out]

Address of a [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure containing coordinates expressed in **HIMETRIC** units. This is an [in] parameter when *dwFlags* contains XFORMCOORDS_HIMETRICTOCONTAINER; it is an [out] parameter with XFORMCOORDS_CONTAINERTOHIMETRIC. In the latter case, the contents are undefined on error.

### `pPtfContainer` [in, out]

Address of a caller-allocated [POINTF](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-pointf) structure that receives the converted coordinates. This is an [in] parameter when *dwFlags* contains XFORMCOORDS_CONTAINERTOHIMETRIC; it is an [out] parameter with XFORMCOORDS_HIMETRICTOCONTAINER. In the latter case, the contents are undefined on error.

### `dwFlags` [in]

Flags indicating the exact conversion to perform. This parameter can be any combination of the following values, except as indicated.

| Value | Meaning |
| --- | --- |
| **XFORMCOORDS_POSITION**<br><br>0x1 | The coordinates to convert represent a position point. Cannot be used with XFORMCOORDS_SIZE. |
| **XFORMCOORDS_SIZE**<br><br>0x2 | The coordinates to convert represent a set of dimensions. Cannot be used with XFORMCOORDS_POSITION. |
| **XFORMCOORDS_HIMETRICTOCONTAINER**<br><br>0x4 | The operation converts pptlHimetric into pptfContainer. Cannot be used with XFORMCOORDS_CONTAINERTOHIMETRIC. |
| **XFORMCOORDS_CONTAINERTOHIMETRIC**<br><br>0x8 | The operation converts pptfContainer into pptlHimetric. Cannot be used with XFORMCOORDS_HIMETRICTOCONTAINER. |
| **XFORMCOORDS_EVENTCOMPAT**<br><br>0x10 | The operation maintains compatibility with an event. |

## Return value

This method can return the standard return values E_INVALIDARG and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The container does not require any special coordinate conversions. The container deals completely in **HIMETRIC**. |
| **E_POINTER** | The address in *pPtlHimetric* or *pPtfContainer* is not valid. For example, it may be **NULL**. |

## Remarks

A control uses this method when it has to send coordinates to a container within an event or some other custom call or when the control has container coordinates that it needs to convert into **HIMETRIC** units.

## See also

[IOleControlSite](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iolecontrolsite)