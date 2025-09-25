# OLECMDID enumeration

## Description

Specifies which standard command is to be executed. A single value from this enumeration is passed in the *nCmdID* argument of [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec).

## Constants

### `OLECMDID_OPEN:1`

**File** menu, **Open** command

### `OLECMDID_NEW:2`

**File** menu, **New** command

### `OLECMDID_SAVE:3`

**File** menu, **Save** command

### `OLECMDID_SAVEAS:4`

**File** menu, **Save As** command

### `OLECMDID_SAVECOPYAS:5`

**File** menu, **Save Copy As** command

### `OLECMDID_PRINT:6`

**File** menu, **Print** command

### `OLECMDID_PRINTPREVIEW:7`

**File** menu, **Print Preview** command

### `OLECMDID_PAGESETUP:8`

**File** menu, **Page Setup** command

### `OLECMDID_SPELL:9`

**Tools** menu, **Spelling** command

### `OLECMDID_PROPERTIES:10`

**File** menu, **Properties** command

### `OLECMDID_CUT:11`

**Edit** menu, **Cut** command

### `OLECMDID_COPY:12`

**Edit** menu, **Copy** command

### `OLECMDID_PASTE:13`

**Edit** menu, **Paste** command

### `OLECMDID_PASTESPECIAL:14`

**Edit** menu, **Paste Special** command

### `OLECMDID_UNDO:15`

**Edit** menu, **Undo** command

### `OLECMDID_REDO:16`

**Edit** menu, **Redo** command

### `OLECMDID_SELECTALL:17`

**Edit** menu, **Select All** command

### `OLECMDID_CLEARSELECTION:18`

**Edit** menu, **Clear** command

### `OLECMDID_ZOOM:19`

**View** menu, **Zoom** command (see below for details.)

### `OLECMDID_GETZOOMRANGE:20`

Retrieves zoom range applicable to **View Zoom** (see below for details.)

### `OLECMDID_UPDATECOMMANDS:21`

Informs the receiver, usually a frame, of state changes. The receiver can then query the status of the commands whenever convenient.

### `OLECMDID_REFRESH:22`

Asks the receiver to refresh its display. Implemented by the document/object.

### `OLECMDID_STOP:23`

Stops all current processing. Implemented by the document/object.

### `OLECMDID_HIDETOOLBARS:24`

**View** menu, **Toolbars** command. Implemented by the document/object to hide its toolbars.

### `OLECMDID_SETPROGRESSMAX:25`

Sets the maximum value of a progress indicator if one is owned by the receiving object, usually a frame. The minimum value is always zero.

### `OLECMDID_SETPROGRESSPOS:26`

Sets the current value of a progress indicator if one is owned by the receiving object, usually a frame.

### `OLECMDID_SETPROGRESSTEXT:27`

Sets the text contained in a progress indicator if one is owned by the receiving object, usually a frame. If the receiver currently has no progress indicator, this text should be displayed in the status bar (if one exists) as with [IOleInPlaceFrame::SetStatusText](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setstatustext).

### `OLECMDID_SETTITLE:28`

Sets the title bar text of the receiving object, usually a frame.

### `OLECMDID_SETDOWNLOADSTATE:29`

Called by the object when downloading state changes. Takes a VT_BOOL parameter, which is **TRUE** if the object is downloading data and **FALSE** if it not. Primarily implemented by the frame.

### `OLECMDID_STOPDOWNLOAD:30`

Stops the download when executed. Typically, this command is propagated to all contained objects. When queried, sets MSOCMDF_ENABLED. Implemented by the document/object.

### `OLECMDID_ONTOOLBARACTIVATED:31`

### `OLECMDID_FIND:32`

**Edit** menu, **Find** command

### `OLECMDID_DELETE:33`

**Edit** menu, **Delete** command

### `OLECMDID_HTTPEQUIV:34`

Issued in response to **HTTP-EQUIV** metatag and results in a call to the deprecated [OnHttpEquiv](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-onhttpequiv) method with the *fDone* parameter set to **false**. This command takes a **VT_BSTR** parameter which is passed to **OnHttpEquiv**.

### `OLECMDID_HTTPEQUIV_DONE:35`

Issued in response to **HTTP-EQUIV** metatag and results in a call to the deprecated [OnHttpEquiv](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-onhttpequiv) method with the *fDone* parameter set to **true**. This command takes a **VT_BSTR** parameter which is passed to **OnHttpEquiv**.

### `OLECMDID_ENABLE_INTERACTION:36`

Pauses or resumes receiver interaction. This command takes a **VT_BOOL** parameter that pauses interaction when set to **FALSE** and resumes interaction when set to **TRUE**.

### `OLECMDID_ONUNLOAD:37`

Notifies the receiver of an intent to close the window imminently. This command takes a **VT_BOOL** output parameter that returns **TRUE** if the receiver can close and **FALSE** if it can't.

### `OLECMDID_PROPERTYBAG2:38`

This command has no effect.

### `OLECMDID_PREREFRESH:39`

Notifies the receiver that a refresh is about to start.

### `OLECMDID_SHOWSCRIPTERROR:40`

Tells the receiver to display the script error message.

### `OLECMDID_SHOWMESSAGE:41`

This command takes an [IHTMLEventObj](https://learn.microsoft.com/previous-versions/hh773930(v=vs.85)) input parameter that contains a message that the receiver shows.

### `OLECMDID_SHOWFIND:42`

Tells the receiver to show the Find dialog box. It takes a **VT_DISPATCH** input param.

### `OLECMDID_SHOWPAGESETUP:43`

Tells the receiver to show the Page Setup dialog box. It takes an [IHTMLEventObj2](https://learn.microsoft.com/previous-versions/hh773930(v=vs.85)) input parameter.

### `OLECMDID_SHOWPRINT:44`

Tells the receiver to show the Print dialog box. It takes an [IHTMLEventObj2](https://learn.microsoft.com/previous-versions/hh773930(v=vs.85)) input parameter.

### `OLECMDID_CLOSE:45`

The exit command for the File menu.

### `OLECMDID_ALLOWUILESSSAVEAS:46`

Supports the [QueryStatus](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus) method.

### `OLECMDID_DONTDOWNLOADCSS:47`

Notifies the receiver that CSS files should not be downloaded when in [DesignMode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationdesignmodesettings).

### `OLECMDID_UPDATEPAGESTATUS:48`

This command has no effect.

### `OLECMDID_PRINT2:49`

**File** menu, updated **Print** command

### `OLECMDID_PRINTPREVIEW2:50`

**File** menu, updated **Print Preview** command

### `OLECMDID_SETPRINTTEMPLATE:51`

Sets an explicit Print Template value of **TRUE** or **FALSE**, based on a **VT_BOOL** input parameter.

### `OLECMDID_GETPRINTTEMPLATE:52`

Gets a **VT_BOOL** output parameter indicating whether the Print Template value is **TRUE** or **FALSE**.

### `OLECMDID_PAGEACTIONBLOCKED:55`

Indicates that a page action has been blocked. PAGEACTIONBLOCKED is designed for use with applications that host the Internet Explorer WebBrowser control to implement their own UI.

### `OLECMDID_PAGEACTIONUIQUERY:56`

Specifies which actions are displayed in the Internet Explorer notification band.

### `OLECMDID_FOCUSVIEWCONTROLS:57`

Causes the Internet Explorer WebBrowser control to focus its default notification band. Hosts can send this command at any time. The return value is S_OK if the band is present and is in focus, or S_FALSE otherwise.

### `OLECMDID_FOCUSVIEWCONTROLSQUERY:58`

This notification event is provided for applications that display Internet Explorers default notification band implementation. By default, when the user presses the ALT-N key combination, Internet Explorer treats it as a request to focus the notification band.

### `OLECMDID_SHOWPAGEACTIONMENU:59`

Causes the Internet Explorer WebBrowser control to show the Information Bar menu.

### `OLECMDID_ADDTRAVELENTRY:60`

Causes the Internet Explorer WebBrowser control to create an entry at the current Travel Log offset. The Docobject should implement [ITravelLogClient](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768478(v=vs.85)) and [IPersist](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersist) interfaces, which are used by the Travel Log as it processes this command with calls to GetWindowData and GetPersistID, respectively.

### `OLECMDID_UPDATETRAVELENTRY:61`

Called when LoadHistory is processed to update the previous Docobject state. For synchronous handling, this command can be called before returning from the LoadHistory call. For asynchronous handling, it can be called later.

### `OLECMDID_UPDATEBACKFORWARDSTATE:62`

Updates the state of the browser's Back and Forward buttons.

### `OLECMDID_OPTICAL_ZOOM:63`

Windows Internet Explorer 7 and later. Sets the zoom factor of the browser. Takes a VT_I4 parameter in the range of 10 to 1000 (percent).

### `OLECMDID_OPTICAL_GETZOOMRANGE:64`

Windows Internet Explorer 7 and later. Retrieves the minimum and maximum browser zoom factor limits. Returns a VT_I4 parameter; the LOWORD is the minimum zoom factor, the HIWORD is the maximum.

### `OLECMDID_WINDOWSTATECHANGED:65`

Windows Internet Explorer 7 and later. Notifies the Internet Explorer WebBrowser control of changes in window states, such as losing focus, or becoming hidden or minimized. The host indicates what has changed by setting OLECMDID_WINDOWSTATE_FLAG option flags in nCmdExecOpt.

### `OLECMDID_ACTIVEXINSTALLSCOPE:66`

Windows Internet Explorer 8 with Windows Vista. Has no effect with Windows Internet Explorer 8 with Windows XP. Notifies Trident to use the indicated Install Scope to install the ActiveX Control specified by the indicated Class ID. For more information, see the Remarks section.

### `OLECMDID_UPDATETRAVELENTRY_DATARECOVERY:67`

Internet Explorer 8. Unlike OLECMDID_UPDATETRAVELENTRY, this updates a Travel Log entry that is not initialized from a previous Docobject state. While this command is not called from [IPersistHistory::LoadHistory](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768216(v=vs.85)), it can be called separately to save browser state that can be used later to recover from a crash.

### `OLECMDID_SHOWTASKDLG:68`

### `OLECMDID_POPSTATEEVENT:69`

### `OLECMDID_VIEWPORT_MODE:70`

### `OLECMDID_LAYOUT_VIEWPORT_WIDTH:71`

### `OLECMDID_VISUAL_VIEWPORT_EXCLUDE_BOTTOM:72`

### `OLECMDID_USER_OPTICAL_ZOOM:73`

### `OLECMDID_PAGEAVAILABLE:74`

### `OLECMDID_GETUSERSCALABLE:75`

### `OLECMDID_UPDATE_CARET:76`

### `OLECMDID_ENABLE_VISIBILITY:77`

### `OLECMDID_MEDIA_PLAYBACK:78`

### `OLECMDID_SETFAVICON:79`

### `OLECMDID_SET_HOST_FULLSCREENMODE:80`

### `OLECMDID_EXITFULLSCREEN:81`

### `OLECMDID_SCROLLCOMPLETE:82`

### `OLECMDID_ONBEFOREUNLOAD:83`

### `OLECMDID_SHOWMESSAGE_BLOCKABLE:84`

### `OLECMDID_SHOWTASKDLG_BLOCKABLE:85`

## Remarks

In OLE Compound Documents technology, an object that is being edited in-place disables the **Zoom** control on its toolbar and the **Zoom** command on its **View** menu, because, the **Zoom** command applies logically to the container document, not to the object. The OLECMDID_ZOOM and OLECMDID_GETZOOMRANGE commands notify the container's frame object of the zoom range it should use to display a document object in its user interface. The container frame is the client-side object that implements [IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe) and, optionally, [IOleCommandTarget](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iolecommandtarget).

The OLECMDID_ZOOM command takes one **LONG** argument as input and writes one **LONG** argument on output. This command is used for three purposes:

* To query the current zoom value. The caller of [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) passes OLECMDEXECOPT_DONTPROMPTUSER as the execute option in *nCmdExecOpt* and **NULL** for pvIn. The object returns the current zoom value in *pvaOut*. When the object goes UI active, it retrieves the current zoom value from the container's frame object using this same mechanism and updates its zoom control with the returned value.
* To display the **Zoom** dialog box. The caller of [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) passes OLECMDEXECOPT_PROMPTUSER in *nCmdExecOpt*. The caller can optionally pass the initial value for the dialog box through *pvaIn*; otherwise *pvaIn* must be **NULL**. If the user clicks **Cancel**, the object returns OLECMDERR_E_CANCELED. If the user clicks **OK**, the object passes the user-selected value in *pvaOut*. When user chooses the **Zoom** command from the **View** menu, the object calls the container's frame object in the same manner. The container then zooms the document to the user selected value, and the object updates its **Zoom** control with that value.
* To set a **Zoom** value. The caller of [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) passes OLECMDEXECOPT_DONTPROMPTUSER in *nCmdExecOpt* and passes the zoom value to apply through *pvaIn*. The object validates and normalizes the new value and returns the validated value in *pvaOut*. When the user selects a new zoom value (using the **Zoom** control on the toolbar, for instance), the object calls the container's frame object in this manner. The container zooms the document to 100 percent, and the object updates the **Zoom** control with that value.

The OLECMDID_GETZOOMRANGE command is used to determine the range of valid zoom values from an object that implements [IOleCommandTarget](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iolecommandtarget). The caller passes MSOCMDEXECOPT_DONTPROMPTUSER in nCmdExecOpt and **NULL** for *pvaIn*. The object returns its zoom range in *pvaOut* where the HIWORD contains the maximum zoom value and the LOWORD contains the minimum zoom value. Typically this command is used when the user drops down the **Zoom** control on the toolbar of the UI-active object. The applications and objects that support this command are required to support all the integral zoom values that are within the (min,max) pair they return.

The OLECMDID_ACTIVEXINSTALLSCOPE command notifies Trident to use the indicated Install Scope to install the ActiveX Control specified by the indicated class ID. The Install Scope is passed in a VT_ARRAY in pvaIn of the [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) method whose elements are as follows.

| Data | VARIANT Type | Index |
| --- | --- | --- |
| Class ID | VT_BSTR | 0 |
| Install Scope | VT_UI4 | 1 |

The Install Scope must be one of the following values.

| Value | Description |
| --- | --- |
| INSTALL_SCOPE_USERS | The ActiveX control should register to HKCU and for the instant user only. |
| INSTALL_SCOPE_MACHINE | The ActiveX control should register to HKLM and across the computer |

The following is an example use of the OLECMDID_ACTIVEXINSTALLSCOPE command.

```cpp
IOleCommandTarget::Exec(
NULL, // Pointer to command group
OLECMDARGINDEX_ACTIVEXINSTALL_INSTALLSCOPE, // ID of command to execute
NULL, // Options
&varArgs, // pvain pointer to input arguments
NULL) // pointer to command output

```

## See also

[IOleCommandTarget](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-iolecommandtarget)

[IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec)

[IOleInPlaceFrame](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceframe)