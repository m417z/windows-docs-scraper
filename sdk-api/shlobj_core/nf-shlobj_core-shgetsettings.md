# SHGetSettings function

## Description

Retrieves the current Shell option settings.

## Parameters

### `psfs`

Type: **LPSHELLFLAGSTATE**

The address of a [SHELLFLAGSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shellflagstate) structure that receives the Shell option settings.

### `dwMask`

Type: **DWORD**

A set of flags that determine which members of *lpsfs* are being requested. This can be one or more of the following values.

#### SSF_DESKTOPHTML

The **fDesktopHTML** member is being requested.

#### SSF_DONTPRETTYPATH

The **fDontPrettyPath** member is being requested.

#### SSF_DOUBLECLICKINWEBVIEW

The **fDoubleClickInWebView** member is being requested.

#### SSF_HIDEICONS

The **fHideIcons** member is being requested.

#### SSF_MAPNETDRVBUTTON

The
**fMapNetDrvBtn** member is being requested.

#### SSF_NOCONFIRMRECYCLE

The
**fNoConfirmRecycle** member is being requested.

#### SSF_SHOWALLOBJECTS

The
**fShowAllObjects** member is being requested.

#### SSF_SHOWATTRIBCOL

The
**fShowAttribCol** member is being requested.

**Windows Vista:** Not used.

#### SSF_SHOWCOMPCOLOR

The
**fShowCompColor** member is being requested.

#### SSF_SHOWEXTENSIONS

The
**fShowExtensions** member is being requested.

#### SSF_SHOWINFOTIP

The
**fShowInfoTip** member is being requested.

#### SSF_SHOWSYSFILES

The
**fShowSysFiles** member is being requested.

#### SSF_WIN95CLASSIC

The
**fWin95Classic** member is being requested.

## See also

[SHGetSetSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsetsettings)