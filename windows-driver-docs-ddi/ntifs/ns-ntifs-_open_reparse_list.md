# _OPEN_REPARSE_LIST structure

## Description

 Points to a list of **OPEN_REPARSE_LIST_ENTRY**
structures that specify the tag and possibly GUID that should be opened directly without returning **STATUS_REPARSE**.

## Members

### `OpenReparseList`

 A pointer to a list of **OPEN_REPARSE_LIST_ENTRY**
structures that specify the tag and possibly GUID that should be opened directly without returning **STATUS_REPARSE**.