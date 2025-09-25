# SHELLDETAILS structure

## Description

Reports detailed information on an item in a Shell folder.

## Members

### `fmt`

Type: **int**

The alignment of the column heading and the subitem text in the column. This member can be one of the following values.

#### LVCFMT_CENTER

Text is centered.

#### LVCFMT_COL_HAS_IMAGES

[Version 4.70](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Header item contains an image in the image list.

#### LVCFMT_LEFT

Text is left-aligned.

#### LVCFMT_RIGHT

Text is right-aligned.

#####

### `cxChar`

Type: **int**

The number of average-sized characters in the header.

### `str`

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)**

An [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure that includes a string with the requested information. To convert this structure to a string, use [StrRetToBuf](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettobufa) or [StrRetToStr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettostra).

## See also

[IShellDetails::GetDetailsOf](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-ishelldetails-getdetailsof)