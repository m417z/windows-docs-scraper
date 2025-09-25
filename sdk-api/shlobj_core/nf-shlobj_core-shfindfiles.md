# SHFindFiles function

## Description

[**SHFindFiles** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Displays the **Search** window UI.

## Parameters

### `pidlFolder` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

The folder from which to start the search. This folder appears in the **Look in:** box in the **Search** window. This folder and all of its subfolders are searched unless users choose other options in the **Search** window's **More Advanced Options**. This value can be **NULL**.

### `pidlSaveFile` [in, optional]

Type: **PCIDLIST_ABSOLUTE**

This parameter is not used and must be set to **NULL**.

**Windows Server 2003 and Windows XP:** A saved search file (.fnd) to load. You can save search parameters to a .fnd file after the search is begun. This value can be **NULL**.

## Return value

Type: **BOOL**

Returns **TRUE** if successful in displaying the **Search** window; otherwise **FALSE**.