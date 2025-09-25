## Description

The `PcwCloseInstance` function closes a counterset instance that was created using [PcwCreateInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwcreateinstance). Most developers will use a [CTRPP](https://learn.microsoft.com/windows/win32/perfctrs/ctrpp)-generated CloseXxx function instead of calling this function directly.

## Parameters

### `Instance` [in]

A pointer to the counterset instance to close.

## Remarks

Use the `PcwCreateInstance` function to create a counterset instance.

You cannot call `PcwCloseInstance` on an instance if you have already called [PcwUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwunregister) for the corresponding counterset registration. When you unregister the counterset, any remaining instances are closed for you. Closing them again will crash the system.

### CTRPP-generated CloseXxx function

Most developers do not need to call `PcwCloseInstance` directly. Instead, they will compile a manifest with the CTRPP tool and use the CloseXxx function from the CTRPP-generated header. The generated function will look like this:

```c
EXTERN_C FORCEINLINE VOID
CloseMyCounterset(
    __in PPCW_INSTANCE Instance
    )
{
    PAGED_CODE();

    PcwCloseInstance(Instance);
}
```

The CTRPP-generated Close function will be named *Prefix*Close*CounterSet*. *Prefix* is usually blank, but may be present if the `-prefix` parameter was used on the CTRPP command-line. *CounterSet* is the name of the counterset, as specified in the manifest.

## See also

[PcwCreateInstance function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwcreateinstance)