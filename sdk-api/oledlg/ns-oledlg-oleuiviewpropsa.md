# OLEUIVIEWPROPSA structure

## Description

Contains information that is used to initialize the **View** tab of the **Object properties** dialog box. A reference to it is passed in as part of the [OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa) structure to the [OleUIObjectProperties](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiobjectpropertiesa) function. This tab allows the user to toggle between "content" and "iconic" views of the object, and change its scaling within the container. It also allows the user to tunnel to the change icon dialog box when the object is being displayed iconically.

## Members

### `cbStruct`

The size of the structure, in bytes.

### `dwFlags`

Flags specific to view page.

| Value | Meaning |
| --- | --- |
| **VPF_SELECTRELATIVE** | Relative to origin. |
| **VPF_DISABLERELATIVE** | Disable relative to origin. |
| **VPF_DISABLESCALE** | Disable scale option. |

### `dwReserved1`

This member is reserved.

### `lpfnHook`

Pointer to a hook callback (not used in this dialog box).

### `lCustData`

Custom data to pass to the hook (not used in this dialog box).

### `dwReserved2`

This member is reserved.

### `lpOP`

Used internally.

### `nScaleMin`

Minimum value for the scale range.

### `nScaleMax`

Maximum value for the scale range.

## See also

[OLEUIOBJECTPROPS](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuiobjectpropsa)

## Remarks

> [!NOTE]
> The oledlg.h header defines OLEUIVIEWPROPS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).