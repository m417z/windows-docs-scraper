# NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS structure

## Description

Contains fields that describe return parameters for the Identify Directive.

## Members

### `DirectivesSupported`

A [NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_directive_identify_return_parameters_descriptor) structure containing values that indicate which directives are supported.

### `DirectivesEnabled`

A [NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_directive_identify_return_parameters_descriptor) structure containing values that indicate which directives are enabled.

## Remarks

This data structure is 4KB in size.

## See also

- [NVME_DIRECTIVE_IDENTIFY_RETURN_PARAMETERS_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_directive_identify_return_parameters_descriptor)