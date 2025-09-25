## Description

The **EVT_ACX_PIN_RETRIEVE_NAME** callback function is implemented by the driver and is called when the name is requested for the specified pin.

## Parameters

### `Pin`

An [ACXPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/) object representing the specific pin for which the name is being requested.

### `Name`

A pointer to a Unicode string to be populated with the requested pin name.

## Return value

**EVT_ACX_PIN_RETRIEVE_NAME** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

ACX pre-allocates the UNICODE_STRING buffer before invoking this callback. The maximum number of wchars for the name is MAX_PATH not including the NULL terminator. The driver is responsible for copying the name in the buffer and for updating the Unicode struct *Length* field to the number of bytes used by the name string, not including the NULL terminator.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)