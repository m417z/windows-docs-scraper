# NCRYPT\_UI\_POLICY\_BLOB structure

The **NCRYPT\_UI\_POLICY\_BLOB** structure is used with the [**NCRYPT\_UI\_POLICY\_PROPERTY**](https://learn.microsoft.com/windows/win32/seccng/key-storage-property-identifiers) property to contain user interface information for a key.

## Members

**dwVersion**

The version number of the structure. This member must contain 1.

**dwFlags**

A set of flags that provide additional user interface information or requirements.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
| **NCRYPT\_UI\_PROTECT\_KEY\_FLAG**<br>0x00000001 | Display the strong key user interface as needed.<br> |
| **NCRYPT\_UI\_FORCE\_HIGH\_PROTECTION\_FLAG**<br>0x00000002 | Force high protection.<br> |

**cbCreationTitle**

The length, in bytes, of the creation title. The creation title is a null-terminated Unicode string that specifies the text that is used as the title of the strong key dialog box when the key is completed. The creation title must be placed immediately following the **NCRYPT\_UI\_POLICY\_BLOB** structure. If the value of the **cbCreationTitle** member is set to 0, a default creation title is used for the title of the strong key dialog box. This member is only used on key finalization.

**cbFriendlyName**

The length, in bytes, of the friendly name of the key. The friendly name is a null-terminated Unicode string that contains the text that is displayed in the strong key dialog box as the name of the key. The friendly name must be placed immediately following the creation title in this BLOB. If the value of the **cbFriendlyName** member is set to 0, a default name is used in the strong key dialog box. This member is used both when the key is completed and when the key is used.

**cbDescription**

The length, in bytes, of the key description. The key description is a null-terminated Unicode string that contains the text that is displayed in the strong key dialog box as the description of the key. The description value must be placed immediately following the friendly name in this BLOB. If the value of the **cbDescription** member is set to 0, a default description is used in the strong key dialog box. This member is used both when the key is completed and when the key is used.

## Remarks

This structure is included in the Ncrypt\_provider.h header. To use the structure, you must download the [Cryptographic Provider Development Kit](https://learn.microsoft.com/collaborate/connect-redirect?InvitationID=CSDK-GYTG-R2PX&ProgramID=7264) from Microsoft Connect.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Ncrypt\_provider.h |

