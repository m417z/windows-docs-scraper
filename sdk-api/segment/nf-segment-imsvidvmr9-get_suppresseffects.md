# IMSVidVMR9::get_SuppressEffects

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_SuppressEffects** method queries whether the Video Control configures the system for optimal video playback.

## Parameters

### `bSuppress` [out]

Receives a **VARIANT_BOOL**. For more information, see [IMSVidVMR9::put_SuppressEffects](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvmr9-put_suppresseffects). The default value is VARIANT_TRUE.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidVMR9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvmr9)