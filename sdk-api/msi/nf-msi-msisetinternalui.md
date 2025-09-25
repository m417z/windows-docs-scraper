# MsiSetInternalUI function

## Description

The
**MsiSetInternalUI** function enables the installer's internal user interface. Then this user interface is used for all subsequent calls to user-interface-generating installer functions in this process. For more information, see
[User Interface Levels](https://learn.microsoft.com/windows/desktop/Msi/user-interface-levels).

## Parameters

### `dwUILevel` [in]

Specifies the level of complexity of the user interface. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLUILEVEL_FULL** | Authored user interface with wizards, progress, and errors. |
| **INSTALLUILEVEL_REDUCED** | Authored user interface with wizard dialog boxes suppressed. |
| **INSTALLUILEVEL_BASIC** | Simple progress and error handling. |
| **INSTALLUILEVEL_DEFAULT** | The installer chooses an appropriate user interface level. |
| **INSTALLUILEVEL_NONE** | Completely silent installation. This includes suppressing the elevation prompt even if required. See **INSTALLUILEVEL_UACONLY** if you would like the user to be able to elevate. |
| **INSTALLUILEVEL_ENDDIALOG** | If combined with any above value, the installer displays a modal dialog box at the end of a successful installation or if there has been an error. No dialog box is displayed if the user cancels. |
| **INSTALLUILEVEL_PROGRESSONLY** | If combined with the **INSTALLUILEVEL_BASIC** value, the installer shows simple progress dialog boxes but does not display any modal dialog boxes or error dialog boxes. |
| **INSTALLUILEVEL_NOCHANGE** | No change in the UI level. However, if *phWnd* is not Null, the parent window can change. |
| **INSTALLUILEVEL_HIDECANCEL** | If combined with the **INSTALLUILEVEL_BASIC** value, the installer shows simple progress dialog boxes but does not display a **Cancel** button on the dialog. This prevents users from canceling the install. |
| **INSTALLUILEVEL_SOURCERESONLY** | If this value is combined with the **INSTALLUILEVEL_NONE** value, the installer displays only the dialog boxes used for source resolution. No other dialog boxes are shown. This value has no effect if the UI level is not **INSTALLUILEVEL_NONE**. It is used with an external user interface designed to handle all of the UI except for source resolution. In this case, the installer handles source resolution. |
 **INSTALLUILEVEL_UACONLY** | If combined with the **INSTALLUILEVEL_NONE** value, the installation will be completely silent except for the prompt for elevation if it is required. |

### `phWnd` [in, out]

Pointer to a window. This window becomes the owner of any user interface created. A pointer to the previous owner of the user interface is returned. If this parameter is null, the owner of the user interface does not change.

## Return value

The previous user interface level is returned. If an invalid *dwUILevel*  is passed, then **INSTALLUILEVEL_NOCHANGE** is returned.

## Remarks

The
**MsiSetInternalUI** function is useful when the installer must display a user interface. For example, if a feature is installed, but the source is a compact disc that must be inserted, the installer prompts the user for the compact disc. Depending on the nature of the installation, the application might also display progress indicators or query the user for information.

When Msi.dll is loaded, the user interface level is set to DEFAULT and the user interface owner is set to 0 (that is, the initial user interface owner is the desktop).

## See also

[Interface and Logging Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)