# RESTRICTIONS enumeration

## Description

These flags are used with the [SHRestricted](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shrestricted) function. **SHRestricted** is used to determine whether a specified administrator policy is in effect. In many cases, applications need to modify certain behaviors in order to comply with the policies enacted by system administrators.

## Constants

### `REST_NONE:0x00000000`

Not used.

### `REST_NORUN:0x00000001`

If nonzero, the system administrator has forbidden access to the **Run** command on the **Start** menu. Applications should remove similar functionality. For example, a browser with an address bar should deny attempts by the user to type the path of a local file into the address bar.

### `REST_NOCLOSE:0x00000002`

If nonzero, the system administrator has forbidden access to the **Shut Down** command on the **Start** menu. Applications should remove the ability to shut down or restart the computer.

### `REST_NOSAVESET:0x00000004`

If nonzero, the system administrator has requested that applications do not save their state at exit for restoration the next time they are run. Applications should disable saving their window position and settings.

### `REST_NOFILEMENU:0x00000008`

If nonzero, the system administrator has forbidden access to the Windows Explorer **File** menu. Applications should remove similar functionality.

### `REST_NOSETFOLDERS:0x00000010`

If nonzero, the system administrator has forbidden access to **Control Panel**, **Printers**, and **Network and Dial up Connections**. Applications should prevent users from viewing those folders.

### `REST_NOSETTASKBAR:0x00000020`

If nonzero, the system administrator has forbidden access to taskbar settings. Applications should prevent users from changing those settings.

### `REST_NODESKTOP:0x00000040`

If nonzero, the system administrator has specified that all icons on the desktop should be hidden. Applications do not need to perform any special actions.

### `REST_NOFIND:0x00000080`

If nonzero, the system administrator has indicated that the user should not be enabled to search for files. Applications should remove similar functionality.

### `REST_NODRIVES:0x00000100`

A 32-bit value that specifies the drives that should not be displayed to the user. Bit 0 corresponds to drive A, up to bit 25 which corresponds to drive Z. Applications that display a list of drives should remove drives that have their corresponding bits set.

### `REST_NODRIVEAUTORUN:0x00000200`

A 32-bit value that specifies the drives for which AutoRun should be disabled. Bit 0 corresponds to drive A, up to bit 25 which corresponds to drive Z. Applications should not offer to AutoRun any drive that has its corresponding bit set.

### `REST_NODRIVETYPEAUTORUN:0x00000400`

A 32-bit value that specifies the drive types for which AutoRun should be disabled. The bits are numbered according to the return value of [GetDriveType](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getdrivetypea). For example, bit **DRIVE_CDROM** disables AutoRun on CD-ROM drives. Applications should not offer to AutoRun any drive whose type has its corresponding bit set.

### `REST_NONETHOOD:0x00000800`

If nonzero, the system administrator has removed **Network Neighborhood** (also known as **My Network Places**) from the Shell namespace. Applications should disable functionality that enables the user to browse the network.

### `REST_STARTBANNER:0x00001000`

Not used.

### `REST_RESTRICTRUN:0x00002000`

If nonzero, the system administrator has restricted the programs the user can run. Only programs listed under the registry key **HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer** can be run either from the **Run** dialog box, by double-clicking, or by selecting from the **File** menu. Applications should prevent users from running programs not listed under that key. Applications that use the [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) or [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) functions to run programs do not need to take any special action because those functions check the policy.

### `REST_NOPRINTERTABS:0x00004000`

Not used.

### `REST_NOPRINTERDELETE:0x00008000`

If nonzero, the system administrator has disabled the user's ability to delete printers. Applications should remove the ability to delete printers.

### `REST_NOPRINTERADD:0x00010000`

If nonzero, the system administrator has disabled the user's ability to add printers. Applications should remove the ability to add printers.

### `REST_NOSTARTMENUSUBFOLDERS:0x00020000`

If nonzero, subfolders of the **Start** menu and **Programs** menu are not shown on the top of the classic **Start** menu, the **Programs** list on the classic **Start** menu, or the **All Programs** list on the **Start** menu. Applications that enumerate the contents of the **Start** menu should avoid subfolders. If nonzero, this flag does not restrict any menus other than those listed here; in particular, **My Computer** can still expand.

### `REST_MYDOCSONNET:0x00040000`

Not used.

### `REST_NOEXITTODOS:0x00080000`

Not used.

### `REST_ENFORCESHELLEXTSECURITY:0x00100000`

If nonzero, the system administrator has forbidden the use of unapproved Shell extensions. Applications should not instantiate Shell extensions unless they are marked as approved by the system administrator. For more information, see [Creating Shell Extension Handlers](https://learn.microsoft.com/windows/desktop/shell/handlers).

### `REST_LINKRESOLVEIGNORELINKINFO:0x00200000`

If nonzero, the system does not attempt to reconnect mapped network drives when resolving a broken shortcut to a file or folder on a mapped network drive. Applications do not need to perform any special actions.

### `REST_NOCOMMONGROUPS:0x00400000`

If nonzero, indicates the system administrator has forbidden access to the **CSIDL_COMMON_STARTMENU** or **CSIDL_COMMON_PROGRAMS** folders on the **Start** menu. Applications that enumerate the contents of the **Start** menu should avoid those folders.

### `REST_SEPARATEDESKTOPPROCESS:0x00800000`

If nonzero, the administrator has required that folders be opened in a separate process. This overrides and disables the corresponding setting in the **Folder Options** dialog box. Applications do not need to perform any special actions.

### `REST_NOWEB:0x01000000`

If nonzero, the system administrator has removed the **Web** tab from the desktop **Properties** dialog box. Applications do not need to perform any special actions. **Windows XP and later**: Not used.

### `REST_NOTRAYCONTEXTMENU:0x02000000`

If nonzero, the system administrator has forbidden access to context menus for the taskbar. Applications do not need to perform any special actions.

### `REST_NOVIEWCONTEXTMENU:0x04000000`

If nonzero, the system administrator has forbidden access to context menus for Shell objects. Applications should disable context menus for Shell objects.

### `REST_NONETCONNECTDISCONNECT:0x08000000`

If nonzero, the system administrator has denied users the ability to map or disconnect network drives. Applications should remove the ability to map or disconnect network drives.

### `REST_STARTMENULOGOFF:0x10000000`

If 1, the system administrator has removed the **Log Off** option from the **Start** menu. If 2, the system administrator has forced the **Log Off** option to be shown. Applications do not need to perform any special actions.

### `REST_NOSETTINGSASSIST:0x20000000`

Not used.

### `REST_NOINTERNETICON:0x40000001`

If nonzero, the system administrator has removed the Internet Explorer icon from the desktop. Applications do not need to perform any special actions.

### `REST_NORECENTDOCSHISTORY:0x40000002`

If nonzero, the system administrator has disabled recent document history. Applications must disable all MRU lists, such as those that are often displayed on the **File** menu. Adherence to this setting is mandatory for Windows logo compliance.

### `REST_NORECENTDOCSMENU:0x40000003`

If nonzero, the system administrator has removed the **Recent Documents** menu from the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOACTIVEDESKTOP:0x40000004`

If nonzero, the system administrator has disabled the ability to create web content on the desktop. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOACTIVEDESKTOPCHANGES:0x40000005`

If nonzero, the system administrator has disabled the ability to change web content on the desktop. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOFAVORITESMENU:0x40000006`

If nonzero, the system administrator has removed the **Favorites** menu from the **Start** menu. Applications do not need to perform any special actions.

### `REST_CLEARRECENTDOCSONEXIT:0x40000007`

If nonzero, the system administrator has required that recent document history and related history information be deleted when the user logs off. Applications should erase recent document history when they exit.

### `REST_CLASSICSHELL:0x40000008`

Not used.

### `REST_NOCUSTOMIZEWEBVIEW:0x40000009`

If nonzero, the system administrator has disabled the ability to customize the appearance of Windows Explorer folders. Applications do not need to perform any special actions.

### `REST_NOHTMLWALLPAPER:0x40000010`

If nonzero, the system administrator has disabled the ability to set the wallpaper to any image that is not a bitmap (*.bmp) image. Applications that enable the user to change desktop wallpaper should disable web content. **Windows Vista or later**: Not used.

### `REST_NOCHANGINGWALLPAPER:0x40000011`

If nonzero, the system administrator has disabled the ability to change the desktop wallpaper. Applications should disable corresponding functionality.

### `REST_NODESKCOMP:0x40000012`

If nonzero, the system administrator has disabled desktop components. Applications that create or modify desktop components should disable this functionality. **Windows Vista or later**: Not used.

### `REST_NOADDDESKCOMP:0x40000013`

If nonzero, the system administrator has disabled the ability to create desktop components. Applications that create desktop components should disable this functionality.

### `REST_NODELDESKCOMP:0x40000014`

If nonzero, the system administrator has disabled the ability to delete desktop components. Applications that delete desktop components should disable this functionality. **Windows Vista or later**: Not used.

### `REST_NOCLOSEDESKCOMP:0x40000015`

If nonzero, the system administrator has disabled the ability to close desktop components. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOCLOSE_DRAGDROPBAND:0x40000016`

If nonzero, the system administrator has disabled the ability to drag, drop, or close desktop bands. Applications do not need to perform any special actions.

### `REST_NOMOVINGBAND:0x40000017`

If nonzero, the system administrator has disabled the ability to move a desktop band. Applications do not need to perform any special actions.

### `REST_NOEDITDESKCOMP:0x40000018`

If nonzero, indicates the system administrator has disabled the ability to modify desktop components. Applications that modify desktop components should disable this functionality. **Windows Vista or later**: Not used.

### `REST_NORESOLVESEARCH:0x40000019`

If nonzero, the system administrator has disabled heuristic file searching when resolving broken shortcuts. Applications do not need to perform any special actions.

### `REST_NORESOLVETRACK:0x4000001A`

If nonzero, the system administrator has disabled the use of the link tracking service when resolving broken shortcuts. Applications do not need to perform any special actions.

### `REST_FORCECOPYACLWITHFILE:0x4000001B`

If nonzero, the system administrator has forced Shell file copy operations to copy the ACL with the file rather than inheriting the ACL from the target folder. Applications that use the [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) function do not need to perform any special actions. Applications that copy files manually should ensure that the source ACL is copied.

### `REST_NOLOGO3CHANNELNOTIFY:0x4000001C`

If nonzero, the system administrator has disabled channel updates when resolving shortcuts. Applications do not need to perform any special actions. **Windows Vista or later**: Not supported.

### `REST_NOFORGETSOFTWAREUPDATE:0x4000001D`

If nonzero, the system administrator has disabled the ability to uncheck the **Remind me until I update the current version** checkbox in the [SoftwareUpdateMessageBox](https://learn.microsoft.com/windows/desktop/api/shlobj/nf-shlobj-softwareupdatemessagebox) function. Applications do not need to perform any special actions.

### `REST_NOSETACTIVEDESKTOP:0x4000001E`

If nonzero, the system administrator has disabled the ability to change settings for web content on the desktop. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOUPDATEWINDOWS:0x4000001F`

If nonzero, the system administrator has hidden the **Windows Update** shortcut on the **Start** menu. Applications that enumerate the contents of the **Start** menu should not show the **Windows Update** shortcut to the user.

### `REST_NOCHANGESTARMENU:0x40000020`

If nonzero, the system administrator has disabled the ability to make changes to the **Start** menu. Applications should disable any feature that enables the user to reorganize their **Start** menu.

### `REST_NOFOLDEROPTIONS:0x40000021`

If nonzero, the system administrator has denied access to the **Folder Options** dialog box. Applications that display **Folder Options** in **Control Panel** should disable this functionality.

### `REST_HASFINDCOMPUTERS:0x40000022`

If nonzero, the system administrator has disabled the ability to search for computers on the network. Applications should remove the ability to search for computers on the network.

### `REST_INTELLIMENUS:0x40000023`

If nonzero, the system administrator has disabled personalized menus. Applications should not hide infrequently-used menu commands.

### `REST_RUNDLGMEMCHECKBOX:0x40000024`

If nonzero, the system administrator has disabled the **Run in separate memory space** option in the **Run** dialog. Applications that provide similar functionality should remove the corresponding checkbox.

### `REST_ARP_ShowPostSetup:0x40000025`

If nonzero, the system administrator has removed the list of incomplete setup operations from the "Add/Remove Windows Components" section of the **Add/Remove Programs** dialog box. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOCSC:0x40000026`

If nonzero, the system administrator has removed **Synchronize All** from the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOCONTROLPANEL:0x40000027`

If nonzero, the system administrator has denied access to **Control Panel**. Applications should disable any functionality that runs `Control Panel`.

### `REST_ENUMWORKGROUP:0x40000028`

If nonzero, the system administrator has indicated that the **Network Neighborhood** should include the computer workgroup. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_ARP_NOARP:0x40000029`

If nonzero, the system administrator has denied access to the **Add/Remove Programs** dialog box. Applications should disable any functionality that runs the **Add/Remove Programs** dialog box. **Windows Vista or later**: Not used.

### `REST_ARP_NOREMOVEPAGE:0x4000002A`

If nonzero, the system administrator has denied access to the **Change or Remove Programs** section of the **Add/Remove Programs** dialog box. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_ARP_NOADDPAGE:0x4000002B`

If nonzero, the system administrator has denied access to the **Add Programs** section of the **Add/Remove Programs** dialog box. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_ARP_NOWINSETUPPAGE:0x4000002C`

If nonzero, the system administrator has denied access to the **Add/Remove Windows Components** section of the **Add/Remove Programs** dialog box. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_GREYMSIADS:0x4000002D`

If nonzero, the system administrator has specified that Windows Installer shortcuts that refer to applications that are available but not yet installed should be displayed on the **Start** menu in gray. Applications do not need to perform any special actions.

### `REST_NOCHANGEMAPPEDDRIVELABEL:0x4000002E`

Not used.

### `REST_NOCHANGEMAPPEDDRIVECOMMENT:0x4000002F`

Not used.

### `REST_MaxRecentDocs:0x40000030`

A 32-bit value that specifies the maximum number of documents to be retained in the **Recent Documents** menu. If this value is zero, then the system administrator has not specified any maximum, and applications can choose a default. If this value is nonzero, applications should restrict their **Recent Documents** list to the specified number of items.

### `REST_NONETWORKCONNECTIONS:0x40000031`

If nonzero, the system administrator has removed the **Network Connections** menu from the **Start** menu. Applications should hide lists of network and dial-up connections.

### `REST_FORCESTARTMENULOGOFF:0x40000032`

If nonzero, the system administrator has forced the **Log Off** command onto the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOWEBVIEW:0x40000033`

If nonzero, the system administrator has disabled folder HTML templates (Windows 2000) or folder tasks (Windows XP) in Windows Explorer. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOCUSTOMIZETHISFOLDER:0x40000034`

If nonzero, the system administrator has disabled the ability to customize the appearance of Windows Explorer folders. Applications do not need to perform any special actions.

### `REST_NOENCRYPTION:0x40000035`

If nonzero, the system administrator has disabled the ability to encrypt and decrypt files and folders. Applications should not call [EncryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-encryptfilea) or [DecryptFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-decryptfilea).

### `REST_DONTSHOWSUPERHIDDEN:0x40000037`

If nonzero, the system administrator has disabled the ability to view files marked System and Hidden ("super-hidden files"), overriding the **fShowSuperHidden** member of the [SHELLSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shellstatea) structure. Applications should not show files that have both the FILE_ATTRIBUTE_SYSTEM and FILE_ATTRIBUTE_HIDDEN attributes to the user.

### `REST_NOSHELLSEARCHBUTTON:0x40000038`

If nonzero, the system administrator has disabled the **Search** button in the Windows Explorer toolbar. Applications do not need to perform any special actions.

### `REST_NOHARDWARETAB:0x40000039`

If nonzero, the system administrator has disabled the **Hardware** tab in the **Drive**, **Mouse**, **Keyboard**, and **Multimedia** property sheets. Applications do not need to perform any special actions.

### `REST_NORUNASINSTALLPROMPT:0x4000003A`

If nonzero, the system administrator has disabled the automatic prompt for automatic credentials when installing an application. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_PROMPTRUNASINSTALLNETPATH:0x4000003B`

If nonzero, the system administrator has disabled the automatic prompt for automatic credentials when installing an application from a network path. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOMANAGEMYCOMPUTERVERB:0x4000003C`

If nonzero, the system administrator has removed the **Manage** command from the **My Computer** context menu. Applications do not need to perform any special actions.

### `REST_DISALLOWRUN:0x4000003E`

If nonzero, the system administrator has restricted the programs the user can run. Programs listed under the registry key
**HKEY_CURRENT_USER**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**Policies**\**Explorer**\**DisallowRun** may not be run from the **Run** dialog box, by double-clicking, or by selecting from the **File** menu. Programs are listed by their full path (for example, "C:\Windows\system32\cmd.exe"). Applications should prevent users from running programs listed under that key. Applications that use the [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) or [ShellExecuteEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecuteexa) function to run programs do not need to take any special action because those functions will check the policy.

### `REST_NOWELCOMESCREEN:0x4000003F`

If nonzero, the system administrator has disabled the **Welcome to Windows** program that is run when a user logs on. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_RESTRICTCPL:0x40000040`

If nonzero, the system administrator has restricted the control panel applications the user can run. In order to be run, a control panel application must be listed under the registry key
**HKEY_CURRENT_USER**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**Policies**\**Explorer**\**RestrictCpl**. The control panel application can be listed either under its display name (for example, "Mouse") or under its filename (for example, "main.cpl"). Applications that launch control panel applications should prevent users from running control panel applications not listed under that key.

### `REST_DISALLOWCPL:0x40000041`

If nonzero, the system administrator has restricted the control panel applications the user can run. In order to be run, a control panel application must not be listed under the registry key
**HKEY_CURRENT_USER**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**Policies**\**Explorer**\**DisallowCpl**. The control panel application can be listed either under its display name (for example, "Mouse") or under its filename (for example, "main.cpl"). Applications that launch control panel applications should prevent users from running control panel applications listed under that key.

### `REST_NOSMBALLOONTIP:0x40000042`

If nonzero, the system administrator has disabled balloon tips that are displayed by the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOSMHELP:0x40000043`

If nonzero, the system administrator has removed the **Help** option from the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOWINKEYS:0x40000044`

If nonzero, the system administrator has disabled the keyboard shortcut associated with the Windows logo key. Applications do not need to perform any special actions.

### `REST_NOENCRYPTONMOVE:0x40000045`

If nonzero, the system administrator has specified that unencrypted files and folders moved into an encrypted folder should remain unencrypted instead of inheriting the encryption attribute from the enclosing folder. Applications that move files and folders should unencrypt them if they were originally unencrypted and are moved into an encrypted folder. Applications that use the [SHFileOperation](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shfileoperationa) function to move files do not need to perform any special actions because the **SHFileOperation** function respects this policy.

### `REST_NOLOCALMACHINERUN:0x40000046`

If nonzero, the system administrator has disabled the execution of programs listed in the
**HKEY_LOCAL_MACHINE**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**Run** registry key. Applications do not need to perform any special actions.

### `REST_NOCURRENTUSERRUN:0x40000047`

If nonzero, the system administrator has disabled the execution of programs listed in the
**HKEY_CURRENT_USER**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**Run** registry key. Applications do not need to perform any special actions.

### `REST_NOLOCALMACHINERUNONCE:0x40000048`

If nonzero, the system administrator has disabled the execution of programs listed in the
**HKEY_LOCAL_MACHINE**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**RunOnce** registry key. Applications do not need to perform any special actions.

### `REST_NOCURRENTUSERRUNONCE:0x40000049`

If nonzero, the system administrator has disabled the execution of programs listed in the
**HKEY_CURRENT_USER**\**Software**\**Microsoft**\**Windows**\**CurrentVersion**\**RunOnce** registry key. Applications do not need to perform any special actions.

### `REST_FORCEACTIVEDESKTOPON:0x4000004A`

If nonzero, the system administrator has forced web content to be enabled on the desktop. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOVIEWONDRIVE:0x4000004C`

A 32-bit value that specifies the drives the user cannot open or drop files into. Bit 0 corresponds to drive A, up to bit 25 which corresponds to drive Z. Applications that enable the user to open folders or drop files should prevent the user from opening a folder on a restricted drive or dropping files onto a restricted drive.

### `REST_NONETCRAWL:0x4000004D`

Windows XP, Windows**2003, or IE_BACKCOMPAT_VERSION defined.** If nonzero, the system administrator has disabled automatic searching for network folders and printers, overriding the *fNoNetCrawling* member of the **SHELLSTATE** structure. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOSHAREDDOCUMENTS:0x4000004E`

Windows XP, Windows**2003 or IE_BACKCOMPAT_VERSION defined.** If nonzero, the system administrator has hidden the **Shared Documents** icon in **My Computer**. Applications should hide access to CSIDL_COMMON_DOCUMENTS. **Windows Vista or later**: Not used.

### `REST_NOSMMYDOCS:0x4000004F`

If nonzero, the system administrator has hidden the **My Documents** icon on the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOSMMYPICS:0x40000050`

**Windows XP or later.** If nonzero, the system administrator has hidden the **My Pictures** icon on the **Start** menu. Applications do not need to perform any special actions.

### `REST_ALLOWBITBUCKDRIVES:0x40000051`

**Windows XP or later.** A 32-bit value that specifies the drives for which the **Recycle Bin** should be forced to be enabled. The system typically disables the **Recycle Bin** on drives that are not local fixed drives. Bit 0 corresponds to drive A, up to bit 25 which corresponds to drive Z. Applications do not need to perform any special actions.

### `REST_NONLEGACYSHELLMODE:0x40000052`

**Windows XP or later.** If nonzero, the system administrator has hidden the **Back** and **Forward** buttons in the Internet Explorer toolbar. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOCONTROLPANELBARRICADE:0x40000053`

**Windows XP or later.** Ignored.

### `REST_NOSTARTPAGE:0x40000054`

**Windows XP or later.** Ignored.

### `REST_NOAUTOTRAYNOTIFY:0x40000055`

**Windows XP or later.** If nonzero, the system administrator has forced all taskbar icons to be visible, even if they are inactive, overriding the user's decision to hide inactive taskbar icons. Applications do not need to perform any special actions.

### `REST_NOTASKGROUPING:0x40000056`

**Windows XP or later.** If nonzero, the system administrator has disabled grouping of similar taskbar buttons, overriding the user's decision to enable taskbar button grouping. Applications do not need to perform any special actions.

### `REST_NOCDBURNING:0x40000057`

**Windows XP or later.** If nonzero, the system administrator has disabled CD burning. Applications should disable any CD-burning capabilities.

### `REST_MYCOMPNOPROP:0x40000058`

**Windows 2000 SP3 or later.** If nonzero, the system administrator has disabled the **System Properties** dialog box. Applications should not launch the **System Properties** dialog box.

### `REST_MYDOCSNOPROP:0x40000059`

**Windows 2000 SP3 or later.** If nonzero, the system administrator has disabled the ability to view properties of the **My Documents** folder. Applications should not redirect the **My Documents** folder.

### `REST_NOSTARTPANEL:0x4000005A`

**Windows XP or later.** If nonzero, the system administrator has disabled the Windows XP **Start** menu. Applications do not need to perform any special actions.

### `REST_NODISPLAYAPPEARANCEPAGE:0x4000005B`

**Windows XP or later.** If 1, the system administrator has disabled the **Themes** and **Appearance** pages from the **Desktop Properties** dialog box. Applications should not change system colors and appearance.

### `REST_NOTHEMESTAB:0x4000005C`

**Windows XP or later.** If nonzero, the system administrator has disabled the **Themes** page from the **Desktop Properties** dialog. Applications should not change visual styles.

### `REST_NOVISUALSTYLECHOICE:0x4000005D`

**Windows XP or later.** If nonzero, the system administrator has disabled the ability to change visual styles. Applications should not change visual styles.

### `REST_NOSIZECHOICE:0x4000005E`

**Windows XP or later.** If nonzero, the system administrator has disabled the ability to change font sizes from the **Appearance** page on the Desktop Properties dialog box. Applications should not change system metrics.

### `REST_NOCOLORCHOICE:0x4000005F`

**Windows XP or later.** If nonzero, the system administrator has disabled the ability to change system colors from the **Appearance** page on the **Desktop Properties** dialog box. Applications should not change system colors.

### `REST_SETVISUALSTYLE:0x40000060`

**Windows XP or later.** If nonzero, the system administrator has forced a specific visual style. Applications should not change visual styles.

### `REST_STARTRUNNOHOMEPATH:0x40000061`

**Windows 2000 SP3 or later.** If nonzero, the default working directory for programs run from the Run dialog is not forced to the user's home directory. Applications do not need to perform any special actions.

### `REST_NOUSERNAMEINSTARTPANEL:0x40000062`

Windows XP, Windows **2003.** If nonzero, the system administrator has hidden the user name on the Windows XP **Start** menu. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_NOMYCOMPUTERICON:0x40000063`

**Windows XP or later.** If nonzero, the system administrator has hidden the **My Computer** icon. Applications should not permit access to the **My Computer** icon.

### `REST_NOSMNETWORKPLACES:0x40000064`

**Windows XP or later.** If nonzero, the system administrator has hidden the **Network Places** icon on the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOSMPINNEDLIST:0x40000065`

**Windows XP or later.** If nonzero, the system administrator has hidden the list of "pinned" items on the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOSMMYMUSIC:0x40000066`

**Windows XP or later.** If nonzero, the system administrator has hidden the **My Music** icon on the **Start** menu. Applications do not need to perform any special actions.

### `REST_NOSMEJECTPC:0x40000067`

**Windows XP or later.** If nonzero, the system administrator has hidden the **Eject** command on the **Start** menu. Applications should not enable the user to eject the computer.

### `REST_NOSMMOREPROGRAMS:0x40000068`

**Windows XP or later.** If nonzero, the system administrator has hidden the **All Programs** item on the Windows XP **Start** menu. Applications should not show the contents of the **Start** menu folder to the user.

### `REST_NOSMMFUPROGRAMS:0x40000069`

**Windows XP or later.** If nonzero, the system administrator has hidden the list of most frequently used programs on the Windows XP **Start** menu. Applications do not need to perform any special actions.

### `REST_NOTRAYITEMSDISPLAY:0x4000006A`

**Windows XP or later.** If nonzero, the system administrator has hidden all taskbar notification icons, regardless of activity. Applications do not need to perform any special actions.

### `REST_NOTOOLBARSONTASKBAR:0x4000006B`

**Windows XP or later.** If nonzero, the system administrator has hidden all taskbar toolbars, such as **Quick Launch**. Applications do not need to perform any special actions.

### `REST_NOSMCONFIGUREPROGRAMS:0x4000006F`

**Windows 2000 SP3 or later.** If nonzero, the system administrator has hidden the **Set Program Access** and **Defaults** shortcut on the **Start** menu. Applications that enumerate the contents of the **Start** menu should not show the **Set Program Access** and **Defaults** shortcut to the user.

### `REST_HIDECLOCK:0x40000070`

**Windows XP or later.** If nonzero, the system administrator has hidden the clock on the taskbar, overriding any user preference. Applications do not need to perform any special actions.

### `REST_NOLOWDISKSPACECHECKS:0x40000071`

**Windows XP or later.** If nonzero, the system administrator has disabled taskbar warnings when disk space has become low. Applications do not need to perform any special actions.

### `REST_NOENTIRENETWORK:0x40000072`

**Windows 2000 Service Pack 4 (SP4) or later.** If nonzero, the system administrator has disabled the **Entire Network** icon in **Network Places**. Applications should remove the ability to browse domain resources.

### `REST_NODESKTOPCLEANUP:0x40000073`

Windows XP, Windows**2003.** If nonzero, the system administrator has disabled the desktop cleaner. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_BITBUCKNUKEONDELETE:0x40000074`

**Windows XP or later.** If nonzero, the system administrator has required that deleted files be removed immediately instead of being placed in the **Recycle Bin**, overriding any user preference. Applications do not need to perform any special actions.

### `REST_BITBUCKCONFIRMDELETE:0x40000075`

**Windows XP or later.** If nonzero, the system administrator has disabled the user's ability to specify whether confirmation dialogs should be displayed when files are moved to the **Recycle Bin**. Applications do not need to perform any special actions.

### `REST_BITBUCKNOPROP:0x40000076`

**Windows XP or later.** If nonzero, the system administrator has disabled the user's ability to view or modify **Recycle Bin** properties. Applications do not need to perform any special actions.

### `REST_NODISPBACKGROUND:0x40000077`

**Windows XP or later.** If nonzero, the system administrator has disabled the user's ability to view or modify the desktop wallpaper. Applications should remove the ability to change the desktop wallpaper.

### `REST_NODISPSCREENSAVEPG:0x40000078`

**Windows XP or later.** If nonzero, the system administrator has disabled the user's ability to view or modify screensaver settings. Applications should remove the ability to change the screensaver or screensaver settings.

### `REST_NODISPSETTINGSPG:0x40000079`

**Windows XP or later.** If nonzero, the system administrator has disabled the user's ability to view or modify screen color depth and resolution settings. Applications should remove the ability to change display color depth and resolution.

### `REST_NODISPSCREENSAVEPREVIEW:0x4000007A`

**Windows XP or later.** Ignored.

### `REST_NODISPLAYCPL:0x4000007B`

**Windows XP or later.** If nonzero, the system administrator has disabled the **Display Properties** dialog box in **Control Panel**. Applications should remove the ability to change system colors, metrics, visual styles, font size, desktop wallpaper, screensaver, screensaver settings, screen color depth, or display resolution.

### `REST_HIDERUNASVERB:0x4000007C`

**Windows XP or later.** If nonzero, the system administrator has disabled the "Run As" command for Shell objects. Applications should remove corresponding functionality.

### `REST_NOTHUMBNAILCACHE:0x4000007D`

**Windows XP or later.** If nonzero, the system administrator has disabled caching of thumbnails. Applications do not need to perform any special actions.

### `REST_NOSTRCMPLOGICAL:0x4000007E`

**Windows XP SP1 or later, or IE_BACKCOMPAT_VERSION defined.**
If nonzero, the system administrator has specified that filenames should be sorted with the **StringCompare** function instead of the **StrCmpLogical** function. Applications that sort filenames should sort accordingly. (This policy does not apply to Windows 2000.)

### `REST_NOPUBLISHWIZARD:0x4000007F`

**Windows XP SP1 or later service pack, Windows Server 2003 or IE_BACKCOMPAT_VERSION defined.** Disables the Windows Publishing Wizard (WPW).**Windows Vista or later**: Not used.

### `REST_NOONLINEPRINTSWIZARD:0x40000080`

**Windows XP SP1 or later, or IE_BACKCOMPAT_VERSION defined.** Disables the Online Prints Wizard (OPW). **Windows Vista or later**: Not used.

### `REST_NOWEBSERVICES:0x40000081`

**Windows XP SP1 or later, or IE_BACKCOMPAT_VERSION defined.**
Disables the web specified services for both the Online Prints Wizard (OPW) and the Windows Publishing Wizard (WPW).

### `REST_ALLOWUNHASHEDWEBVIEW:0x40000082`

**Windows 2000 SP3 or later, Windows XP, or Windows Server 2003.** If nonzero, the system administrator has granted permission for unregistered web view templates to be displayed. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_ALLOWLEGACYWEBVIEW:0x40000083`

If nonzero, the system administrator has granted permission for old web view templates (created prior to Windows XP) to be converted to Windows XP templates. Applications do not need to perform any special actions. **Windows Vista or later**: Not used.

### `REST_REVERTWEBVIEWSECURITY:0x40000084`

**Windows 2000 SP3 or later, Windows XP, or Windows Server 2003.** If nonzero, the system administrator has reduced web view security to the level that existed in Windows 2000 SP2 or earlier. Applications do not need to perform any special actions. (This policy does not apply to Windows 2000 SP2 or earlier.) **Windows Vista or later**: Not used.

### `REST_INHERITCONSOLEHANDLES:0x40000086`

**Windows 2000 Service Pack 4 (SP4) or later.** If nonzero, the ShellExec function checks if the current process and target process are console processes that can inherit handles.

### `REST_SORTMAXITEMCOUNT:0x40000087`

**Windows XP SP2 and SP3 only. Not supported under Windows Vista or later.** Do not sort views with more items than this key. Useful for viewing large numbers of files in one folder.

### `REST_NOREMOTERECURSIVEEVENTS:0x40000089`

**Windows XP SP2 or later.** Do not register network change events recursively. This helps to avoid network traffic.

### `REST_NOREMOTECHANGENOTIFY:0x40000091`

**Windows XP SP2 or later.** Do not notify for remote change notifications.

### `REST_NOSIMPLENETIDLIST:0x40000092`

**Windows XP SP2 or SP3 only. Not supported under Windows Vista or later.** No simple network IDLists.

### `REST_NOENUMENTIRENETWORK:0x40000093`

**Windows XP SP2 or later.** Do not enumerate the entire network.

### `REST_NODETAILSTHUMBNAILONNETWORK:0x40000094`

**Windows XP SP2 and SP3 only. Not supported under Windows Vista or later.**

### `REST_NOINTERNETOPENWITH:0x40000095`

**Windows XP SP2 or later.** If nonzero, the system administrator has removed the ability to resolve file associations using the Internet. The option **Use the web service to find the appropriate program** is unavailable in the dialog displayed when the user selects **Open With** or double-clicks an unassociated file type.

### `REST_DONTRETRYBADNETNAME:0x4000009B`

**Windows XP SP2 or later.** In **Network Places**, if the provider returns ERROR_BAD_NET_NAME, do not retry.

### `REST_ALLOWFILECLSIDJUNCTIONS:0x4000009C`

**Windows XP SP2 or later, Windows Server 2003.** Re-enable legacy support for file.{guid} junctions in file system folders.

### `REST_NOUPNPINSTALL:0x4000009D`

**Windows XP SP2 or later.** Disable the **Install Universal Plug and Play (UPnP)** task in **My Network Places**.

### `REST_ARP_DONTGROUPPATCHES:0x400000AC`

If nonzero, the system administrator has removed the option to list individual patches in Add/Remove Programs. **Windows Vista or later**: Not used.

### `REST_ARP_NOCHOOSEPROGRAMSPAGE:0x400000AD`

If nonzero, the system administrator has removed the option to choose the programs page. **Windows Vista or later**: Not used.

### `REST_NODISCONNECT:0x41000001`

**Not supported under Windows Vista or later**. If nonzero, the system administrator has removed the **Disconnect** option from the **Start** menu and **Task Manager**. Applications should remove the ability to disconnect users from a Terminal Server session.

### `REST_NOSECURITY:0x41000002`

**Not supported under Windows Vista and later**. If nonzero, the system administrator has removed the **Windows Security** option from the **Start** menu and **Task Manager**. Applications do not need to perform any special actions.

### `REST_NOFILEASSOCIATE:0x41000003`

**Not supported under Windows Vista and later**. If nonzero, the system administrator has removed the ability to change file associations. Applications should not enable users to change file associations arbitrarily.

### `REST_ALLOWCOMMENTTOGGLE:0x41000004`

**Windows XP SP2 only. Not supported under Windows Vista or later.** Allows the user to toggle the position of the Comment and the Computer Name.

### `REST_USEDESKTOPINICACHE:0x41000005`

**Windows XP SP2 and SP3 only. Not supported under Windows Vista or later.** Cache desktop.ini entries from network folders.

#### - REST_ALLOWLEGACYLMZBEHAVIOR

**Windows XP SP2 only. Not supported under Windows Vista or later.** Indicates allowable LMZ behavior for ActiveX objects changed in Windows XP SP2, this policy gets the pre-Windows XP SP2 behavior.

#### - REST_NOCOMPUTERSNEARME

**Not supported under Windows Vista and later**. If nonzero, the system administrator has hidden the **Computers Near Me** icon in the **My Network Places** folder. Applications should remove access to CSIDL_COMPUTERSNEARME.

#### - REST_NORECENTDOCSNETHOOD

Windows Vista. If nonzero, the system administrator has disabled the automatic addition of shortcuts in **Network Neighborhood** to recently-accessed network resources. Applications do not need to perform any special actions.