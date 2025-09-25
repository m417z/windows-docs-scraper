# ShellSpecialFolderConstants enumeration

## Description

Specifies unique, system-independent values that identify special folders. These folders are frequently used by applications but which may not have the same name or location on any given system. For example, the system folder can be "C:\Windows" on one system and "C:\Winnt" on another.

## Constants

### `ssfDESKTOP:0`

0x00 (0). Windows desktop—the virtual folder that is the root of the namespace.

### `ssfPROGRAMS:0x2`

0x02 (2). File system directory that contains the user's program groups (which are also file system directories). A typical path is C:\Users\*username*\AppData\Roaming\Microsoft\Windows\Start Menu\Programs.

### `ssfCONTROLS:0x3`

0x03 (3). Virtual folder that contains icons for the Control Panel applications.

### `ssfPRINTERS:0x4`

0x04 (4). Virtual folder that contains installed printers.

### `ssfPERSONAL:0x5`

0x05 (5). File system directory that serves as a common repository for a user's documents. A typical path is C:\Users\*username*\Documents.

### `ssfFAVORITES:0x6`

0x06 (6). File system directory that serves as a common repository for the user's favorite URLs. A typical path is C:\Documents and Settings\*username*\Favorites.

### `ssfSTARTUP:0x7`

0x07 (7). File system directory that corresponds to the user's Startup program group. The system starts these programs whenever any user first logs into their profile after a reboot. A typical path is C:\Users\*username*\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\StartUp.

### `ssfRECENT:0x8`

0x08 (8). File system directory that contains the user's most recently used documents. A typical path is C:\Users\*username*\AppData\Roaming\Microsoft\Windows\Recent.

### `ssfSENDTO:0x9`

0x09 (9). File system directory that contains **Send To** menu items. A typical path is C:\Users\*username*\AppData\Roaming\Microsoft\Windows\SendTo.

### `ssfBITBUCKET:0xa`

0x0a (10). Virtual folder that contains the objects in the user's Recycle Bin.

### `ssfSTARTMENU:0xb`

0x0b (11). File system directory that contains **Start** menu items. A typical path is C:\Users\*username*\AppData\Roaming\Microsoft\Windows\Start Menu.

### `ssfDESKTOPDIRECTORY:0x10`

0x10 (16). File system directory used to physically store the file objects that are displayed on the desktop. It is not to be confused with the desktop folder itself, which is a virtual folder. A typical path is C:\Documents and Settings\*username*\Desktop.

### `ssfDRIVES:0x11`

0x11 (17). My Computer—the virtual folder that contains everything on the local computer: storage devices, printers, and Control Panel. This folder can also contain mapped network drives.

### `ssfNETWORK:0x12`

0x12 (18). Network Neighborhood—the virtual folder that represents the root of the network namespace hierarchy.

### `ssfNETHOOD:0x13`

0x13 (19). A file system folder that contains any link objects in the **My Network Places** virtual folder. It is not the same as ssfNETWORK, which represents the network namespace root. A typical path is C:\Users\*username*\AppData\Roaming\Microsoft\Windows\Network Shortcuts.

### `ssfFONTS:0x14`

0x14 (20). Virtual folder that contains installed fonts. A typical path is C:\Windows\Fonts.

### `ssfTEMPLATES:0x15`

0x15 (21). File system directory that serves as a common repository for document templates.

### `ssfCOMMONSTARTMENU:0x16`

0x16 (22). File system directory that contains the programs and folders that appear on the **Start** menu for all users. A typical path is C:\Documents and Settings\All Users\Start Menu. Valid only for Windows NT systems.

### `ssfCOMMONPROGRAMS:0x17`

0x17 (23). File system directory that contains the directories for the common program groups that appear on the **Start** menu for all users. A typical path is C:\Documents and Settings\All Users\Start Menu\Programs. Valid only for Windows NT systems.

### `ssfCOMMONSTARTUP:0x18`

0x18 (24). File system directory that contains the programs that appear in the Startup folder for all users. A typical path is C:\Documents and Settings\All Users\Microsoft\Windows\Start Menu\Programs\StartUp. Valid only for Windows NT systems.

### `ssfCOMMONDESKTOPDIR:0x19`

0x19 (25). File system directory that contains files and folders that appear on the desktop for all users. A typical path is C:\Documents and Settings\All Users\Desktop. Valid only for Windows NT systems.

### `ssfAPPDATA:0x1a`

0x1a (26). [Version 4.71](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). File system directory that serves as a common repository for application-specific data. A typical path is C:\Documents and Settings\*username*\Application Data.

### `ssfPRINTHOOD:0x1b`

0x1b (27). File system directory that contains any link objects in the Printers virtual folder. A typical path is C:\Users\*username*\AppData\Roaming\Microsoft\Windows\Printer Shortcuts.

### `ssfLOCALAPPDATA:0x1c`

0x1c (28). [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). File system directory that serves as a data repository for local (non-roaming) applications. A typical path is C:\Users\*username*\AppData\Local.

### `ssfALTSTARTUP:0x1d`

0x1d (29). File system directory that corresponds to the user's non-localized Startup program group.

### `ssfCOMMONALTSTARTUP:0x1e`

0x1e (30). File system directory that corresponds to the non-localized Startup program group for all users. Valid only for Windows NT systems.

### `ssfCOMMONFAVORITES:0x1f`

0x1f (31). File system directory that serves as a common repository for the favorite URLs shared by all users. Valid only for Windows NT systems.

### `ssfINTERNETCACHE:0x20`

0x20 (32). File system directory that serves as a common repository for temporary Internet files. A typical path is C:\Users\*username*\AppData\Local\Microsoft\Windows\Temporary Internet Files.

### `ssfCOOKIES:0x21`

0x21 (33). File system directory that serves as a common repository for Internet cookies. A typical path is C:\Documents and Settings\*username*\Application Data\Microsoft\Windows\Cookies.

### `ssfHISTORY:0x22`

0x22 (34). File system directory that serves as a common repository for Internet history items.

### `ssfCOMMONAPPDATA:0x23`

0x23 (35). [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Application data for all users. A typical path is C:\Documents and Settings\All Users\Application Data.

### `ssfWINDOWS:0x24`

0x24 (36). [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Windows directory. This corresponds to the %windir% or %SystemRoot% environment variables. A typical path is C:\Windows.

### `ssfSYSTEM:0x25`

0x25 (37). [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). The System folder. A typical path is C:\Windows\System32.

### `ssfPROGRAMFILES:0x26`

0x26 (38). [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Program Files folder. A typical path is C:\Program Files.

### `ssfMYPICTURES:0x27`

0x27 (39). My Pictures folder. A typical path is C:\Users\*username*\Pictures.

### `ssfPROFILE:0x28`

0x28 (40). [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). User's profile folder.

### `ssfSYSTEMx86:0x29`

0x29 (41). [Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). System folder. A typical path is C:\Windows\System32, or C:\Windows\Syswow32 on a 64-bit computer.

### `ssfPROGRAMFILESx86:0x30`

Do not use this field. Use the value 0x2a (42) in your code instead to specify the Program Files (x86) folder. A typical path is C:\Program Files, or C:\Program Files (x86) on a 64-bit computer.

**Note:** In the shldisp.h header, the **ssfPROGRAMFILESx86** field is erroneously assigned to the value 0x30 (48). This value specifies the folder for the Administrative Tools folder instead of the Program Files folder.

## Remarks

The values in this enumeration are equivalent to their corresponding [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) or [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) values, used in C++ applications. They supersede the use of environment variables for this purpose. Note that not all **CSIDL** or **KNOWNFOLDERID** values have an equivalent value in **ShellSpecialFolderConstants**.

> [!NOTE]
> Where a constant identifies a file system folder, a commonly used path is given as an example. However, there is no guarantee that this path will be used on any particular system.

## See also

[CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl)

[KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)