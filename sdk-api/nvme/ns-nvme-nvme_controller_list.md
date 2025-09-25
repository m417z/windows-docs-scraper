# NVME_CONTROLLER_LIST structure

## Description

Contains an ordered list of controller identifiers. Each controller identifier corresponds to the **CNTLID** field of a [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) structure which defines the capabilities and characteristics of a controller in the NVM subsystem.

Unused entries in the controller list are zero filled.

## Members

### `NumberOfIdentifiers`

Specifies the number of controller entries in the list.

There may be up to 2047 identifiers in the list. A value of 0 indicates that there are no controllers in the list.

### `ControllerID`

Contains a list of unique controller identifiers.

If the first value in the list is `0h`, the list is empty and there are no controllers in the list.

## Remarks

## See also

- [NVME_IDENTIFY_CONTROLLER_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data)