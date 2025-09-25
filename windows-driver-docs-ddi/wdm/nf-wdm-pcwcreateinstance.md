## Description

The `PcwCreateInstance` function creates a new counterset instance. Most developers will use a [CTRPP](https://learn.microsoft.com/windows/win32/perfctrs/ctrpp)-generated CreateXxx function instead of calling this function directly.

## Parameters

### `Instance` [out]

A pointer to receive the newly created instance. The instance should be closed using [PcwCloseInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwcloseinstance).

### `Registration` [in]

A pointer to the counterset registration that owns this instance. The registration is created using [PcwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwregister).

### `Name` [in]

A pointer to the Unicode string that contains the name of the instance of the counterset. This must not be NULL.

Instance `Name` values MUST be stable over time (the same logical instance should use the same `Name` value for all invocations of the callback) and MUST be unique. If the counterset is registered as single-instance, the instance `Name` should be blank (0-length). If the counterset registered as multi-instance, the instance `Name` should not be blank. Instance name matching is not case-sensitive, so `Name` values should not differ only by case.

### `Count` [in]

The number of descriptors provided in the `Data` parameter.

### `Data` [in]

An array of descriptors for the provider data blocks that contain the counter values of this instance. The data blocks referenced by the descriptors may be accessed at any time and must remain valid until the instance is closed by `PcwCloseInstance` or `PcwUnregister`.

## Return value

`PcwCreateInstance` returns one of the following values:

| Return code | Description |
|---|---|
| `STATUS_SUCCESS` | The instance was successfully created. |
| `STATUS_INVALID_PARAMETER_4` | The number of structures, specified by `Count`, is not valid for the registered provider. |
| `STATUS_INVALID_BUFFER_SIZE` | One of the provider data blocks is too small. For example, suppose that during the call to [PcwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwregister), the provider specifies that counter `X` is at offset 100 of the first data block of size 4 bytes. If the call to `PcwCreateInstance` specifies that the first data block is 50 bytes, this error status is returned. |
| `STATUS_INTEGER_OVERFLOW` | The size of the structure, specified by `Count`, overflows the data buffer. |

## Remarks

Counterset providers can supply information to the consumer through two different systems:

- The provider can supply a `PCW_CALLBACK` function that will be invoked by the Performance Counter Library as needed to collect data. For more information on this system, refer to the documentation for [PCW_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback).
- The provider can use `PcwCreateInstance` and `PcwCloseInstance` to maintain a list of available instances and the corresponding counter data. This system is simple to implement but limited in flexibility.

Before the provider uses this function, the provider must call the `PcwRegister` function to create a registration.

When a new instance arrives (e.g. when a device is plugged in), the provider should allocate and initialize a data block for the instance, call `PcwCreateInstance` with the name and data block for the instance, and then keep the values in the data block updated with counter values for the instance. When the instance becomes invalid (e.g. when a device is unplugged), the provider should call `PcwCloseInstance` and then delete the data block.

The provider must maintain data blocks (usually in paged or nonpaged pool) containing the current counter values for each instance.

`PcwCreateInstance` will automatically assign a unique id for the instance. To provide specific values for the instance id, implement a `PCW_CALLBACK` function instead of using `PcwCreateInstance`.

Use the PcwCloseInstance function to close the instance.

### CTRPP-generated CreateXxx function

Most developers do not need to call `PcwCreateInstance` directly. Instead, they will compile a manifest with the CTRPP tool and use the CreateXxx function from the CTRPP-generated header. The generated function will look like this:

```c
EXTERN_C __inline NTSTATUS
CreateMyCounterset(
    __deref_out PPCW_INSTANCE *Instance,
    __in PCUNICODE_STRING Name,
    __in const MY_COUNTER_DATA *MyCounterData
    )
{
    PCW_DATA Data[1];

    PAGED_CODE();

    Data[0].Data = MyCounterData;
    Data[0].Size = sizeof(MY_COUNTER_DATA);

    return PcwCreateInstance(Instance,
                             MyCounterset,
                             Name,
                             1,
                             Data);
}
```

The CTRPP-generated Create function will be named *Prefix*Create*Counterset*. *Prefix* is usually blank, but may be present if the `-prefix` parameter was used on the CTRPP command-line. *Counterset* is the name of the counterset, as specified in the manifest. The function will have Data parameters based on the structures defined in the manifest. The function will wrap the user-provided data block(s) into an array of `PCW_DATA` structures and then call `PcwCreateInstance`. Note that the function references a *Counterset* variable (`MyCounterset` in the example), which is a global variable that holds the counterset registration handle initialized by the CTRPP-generated RegisterXxx function.

## See also

[PcwCloseInstance function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwcloseinstance)

[PcwRegister function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwregister)