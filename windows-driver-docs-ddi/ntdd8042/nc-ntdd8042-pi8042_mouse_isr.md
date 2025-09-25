# PI8042_MOUSE_ISR callback function

## Description

A PI8042_MOUSE_ISR-typed callback routine customizes the operation of the I8042prt mouse ISR.

## Parameters

### `IsrContext` [in]

Pointer to the filter device object of the driver that supplies this callback.

### `CurrentInput` [in]

Pointer to the input [MOUSE_INPUT_DATA](https://learn.microsoft.com/windows/win32/api/ntddmou/ns-ntddmou-mouse_input_data) structure being constructed by the ISR.

### `CurrentOutput` [in]

Pointer to an [OUTPUT_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_output_packet) structure, which specifies an array of bytes being written to the hardware device.

### `StatusByte` [in]

Specifies a status byte that is read from I/O port 60 when the interrupt occurs.

### `Byte` [in]

Specifies a data byte that is read from I/O port 64 when the interrupt occurs.

### `ContinueProcessing` [in, out]

Specifies, if **TRUE**, that processing in the I8042prt mouse ISR will continue after this callback completes. Otherwise, processing does not continue.

### `MouseState` [in]

Pointer to a [MOUSE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ne-ntdd8042-_mouse_state) enumeration value, which identifies the state of mouse input.

### `ResetSubState` [in]

Pointer to MOUSE_RESET_SUBSTATE enumeration value, which identifies the mouse reset substate. See the Remarks section.

## Return value

A PI8042_MOUSE_ISR callback returns **TRUE** if the I8042prt mouse ISR should continue; otherwise it returns **FALSE**.

## Remarks

A PI8042_MOUSE_ISR callback is not needed if the default operation of the I8042prt mouse ISR is sufficient.

An upper-level keyboard filter driver can provide a mouse ISR callback. After the I8042prt mouse ISR validates the interrupt, it calls the mouse ISR callback.

To reset a mouse, I8042prt goes through a sequence of operational substates, each one of which is identified by a MOUSE_RESET_SUBSTATE enumeration value. For more information about how I8042prt resets a mouse and the corresponding mouse reset substates, see the documentation of MOUSE_RESET_SUBSTATE in ntdd8042.h.

A PI8042_MOUSE_ISR callback runs in kernel mode at the IRQL of the I8042prt mouse ISR.

## See also

[MOUSE_INPUT_DATA](https://learn.microsoft.com/windows/win32/api/ntddmou/ns-ntddmou-mouse_input_data)

[MOUSE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ne-ntdd8042-_mouse_state)

[MouFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542379(v=vs.85))

[OUTPUT_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_output_packet)