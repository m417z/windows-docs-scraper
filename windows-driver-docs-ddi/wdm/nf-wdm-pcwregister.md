## Description

The `PcwRegister` function creates a new counterset registration. Most developers will use a [CTRPP](https://learn.microsoft.com/windows/win32/perfctrs/ctrpp)-generated RegisterXxx function instead of calling this function directly.

## Parameters

### `Registration` [out]

A pointer to a PPCW_REGISTRATION. Receives the handle to the new registration. The registration should be closed using [PcwUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwunregister).

### `Info` [in]

A pointer to a [**PCW_REGISTRATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_registration_information) structure that contains the details about the counterset being registered.

## Return value

`PcwRegister` returns one of the following values:

| Return code | Description |
|---|---|
| `STATUS_SUCCESS` | The counterset is successfully registered. |
| `STATUS_INTEGER_OVERFLOW` | The number of the counters exposed by this registration exceeds the maximum supported. |
| `STATUS_NO_MEMORY` | There is not enough space available to allocate memory for the counters. |
| `STATUS_INVALID_PARAMETER_2` | A problem was found in the `Info` parameter. See below for some possible causes. |

`PcwRegister` may return `STATUS_INVALID_PARAMETER_2` in the following cases:

- The `Info->Name->Length` field is 0 or is not a multiple of `sizeof(WCHAR)`.

- The `Info->Version` field does not match a supported value for this version of Windows. When running on Windows prior to 10.0.19645 (`NTDDI_VERSION < NTDDI_VERSION_MN`), the `Version` field must be set to PCW_VERSION_1 (0x100). When running on Windows 10.0.19645 and later (`NTDDI_VERSION >= NTDDI_VERSION_MN`), this may be set to PCW_VERSION_1 (0x100) or PCW_VERSION_2 (0x200).
- The `Info->Flags` field contains a value not recognized by the running version of Windows.

## Remarks

The provider calls this function to create a new counterset registration. All of the input arguments are captured so that the caller does not have to keep a copy of them.

By default, the new counterset is visible only to the server silo that was active at the time of registration (i.e. `PcwRegister` associates the newly-created registration with the server silo that was attached to the thread when `PcwRegister` is called). If running on Windows 10.0.19645 and later (`NTDDI_VERSION >= NTDDI_VERSION_MN`) you may create a counterset registration that is visible to all server silos by setting `PCW_REGISTRATION_INFORMATION::Version` to `PCW_VERSION_2` and setting `PCW_REGISTRATION_INFORMATION::Flags` to `PcwRegistrationSiloNeutral`.

### CTRPP-generated RegisterXxx function

Most developers do not need to call `PcwRegister` directly. Instead, they will compile a manifest with the CTRPP tool and use the RegisterXxx function from the CTRPP-generated header. The generated function will look like this:

```c
EXTERN_C FORCEINLINE NTSTATUS
RegisterMyCounterset(
    __in_opt PPCW_CALLBACK Callback,
    __in_opt PVOID CallbackContext
    )
{
    PCW_REGISTRATION_INFORMATION RegInfo;

    PAGED_CODE();

    InitRegistrationInformationMyCounterset(Callback, CallbackContext, &RegInfo);

    return PcwRegister(&MyCounterset, &RegInfo);
}
```

The CTRPP-generated Register function will be named *Prefix*Register*Counterset*. *Prefix* is usually blank, but may be present if the `-prefix` parameter was used on the CTRPP command-line. *Counterset* is the name of the counterset, as specified in the manifest. The generated Register function will invoke the *Prefix*InitRegistrationInformation*Counterset* function to initialize a `PCW_REGISTRATION_INFORMATION` structure and then invoke `PcwRegister` to create a new registration and store the handle in the global *Counterset* variable (declared in the CTRPP-generated header, `MyCounterset` in the example).

In some cases, the CTRPP-generated Add function might not be appropriate.

- If you must compile with `NTDDI_VERSION >= NTDDI_VERSION_FE` but must run on earlier versions of Windows, the CTRPP-generated Register function will not work because it sets `RegInfo.Version = PCW_CURRENT_VERSION`. When `NTDDI_VERSION >= NTDDI_VERSION_FE`, `PCW_CURRENT_VERSION` will be set to `PCW_VERSION_2`, causing `PcwRegister` to return an error.

- If you need to support multiple counterset registrations (e.g. to support a separate registration per server silo), the CTRPP-generated Register function will not work because it stores the returned handle in a global variable.

- If you want to create a silo-neutral counterset registration, the CTRPP-generated Register function will not work because there is no way to change the value of `RegInfo.Flags` before calling `PcwRegister`.

In these cases, use code like the following instead of calling the CTRPP-generated Register function:

```c
PCW_REGISTRATION_INFORMATION RegInfo;
InitRegistrationInformationMyCounterset(Callback, CallbackContext, &RegInfo);

// Modify RegInfo as needed,
// e.g. RegInfo.Version = PCW_VERSION_1,
// or RegInfo.Flags = PcwRegistrationSiloNeutral.

// If needed, use another variable to store the handle instead of MyCounterset.
Status = PcwRegister(&MyCounterset, &RegInfo);
```

The CTRPP-generated InitRegistrationInformationXxx function initializes the `RegInfo` structure based on declarations from the manifest. For more information about the generated InitRegistrationInformation function, refer to the documentation for [PCW_REGISTRATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_registration_information).

If using your own handle variables instead of *Counterset* to store the handle, you may also need to call `PcwUnregister` and `PcwCreateInstance` directly instead of using the CTRPP-generated **Unregister***Xxx* and **Create***Xxx* functions.

## See also

[PcwUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pcwunregister)

[**_PCW_REGISTRATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pcw_registration_information)