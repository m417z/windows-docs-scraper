## Description

The `PcwAddInstance` function adds the specified instance of the counterset to the consumer buffer. Most developers will use a [CTRPP](https://learn.microsoft.com/windows/win32/perfctrs/ctrpp)-generated AddXxx function instead of calling this function directly. See Remarks below for more info.

## Parameters

### `Buffer` [in]

A handle to the system-managed buffer to which the instance of the counterset will be added. When the buffer comes from a `PcwCallbackEnumerateInstances` notification, `PcwAddInstance` will record only the Name and Id of the instance. When the buffer comes from a `PcwCallbackCollectData` notification, `PcwAddInstance` will record the Name, Id, and Data (counter values) of the instance.

### `Name` [in]

A pointer to the Unicode string that contains the name of the counterset instance. This must not be NULL.

Instance `Name` values MUST be stable over time (the same logical instance should use the same `Name` value for all invocations of the callback) and MUST be unique. If the counterset is registered as single-instance, the instance `Name` should be blank (0-length). If the counterset registered as multi-instance, the instance `Name` should not be blank. Instance name matching is not case-sensitive, so `Name` values should not differ only by case.

### `Id` [in]

A numeric value that specifies the `Id` (identifier) associated with the counterset instance.

Instance `Id` values MUST be stable over time (the same instance should use the same `Id` value for all invocations of the callback), should be unique (e.g. do not use 0 for all instances), and should be less than 0xFFFFFFFE (do not use `PCW_ANY_INSTANCE_ID` for any instances). When possible, the instance `Id` should be meaningful (e.g. a Process counterset might use a PID as the `Id`) instead of arbitrary (e.g. a sequence number).

### `Count` [in]

The number of descriptors provided in the `Data` parameter.

### `Data` [in]

An array of descriptors for the provider data blocks that contain the counter values of this instance.

## Return value

`PcwAddInstance` returns one of the following values:

| Return code | Description |
|---|---|
| `STATUS_SUCCESS` | The instance was successfully added to the buffer. |
| `STATUS_INVALID_BUFFER_SIZE` | One of the provider data blocks is too small. For example, suppose that during the call to [PcwRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwregister), the provider specifies that counter `X` is at offset 100 of the first data block of size 4 bytes. If the call to `PcwAddInstance` specifies that the first data block is 50 bytes, this error status is returned. |

## Remarks

The `PcwAddInstance` function should called by the provider-defined [PCW_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback) routine when the notification type is either `PcwCallbackEnumerateInstances` or `PcwCallbackCollectData`. The `Buffer` to be used comes from the `Info` parameter for the `PCW_CALLBACK` routine, e.g. `Info->EnumerateInstances.Buffer` or `Info->CollectData.Buffer`.

When called for a `PcwCallbackEnumerateInstances` notification, `PcwAddInstance` adds the `Name` and `Id` values to the buffer. When called for a `PcwCallbackCollectData` notification, `PcwAddInstance` adds the `Name`, `Id`, and counter data values to the buffer.

### CTRPP-generated Add\*\*\* function

Most developers do not need to call `PcwAddInstance` directly. Instead, they will compile a manifest with the CTRPP tool and use the Add\*\*\* function from the CTRPP-generated header. The generated function will look like this:

```c
EXTERN_C __inline NTSTATUS
AddMyCounterset(
    __in PPCW_BUFFER Buffer,
    __in PCUNICODE_STRING Name,
    __in ULONG Id,
    __in_opt const MY_COUNTER_DATA *MyCounterData
    )
{
    PCW_DATA Data[1];

    PAGED_CODE();

    Data[0].Data = MyCounterData;
    Data[0].Size = sizeof(MY_COUNTER_DATA);

    return PcwAddInstance(Buffer,
                          Name,
                          Id,
                          1,
                          Data);
}
```

The CTRPP-generated Add function will be named *Prefix*Add*Counterset*. *Prefix* is usually blank, but may be present if the `-prefix` parameter was used on the CTRPP command-line. *Counterset* is the name of the counterset, as specified in the manifest. The function will have Data parameters based on the structures defined in the manifest. The function will wrap the user-provided data block(s) into an array of `PCW_DATA` structures and then call `PcwAddInstance`.

## See also

[PCW_CALLBACK callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcw_callback)