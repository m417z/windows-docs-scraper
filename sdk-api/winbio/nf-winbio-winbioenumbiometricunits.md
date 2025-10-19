# WinBioEnumBiometricUnits function

## Description

Enumerates all attached biometric units that match the input type.

## Parameters

### `Factor` [in]

A bitmask of WINBIO_BIOMETRIC_TYPE flags that specifies the biometric unit types to be enumerated. Only **WINBIO_TYPE_FINGERPRINT** is currently supported.

### `UnitSchemaArray` [out]

Address of a variable that receives a pointer to an array of [WINBIO_UNIT_SCHEMA](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-unit-schema) structures that contain information about each enumerated biometric unit. If the function does not succeed, the pointer is set to **NULL**. If the function succeeds, you must pass the pointer to [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release memory allocated internally for the array.

### `UnitCount` [out]

Pointer to a value that specifies the number of structures pointed to by the *UnitSchemaArray* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The bitmask contained in the *Factor* parameter contains one or more an invalid type bits. |
| **E_OUTOFMEMORY** | There was insufficient memory to complete the request. |
| **E_POINTER** | The *UnitSchemaArray* and *UnitCount* parameters cannot be **NULL**. |
| **WINBIO_E_DISABLED** | Current administrative policy prohibits use of the Windows Biometric Framework API. |

## Remarks

Only **WINBIO_TYPE_FINGERPRINT** is currently supported in the *Factor* parameter.

If information about multiple installed biometric units is returned in the array of structures pointed to by the *UnitSchemaArray* parameter, the units are not guaranteed to be in any particular order.

After you are finished using the structures returned to the *UnitSchemaArray* parameter, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory allocated internally for the array.

If all of the factor bits in the *Factor* bitmask refer to unsupported biometric types, the function returns S_OK but the value pointed to by the *UnitSchemaArray* parameter will be NULL and the *UnitCount* parameter will contain zero. Although it is not an error to inquire about unsupported biometric factors, the result of the query will be an empty set.

#### Examples

The following function calls **WinBioEnumBiometricUnits** to enumerate the installed biometric units. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT EnumerateSensors( )
{
    // Declare variables.
    HRESULT hr = S_OK;
    PWINBIO_UNIT_SCHEMA unitSchema = NULL;
    SIZE_T unitCount = 0;
    SIZE_T index = 0;

    // Enumerate the installed biometric units.
    hr = WinBioEnumBiometricUnits(
            WINBIO_TYPE_FINGERPRINT,        // Type of biometric unit
            &unitSchema,                    // Array of unit schemas
            &unitCount );                   // Count of unit schemas

    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioEnumBiometricUnits failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Display information for each installed biometric unit.
    wprintf_s(L"\nSensors: \n");
    for (index = 0; index < unitCount; ++index)
    {
        wprintf_s(L"\n[%d]: \tUnit ID: %d\n",
                 index,
                 unitSchema[index].UnitId );
        wprintf_s(L"\tDevice instance ID: %s\n",
                 unitSchema[index].DeviceInstanceId );
        wprintf_s(L"\tPool type: %d\n",
                 unitSchema[index].PoolType );
        wprintf_s(L"\tBiometric factor: %d\n",
                 unitSchema[index].BiometricFactor );
        wprintf_s(L"\tSensor subtype: %d\n",
                 unitSchema[index].SensorSubType );
        wprintf_s(L"\tSensor capabilities: 0x%08x\n",
                 unitSchema[index].Capabilities );
        wprintf_s(L"\tDescription: %s\n",
                 unitSchema[index].Description );
        wprintf_s(L"\tManufacturer: %s\n",
                 unitSchema[index].Manufacturer );
        wprintf_s(L"\tModel: %s\n",
                 unitSchema[index].Model );
        wprintf_s(L"\tSerial no: %s\n",
                 unitSchema[index].SerialNumber );
        wprintf_s(L"\tFirmware version: [%d.%d]\n",
                 unitSchema[index].FirmwareVersion.MajorVersion,
                 unitSchema[index].FirmwareVersion.MinorVersion);
    }

e_Exit:
    if (unitSchema != NULL)
    {
        WinBioFree(unitSchema);
        unitSchema = NULL;
    }

    wprintf_s(L"\nPress any key to exit...");
    _getch();

    return hr;
}

```

## See also

[WinBioEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumdatabases)

[WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments)

[WinBioEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumserviceproviders)