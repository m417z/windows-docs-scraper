# PI8042_KEYBOARD_ISR callback function

## Description

A PI8042_KEYBOARD_ISR-typed callback routine customizes the operation of the I8042prt keyboard ISR.

## Parameters

### `IsrContext` [in]

Pointer to the filter device object of the driver that supplies a callback.

### `CurrentInput` [in]

Pointer to the input [KEYBOARD_INPUT_DATA](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_input_data) structure that is being constructed by the ISR.

### `CurrentOutput` [in]

Pointer to an [OUTPUT_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_output_packet) structure, which specifies an array of bytes that is being written to the hardware device.

### `StatusByte` [in]

Specifies the status byte that is read from I/O port 60 when an interrupt occurs.

### `Byte` [in]

Specifies the data byte that is read from I/O port 64 when an interrupt occurs.

### `ContinueProcessing` [out]

Specifies, if **TRUE**, that processing in the I8042prt keyboard ISR will continue after this callback completes. Otherwise, processing does not continue.

### `ScanState` [in]

Pointer to a [KEYBOARD_SCAN_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ne-ntdd8042-_keyboard_scan_state) enumeration value, which identifies the keyboard scan state.

## Return value

A PI8042_KEYBOARD_ISR callback returns **TRUE** if the I8042prt keyboard ISR should continue; otherwise it returns **FALSE**.

## Remarks

A PI8042_KEYBOARD_ISR callback is not needed if the default operation of the I8042prt keyboard ISR is sufficient.

An optional, vendor-supplied, upper-level keyboard filter driver can provide a PI8042_KEYBOARD_ISR callback. The I8042prt ISR calls the callback after it validates the interrupt and reads the scan code.

The PI8042_KEYBOARD_ISR callback runs in kernel mode at the IRQL of the I8042prt keyboard ISR.

## See also

[KEYBOARD_INPUT_DATA](https://learn.microsoft.com/windows/win32/api/ntddkbd/ns-ntddkbd-keyboard_input_data)

[KEYBOARD_SCAN_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ne-ntdd8042-_keyboard_scan_state)

[KbFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542294(v=vs.85))

[OUTPUT_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/ns-ntdd8042-_output_packet)

[PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr)