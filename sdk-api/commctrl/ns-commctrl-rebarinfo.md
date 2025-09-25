# REBARINFO structure

## Description

Contains information that describes rebar control characteristics.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of this structure, in bytes. Your application must fill this member before sending any messages that use the address of this structure as a parameter.

### `fMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag values that describe characteristics of the rebar control. Currently, rebar controls support only one value:

| Value | Meaning |
| --- | --- |
| **RBIM_IMAGELIST** | The **himl** member is valid or must be filled. |

### `himl`

Type: **HIMAGELIST**

Handle to an image list. The rebar control will use the specified image list to obtain images.