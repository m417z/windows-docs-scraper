# IDeskBandInfo::GetDefaultBandWidth

## Description

[**GetDefaultBandWidth** may be altered or unavailable in subsequent versions of the operating system or product.]

Gets the band width that the bandsite initially uses to set the default width when the band is added.

## Parameters

### `dwBandID` [in]

Type: **DWORD**

The band ID.

### `dwViewMode` [in]

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

### `pnWidth` [out]

Type: **int***

A pointer to the band width.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.