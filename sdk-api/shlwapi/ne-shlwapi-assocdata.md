# ASSOCDATA enumeration

## Description

Used by [IQueryAssociations::GetData](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getdata) to define the type of data that is to be returned.

## Constants

### `ASSOCDATA_MSIDESCRIPTOR:1`

The component descriptor to pass to the Windows Installer API.

### `ASSOCDATA_NOACTIVATEHANDLER`

Attempts to activate a window are restricted. There is no data associated with this value.

### `ASSOCDATA_UNUSED1`

### `ASSOCDATA_HASPERUSERASSOC`

Defaults to user specified association.

### `ASSOCDATA_EDITFLAGS`

**Internet Explorer version 6 or later**. Gets the data stored in the EditFlags value of a file association [PROGID](https://learn.microsoft.com/windows/desktop/shell/fa-progids) registry key. This value consists of one or more [FILETYPEATTRIBUTEFLAGS](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-filetypeattributeflags). Compare against those values to determine which attributes have been set.

### `ASSOCDATA_VALUE`

**Internet Explorer version 6 or later**. Uses the *pwszExtra* parameter from the [IQueryAssociations::GetData](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-iqueryassociations-getdata) method as the value name.

### `ASSOCDATA_MAX`

#### - ASSOCDATA_QUERYCLASSSTORE

If this value is present, applications should check the Windows 2000 class store.