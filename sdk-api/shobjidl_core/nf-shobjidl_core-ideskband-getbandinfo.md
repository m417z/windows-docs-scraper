# IDeskBand::GetBandInfo

## Description

Gets state information for a band object.

**Important** You should use [thumbnail toolbars](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions) in new development in place of desk bands, which are not supported as of Windows 7.

## Parameters

### `dwBandID`

Type: **DWORD**

The identifier of the band, assigned by the container. The band object can retain this value if it is required.

### `dwViewMode`

Type: **DWORD**

The view mode of the band object. One of the following values:

#### DBIF_VIEWMODE_NORMAL

The band object is being displayed in a horizontal band.

#### DBIF_VIEWMODE_VERTICAL

The band object is being displayed in a vertical band.

#### DBIF_VIEWMODE_FLOATING

The band object is being displayed in a floating band.

#### DBIF_VIEWMODE_TRANSPARENT

The band object is being displayed in a transparent band.

### `pdbi`

Type: **[DESKBANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-deskbandinfo)***

Pointer to a [DESKBANDINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-deskbandinfo) structure that receives the band information for the object. The **dwMask** member of this structure indicates the specific information that is being requested.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.