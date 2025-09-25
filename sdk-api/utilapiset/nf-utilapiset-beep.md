# Beep function

## Description

Generates simple tones on the speaker. The function is synchronous; it performs an alertable wait and does not return control to its caller until the sound finishes.

## Parameters

### `dwFreq` [in]

The frequency of the sound, in hertz. This parameter must be in the range 37 through 32,767 (0x25 through 0x7FFF).

### `dwDuration` [in]

The duration of the sound, in milliseconds.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

 A long time ago, all PC computers shared a common 8254 programmable interval timer chip for the generation of primitive sounds. The **Beep** function was written specifically to emit a beep on that piece of hardware.

On these older systems, muting and volume controls have no effect on **Beep**; you would still hear the tone. To silence the tone, you used the following commands:

**net stop beep**

**sc config beep start= disabled**

Since then, sound cards have become standard equipment on almost all PC computers. As sound cards became more common, manufacturers began to remove the old timer chip from computers. The chips were also excluded from the design of server computers. The result is that **Beep** did not work on all computers without the chip. This was okay because most developers had moved on to calling the [MessageBeep](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebeep) function that uses whatever is the default sound device instead of the 8254 chip.

Eventually because of the lack of hardware to communicate with, support for playing sound from the motherboard speaker was dropped in Windows Vista and Windows XP 64-Bit Edition.

In Windows 7, **Beep** was rewritten to pass the beep to the default sound device for the session. This is normally the sound card, except when run under Terminal Services, in which case the beep is rendered on the client.

#### Examples

The following example demonstrates the use of this function.

```cpp
Beep( 750, 300 );

```

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[MessageBeep](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebeep)

[Notifying the User](https://learn.microsoft.com/windows/desktop/Debug/notifying-the-user)