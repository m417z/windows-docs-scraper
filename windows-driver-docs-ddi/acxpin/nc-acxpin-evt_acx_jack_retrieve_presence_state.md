## Description

The **EVT_ACX_JACK_RETRIEVE_PRESENCE_STATE** callback function is implemented by the driver and is called when the state is requested for the specified jack.

## Parameters

### `Jack`

The physical terminal for which the presence state has been requested.

### `IsConnected`

A Boolean value indicating if the terminal specified by the *Jack* parameter is present and connected.

## Return value

**EVT_ACX_JACK_RETRIEVE_PRESENCE_STATE** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)