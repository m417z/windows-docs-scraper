# DETAILSINFO structure

## Description

Contains detail information for a Shell folder item. Used with the [SFVM_GETDETAILSOF](https://learn.microsoft.com/windows/desktop/shell/sfvm-getdetailsof) notification.

## Members

### `pidl`

Type: **PCUITEMID_CHILD**

PIDL of the item whose details are being retrieved.

### `fmt`

Type: **int**

The alignment of the column heading and the subitem text in the column. This member can be one of the following values. Note that the alignment of the leftmost column is always left-justified and cannot be changed.

#### LVCFMT_CENTER

Text is centered.

#### LVCFMT_COL_HAS_IMAGES

Header item contains an image in the image list.

#### LVCFMT_LEFT

Text is left-aligned.

#### LVCFMT_RIGHT

Text is right-aligned.

### `cxChar`

Type: **int**

The number of average-sized characters in the heading.

### `str`

Type: **[STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret)**

An [STRRET](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-strret) structure that includes a string containing the requested detail. To convert this structure to a string, use [StrRetToBuf](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettobufa) or [StrRetToStr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strrettostra).

### `iImage`

Type: **int**

The index of an icon in the Shell image list that is displayed in the view.