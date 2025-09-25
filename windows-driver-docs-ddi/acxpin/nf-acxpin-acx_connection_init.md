## Description

Initializes an [ACX_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_connection) structure for use in configuring a connection.

## Parameters

### `Connection` [out]

Pointer to an [ACX_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_connection) object to be initialized.

### `FromObject` [in]

The **ACXOBJECT** from which the connection starts.

### `ToObject` [in]

The **ACXOBJECT** to which the connection ends.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_connection)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)