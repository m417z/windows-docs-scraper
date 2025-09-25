# FOLDERSETDATA structure

## Description

[**FOLDERSETDATA** may be altered or unavailable in subsequent versions of the operating system or product.]

Deprecated. Data used in [IBrowserService2::GetFolderSetData](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice2-getfoldersetdata).

## Members

### `_fs`

Type: **[FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings)**

The [FOLDERSETTINGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-foldersettings) structure containing folder view information.

### `_vidRestore`

Type: **SHELLVIEWID**

The last view used for this folder, used as a suggestion for this visit.

### `_dwViewPriority`

Type: **DWORD**

One of the following values indicating the priority used in choosing the view, listed from highest priority to lowest.

#### VIEW_PRIORITY_RESTRICTED

A Shell restriction is in place that forces this view to be used.

#### VIEW_PRIORITY_CACHEHIT

Current information for this view stored in the registry should be used.

#### VIEW_PRIORITY_STALECACHEHIT

Stored registry information for this view is out of date, so the default view for folders of this type should be used.

#### VIEW_PRIORITY_USEASDEFAULT

The default view for folders of this type should be used.

#### VIEW_PRIORITY_SHELLEXT

The Shell extension determines which view should be used.

#### VIEW_PRIORITY_CACHEMISS

No information on the view is stored in the registry, so the default view for folders of this type should be used.

#### VIEW_PRIORITY_INHERIT

The view from the previous window should be inherited.

#### VIEW_PRIORITY_SHELLEXT_ASBACKUP

If the classic view is operative, the inherited view should be used.

#### VIEW_PRIORITY_DESPERATE

The last known good view supported by the window should be used.

#### VIEW_PRIORITY_NONE

No view is available at this point.