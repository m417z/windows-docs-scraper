# NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR structure

## Description

Contains values that describe return parameters for the Identify Directive.

This structure is used in the **DirectivesSupported** and **DirectivesEnabled** parameters of the [NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_directive_identify_return_parameters) structure.

## Members

### `Identify`

The return parameter is an [NVME_DIRECTIVE_TYPE_IDENTIFY](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_directive_types), a directive for an Identify operation.

### `Streams`

The return parameter is an [NVME_DIRECTIVE_TYPE_STREAMS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_directive_types), a directive for a Streams operation.

### `Reserved0`

### `Reserved1`

## Remarks

## See also

- [NVME_DIRECTIVE_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_directive_types)
- [NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_directive_identify_return_parameters)