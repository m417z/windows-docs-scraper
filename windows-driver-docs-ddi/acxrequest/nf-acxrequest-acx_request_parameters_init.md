## Description

The **ACX_REQUEST_PARAMETERS_INIT** function initializes an ACX_REQUEST_PARAMETERS struct.

## Parameters

### `Parameters`

An [ACX_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nf-acxrequest-acxrequestgetparameters) structure that stores the ACX/KS operation parameters.

## Remarks

### Example

Example usage is shown below.

```cpp

    ACX_REQUEST_PARAMETERS params;

    ACX_REQUEST_PARAMETERS_INIT(&params);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)