# _OUTPUT_PACKET structure

## Description

OUTPUT_PACKET contains information about the data that is being written to a keyboard or mouse device by I8042prt.

## Members

### `Bytes`

Pointer to an array of bytes being written to an i8042 port device.

### `CurrentByte`

Specifies the index of the next byte to write.

### `ByteCount`

Specifies the number of bytes in the array of bytes located at **Bytes**.

### `State`

Specifies one of the following write states:

```
typedef enum _TRANSMIT_STATE {
    Idle = 0,
    SendingBytes
} TRANSMIT_STATE;
```

#### Idle

Identifies that a write is not in progress.

#### SendingBytes

Identifies that a write is in progress.

## Remarks

This structure is used with a [PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr) callback routine and a [PI8042_MOUSE_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_mouse_isr) callback routine.

## See also

[KbFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542294(v=vs.85))

[MouFilter_IsrHook](https://learn.microsoft.com/previous-versions/ff542379(v=vs.85))

[PI8042_KEYBOARD_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_keyboard_isr)

[PI8042_MOUSE_ISR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdd8042/nc-ntdd8042-pi8042_mouse_isr)