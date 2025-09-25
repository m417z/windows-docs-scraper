# IShellBrowser::BrowseObject

## Description

Informs Windows Explorer to browse to another folder.

## Parameters

### `pidl`

Type: **PCUIDLIST_RELATIVE**

The address of an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (item identifier list) structure that specifies an object's location. This value is dependent on the flag or flags set in the *wFlags* parameter.

### `wFlags`

Type: **UINT**

Flags specifying the folder to be browsed. It can be zero or one or more of the following values.

These flags specify whether another window is to be created.

#### SBSP_DEFBROWSER (0x0000)

Use default behavior, which respects the view option (the user setting to create new windows or to browse in place). In most cases, calling applications should use this flag.

#### SBSP_SAMEBROWSER

Browse to another folder with the same Windows Explorer window.

#### SBSP_NEWBROWSER

Creates another window for the specified folder.

The following flags specify the mode. These values are ignored if SBSP_SAMEBROWSER is specified or if SBSP_DEFBROWSER is specified and the user has selected **Browse In Place**.

#### SBSP_DEFMODE

Use the current window.

#### SBSP_OPENMODE

Specifies no folder tree for the new browse window. If the current browser does not match the SBSP_OPENMODE of the browse object call, a new window is opened.

#### SBSP_EXPLOREMODE

Specifies a folder tree for the new browse window. If the current browser does not match the SBSP_EXPLOREMODE of the browse object call, a new window is opened.

#### SBSP_HELPMODE

Not supported. Do not use.

#### SBSP_NOTRANSFERHIST

Do not transfer the browsing history to the new window.

The following flags specify the category of the *pidl* parameter.

#### SBSP_ABSOLUTE

An absolute PIDL, relative to the desktop.

#### SBSP_RELATIVE

A relative PIDL, relative to the current folder.

#### SBSP_PARENT

Browse the parent folder, ignore the PIDL.

#### SBSP_NAVIGATEBACK

Navigate back, ignore the PIDL.

#### SBSP_NAVIGATEFORWARD

Navigate forward, ignore the PIDL.

#### SBSP_ALLOW_AUTONAVIGATE (0x00010000)

Enable auto-navigation.

The following flags specify mode.

#### SBSP_KEEPSAMETEMPLATE (0x00020000)

**Windows Vista and later**. Not supported. Do not use.

#### SBSP_KEEPWORDWHEELTEXT (0x00040000)

**Windows Vista and later**. Navigate without clearing the search entry field.

#### SBSP_ACTIVATE_NOFOCUS (0x00080000)

**Windows Vista and later**. Navigate without the default behavior of setting focus into the new view.

The following flags control how history is manipulated as a result of navigation.

#### SBSP_CALLERUNTRUSTED (0x00800000)

**Microsoft Internet Explorer 6 Service Pack 2 (SP2) and later**. The navigation was possibly initiated by a webpage with scripting code already present on the local system.

#### SBSP_TRUSTFIRSTDOWNLOAD (0x01000000)

**Microsoft Internet Explorer 6 Service Pack 2 (SP2) and later**. The new window is the result of a user initiated action. Trust the new window if it immediately attempts to download content.

#### SBSP_UNTRUSTEDFORDOWNLOAD (0x02000000)

**Microsoft Internet Explorer 6 Service Pack 2 (SP2) and later**. The window is navigating to an untrusted, non-HTML file. If the user attempts to download the file, do not allow the download.

#### SBSP_NOAUTOSELECT

Suppress selection in the history pane.

#### SBSP_WRITENOHISTORY

Write no history of this navigation in the history Shell folder.

#### SBSP_CREATENOHISTORY (0x00100000)

0x00100000. **Windows 7 and later**. Do not add a new entry to the travel log. When the user enters a search term in the search box and subsequently refines the query, the browser navigates forward but does not add an additional travel log entry.

#### SBSP_TRUSTEDFORACTIVEX (0x10000000)

**Microsoft Internet Explorer 6 Service Pack 2 (SP2) and later**. The navigate should allow ActiveX prompts.

#### SBSP_FEEDNAVIGATION (0x20000000)

**Windows Internet Explorer 7 and later**. If allowed by current registry settings, give the browser a destination to navigate to.

#### SBSP_REDIRECT (0x40000000)

Enables redirection to another URL.

#### SBSP_INITIATEDBYHLINKFRAME (0x80000000)

#### SBSP_PLAYNOSOUND (0x00200000)

**Windows 7 and later**. Do not make the navigation complete sound for each keystroke in the search box.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Views can use this method to force Windows Explorer to browse to a specific place in the namespace. Typically, these are folders contained in the view.

#### Examples

```cpp
IShellBrowser* psb;
hr = IUnknown_QueryService(punkSite, SID_STopLevelBrowser, IID_PPV_ARGS(&psb));

if (SUCCEEDED(hr))
{
    hr = psb->BrowseObject(pidlSearch, SBSP_DEFBROWSER | SBSP_ABSOLUTE);
    psb->Release();
}
```

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)