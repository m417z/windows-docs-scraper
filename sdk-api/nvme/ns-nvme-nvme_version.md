# NVME_VERSION structure

## Description

Contains fields that specify the version number of the NVM Express specification that the controller implementation supports.

This structure is used in the **VS** field of the [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.TER`

Indicates the tertiary version number of the specification.

For example, if the version number is 1.2.3, then 3 is the tertiary version number.

### `DUMMYSTRUCTNAME.MNR`

Indicates the minor version number of the specification.

For example, if the version number is 1.2, then 2 is the minor version number.

### `DUMMYSTRUCTNAME.MJR`

Indicates the major version number of the specification.

For example, if the version number is 1.2, then 1 is the major version number.

### `AsUlong`

## Remarks

Valid versions of the NVM Express specification are: 1.0, 1.1, and 1.2.

## See also