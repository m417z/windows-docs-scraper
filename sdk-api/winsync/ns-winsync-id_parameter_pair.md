# ID_PARAMETER_PAIR structure

## Description

Represents the format of a synchronization entity ID.

## Members

### `fIsVariable`

**TRUE** if the ID is variable length; otherwise, **FALSE**.

### `cbIdSize`

The length of the ID when *fIsVariable* is **FALSE**. The maximum length of the ID when *fIsVariable* is **TRUE**. Must be greater than zero.

## See also

[ID_PARAMETERS Structure](https://learn.microsoft.com/windows/desktop/api/winsync/ns-winsync-id_parameters)

[Windows Sync Structures](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-structures)