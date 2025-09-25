# FDICABINETINFO structure

## Description

The **FDICABINETINFO** structure contains details about a particular cabinet file.

## Members

### `cbCabinet`

The total length of the cabinet file.

### `cFolders`

The count of the folders in the cabinet.

### `cFiles`

The count of the files in the cabinet.

### `setID`

The identifier of the cabinet set.

### `iCabinet`

The cabinet number in set. This index is zero based.

### `fReserve`

If this value is set to **TRUE**, a reserved area is present in the cabinet.

### `hasprev`

If this value is set to **TRUE**, the cabinet is linked to a previous cabinet. This is accomplished by having a file continued from the previous cabinet into the current one.

### `hasnext`

If this value is set to **TRUE**, the current cabinet is linked to the next cabinet by having a file continued from the current cabinet into the next one.

## See also

[FDIIsCabinet](https://learn.microsoft.com/windows/desktop/api/fdi/nf-fdi-fdiiscabinet)