# DEVNAMES structure

## Description

Contains strings that identify the driver, device, and output port names for a printer. These strings must be ANSI strings when the ANSI version of [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) or [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) is used, and must be Unicode strings when the Unicode version of **PrintDlg** or **PrintDlgEx** is used. The **PrintDlgEx** and **PrintDlg** functions use these strings to initialize the system-defined [Print Property Sheet](https://learn.microsoft.com/windows/desktop/dlgbox/print-property-sheet) or [Print Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/print-dialog-box). When the user closes the property sheet or dialog box, information about the selected printer is returned in this structure.

## Members

### `wDriverOffset`

Type: **WORD**

The offset, in characters, from the beginning of this structure to a null-terminated string that contains the file name (without the extension) of the device driver. On input, this string is used to determine the printer to display initially in the dialog box.

### `wDeviceOffset`

Type: **WORD**

The offset, in characters, from the beginning of this structure to the null-terminated string that contains the name of the device.

### `wOutputOffset`

Type: **WORD**

The offset, in characters, from the beginning of this structure to the null-terminated string that contains the device name for the physical output medium (output port).

### `wDefault`

Type: **WORD**

Indicates whether the strings contained in the **DEVNAMES** structure identify the default printer. This string is used to verify that the default printer has not changed since the last print operation. If any of the strings do not match, a warning message is displayed informing the user that the document may need to be reformatted. On output, the **wDefault** member is changed only if the **Print Setup** dialog box was displayed and the user chose the **OK** button. The **DN_DEFAULTPRN** flag is used if the default printer was selected. If a specific printer is selected, the flag is not used. All other flags in this member are reserved for internal use by the dialog box procedure for the **Print** property sheet or **Print** dialog box.

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85))

[PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85))

**Reference**