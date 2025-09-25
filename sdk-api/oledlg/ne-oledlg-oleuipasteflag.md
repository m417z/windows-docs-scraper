# OLEUIPASTEFLAG enumeration

## Description

Indicates the user options that are available to the user when pasting this format, and within which group or list of choices (**Paste**, **Paste Link**, etc.).

## Constants

### `OLEUIPASTE_ENABLEICON:2048`

If the container does not specify this flag for the entry in the [OLEUIPASTEENTRY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipasteentrya) array passed as input to [OleUIPasteSpecial](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuipastespeciala), the DisplayAsIcon button will be unchecked and disabled when the user selects the format that corresponds to the entry.

### `OLEUIPASTE_PASTEONLY:0`

The entry in the [OLEUIPASTEENTRY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipasteentrya) array is valid for pasting only.

### `OLEUIPASTE_PASTE:512`

The entry in the [OLEUIPASTEENTRY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipasteentrya) array is valid for pasting. It may also be valid for linking if any of the following linking flags are specified. If it is valid for linking, then the following flags indicate which link types are acceptable by OR'ing together the appropriate OLEUIPASTE_LINKTYPE*n* values. These values correspond as follows to the array of link types passed to [OleUIPasteSpecial](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuipastespeciala) in the **arrLinkTypes** member of the [OLEUIPASTESPECIAL](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipastespeciala) structure:

* OLEUIPASTE_LINKTYPE1=arrLinkTypes[0]
* OLEUIPASTE_LINKTYPE2=arrLinkTypes[1]
* OLEUIPASTE_LINKTYPE3=arrLinkTypes[2]
* OLEUIPASTE_LINKTYPE4=arrLinkTypes[3]
* OLEUIPASTE_LINKTYPE5=arrLinkTypes[4]
* OLEUIPASTE_LINKTYPE6=arrLinkTypes[5]
* OLEUIPASTE_LINKTYPE7=arrLinkTypes[6]
* OLEUIPASTE_LINKTYPE8=arrLinkTypes[7]

The **arrLinkTypes** array is an array of registered clipboard formats for linking. A maximum of 8 link types is allowed.

### `OLEUIPASTE_LINKANYTYPE:1024`

Any link type.

### `OLEUIPASTE_LINKTYPE1:1`

Link type 1.

### `OLEUIPASTE_LINKTYPE2:2`

Link type 2.

### `OLEUIPASTE_LINKTYPE3:4`

Link type 3.

### `OLEUIPASTE_LINKTYPE4:8`

Link type 4.

### `OLEUIPASTE_LINKTYPE5:16`

Link type 5.

### `OLEUIPASTE_LINKTYPE6:32`

Link type 6.

### `OLEUIPASTE_LINKTYPE7:64`

Link type 7.

### `OLEUIPASTE_LINKTYPE8:128`

Link type 8.

## See also

[OLEUIPASTEENTRY](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuipasteentrya)