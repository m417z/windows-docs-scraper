# NVM_SET_LIST structure

## Description

Contains an array of entries for the NVME Set Attributes command.

## Members

### `IdentifierCount`

The number of identifiers in the entry.

### `Reserved`

### `Entry`

An array of [NVME_SET_ATTRIBUTES_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_set_attributes_entry) structures that specify attribute values to be set by the set list.

## Remarks

## See also