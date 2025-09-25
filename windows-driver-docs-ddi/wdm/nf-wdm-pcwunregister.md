## Description

The `PcwUnregister` function closes the specified counterset registration. Most developers will use a [CTRPP](https://learn.microsoft.com/windows/win32/perfctrs/ctrpp)-generated UnregisterXxx function instead of calling this function directly.

## Parameters

### `Registration`

[in A pointer to the registration being closed.

## Remarks

The `PcwUnregister` function closes the specified counterset registration. Instances owned by the counterset registration are automatically closed. These instances should not be accessed by the provider while the counterset is being unregistered or after the counterset is unregistered.

Before the provider uses this function, the provider must call the [PcwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwregister) function to create a registration.

### CTRPP-generated UnregisterXxx function

Most developers do not need to call `PcwUnregister` directly. Instead, they will compile a manifest with the CTRPP tool and use the UnregisterXxx function from the CTRPP-generated header. The generated function will look like this:

```c
EXTERN_C FORCEINLINE VOID
UnregisterMyCounterset(
    VOID
    )
{
    PAGED_CODE();

    PcwUnregister(MyCounterset);
}
```

The CTRPP-generated Unregister function will be named *Prefix*Unregister*CounterSet*. *Prefix* is usually blank, but may be present if the `-prefix` parameter was used on the CTRPP command-line. *CounterSet* is the name of the counterset, as specified in the manifest. Note that the function references a *Counterset* variable (`MyCounterset` in the example), which is a global variable that holds the counterset registration handle initialized by the CTRPP-generated RegisterXxx function.

## See also

[PcwRegister function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwregister)