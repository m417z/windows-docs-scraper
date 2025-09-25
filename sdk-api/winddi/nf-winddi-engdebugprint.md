# EngDebugPrint function

## Description

The **EngDebugPrint** function prints the specified debug message to the kernel debugger.

## Parameters

### `StandardPrefix` [in]

Pointer to a string that is prepended to *DebugMessage*.

### `DebugMessage` [in]

Pointer to a string containing the debug message to be printed.

### `ap` [in]

Specifies the variable argument list.

## Return value

None

## Remarks

**EngDebugPrint** is useful for debugging drivers that are under development. It prints *StandardPrefix*, followed by *DebugMessage*, to the kernel debugger.

The *StandardPrefix* parameter acts as a unique identifier of the driver executing the debug statement; therefore, the same string should be used for all calls to **EngDebugPrint** by a single driver.

The *DebugMessage* parameter is a variable argument ASCII C string; that is, it can contain both ordinary characters and C-style conversion specifications. The argument list contained in *ap* can have any number of arguments of any type in it.

An example use of **EngDebugPrint** follows:

```
#define STANDARD_DEBUG_PREFIX     "Permedia: "
LONG bank;
LONG width;
...
VOID MyDebugPrint(PCHAR DebugMessage, ...)
{
    va_list ap;

    va_start(ap, DebugMessage);
    EngDebugPrint(STANDARD_DEBUG_PREFIX, DebugMessage, ap);
    va_end(ap);
}
...
MyDebugPrint("Bank: %lx; Width: %ld", bank, width);
```

**Note** The Microsoft Windows Driver Kit (WDK) does not contain the Permedia (*3dlabs.htm* and *Perm3.htm*) and FrameBuffer (*Framebuf.htm)*  sample display drivers. You can get these sample drivers from the Windows Server 2003 SP1 Driver Development Kit (DDK), which you can download from the [DDK - Windows Driver Development Kit](https://learn.microsoft.com/windows-hardware/drivers/devtest/) page of the WDHC website.

## See also

[EngDebugBreak](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdebugbreak)