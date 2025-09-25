# ADDRESS structure

## Description

Represents an address. It is used in the
[STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe) structure.

## Members

### `Offset`

The offset into the segment, or a 32-bit virtual address. The interpretation of this value depends on the value contained in the **Mode** member.

### `Segment`

The segment number. This value is used only for 16-bit addressing.

### `Mode`

The addressing mode. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **AddrMode1616**<br><br>0 | 16:16 addressing. To support this addressing mode, you must supply a [TranslateAddressProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-ptranslate_address_routine) callback function. |
| **AddrMode1632**<br><br>1 | 16:32 addressing. To support this addressing mode, you must supply a [TranslateAddressProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-ptranslate_address_routine) callback function. |
| **AddrModeReal**<br><br>2 | Real-mode addressing. To support this addressing mode, you must supply a [TranslateAddressProc64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nc-dbghelp-ptranslate_address_routine) callback function. |
| **AddrModeFlat**<br><br>3 | Flat addressing. This is the only addressing mode supported by the library. |

## Remarks

This structure supersedes the **ADDRESS** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **ADDRESS** is defined as follows in DbgHelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define ADDRESS ADDRESS64
#define LPADDRESS LPADDRESS64
#else
typedef struct _tagADDRESS {
    DWORD         Offset;
    WORD          Segment;
    ADDRESS_MODE  Mode;
} ADDRESS, *LPADDRESS;
#endif
```

## See also

[STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe)