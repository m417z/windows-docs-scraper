# APPHELP\_DATA structure

Contains Apphelp data information.

## Members

**dwFlags**

This parameter can be one of more of the following values.

**SHIMREG\_DISABLE\_SHIM** (0x00000001)

**SHIMREG\_DISABLE\_APPHELP** (0x00000002)

**SHIMREG\_APPHELP\_NOUI** (0x00000004)

**SHIMREG\_APPHELP\_CANCEL** (0x10000000)

**SHIMREG\_DISABLE\_SXS** (0x00000010)

**SHIMREG\_DISABLE\_LAYER** (0x00000020)

**SHIMREG\_DISABLE\_DRIVER** (0x00000040)

**dwSeverity**

This parameter can be APPTYPE\_NONE (0).

**dwHTMLHelpID**

The HTML Help identifier.

**szAppName**

The application name.

**trExe**

The [**TAGREF**](https://learn.microsoft.com/windows/win32/devnotes/tagref) of the corresponding executable file.

**szURL**

The URL for Apphelp online link.

**szLink**

The link text for **szURL**.

**szAppTitle**

The title for the Apphelp message.

**szContact**

The vendor contact information.

**szDetails**

The detailed Apphelp message.

**dwData**

User-defined data managed by the application.

**bSPEntry**

This member is **TRUE** if this entry is in the service pack database and **FALSE** otherwise.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |

## See also

[**SdbReadApphelpDetailsData**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadapphelpdetailsdata)

