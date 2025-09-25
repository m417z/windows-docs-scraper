# WinBioEnumDatabases function

## Description

Enumerates all registered databases that match a specified type.

## Parameters

### `Factor` [in]

A bitmask of WINBIO_BIOMETRIC_TYPE flags that specifies the biometric unit types to be enumerated. Only **WINBIO_TYPE_FINGERPRINT** is currently supported.

### `StorageSchemaArray` [out]

Address of a variable that receives a pointer to an array of [WINBIO_STORAGE_SCHEMA](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-storage-schema) structures that contain information about each database. If the function does not succeed, the pointer is set to **NULL**. If the function succeeds, you must pass the pointer to [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release memory allocated internally for the array.

### `StorageCount` [out]

Pointer to a value that specifies the number of structures pointed to by the *StorageSchemaArray* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The bitmask contained in the *Factor* parameter contains one or more an invalid type bits. |
| **E_OUTOFMEMORY** | There was insufficient memory to complete the request. |
| ****E_POINTER**** | The *StorageSchemaArray* and *StorageCount* parameters cannot be **NULL**. |

## Remarks

Only **WINBIO_TYPE_FINGERPRINT** is currently supported in the *Factor* parameter.

If information about multiple databases is returned in the array of structures pointed to by the *StorageSchemaArray* parameter, the databases are not guaranteed to be in any particular order.

After you are finished using the structures returned to the *StorageSchemaArray* parameter, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory allocated internally for the array.

#### Examples

The following code example calls **WinBioEnumDatabases** to enumerate the
biometric databases on the system. The example also includes a function, DisplayGuid, to display the database ID. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT EnumDatabases( )
{
    // Declare variables.
    HRESULT hr = S_OK;
    PWINBIO_STORAGE_SCHEMA storageSchemaArray = NULL;
    SIZE_T storageCount = 0;
    SIZE_T index = 0;

    // Enumerate the databases.
    hr = WinBioEnumDatabases(
            WINBIO_TYPE_FINGERPRINT,    // Type of biometric unit
            &storageSchemaArray,        // Array of database schemas
            &storageCount );            // Number of database schemas
    if (FAILED(hr))
    {
        wprintf_s(L"\nWinBioEnumDatabases failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Display information for each database.
    wprintf_s(L"\nDatabases:\n");
    for (index = 0; index < storageCount; ++index)
    {
        wprintf_s(L"\n[%d]: \tBiometric factor: 0x%08x\n",
                 index,
                 storageSchemaArray[index].BiometricFactor );

        wprintf_s(L"\tDatabase ID: ");
        DisplayGuid(&storageSchemaArray[index].DatabaseId);
        wprintf_s(L"\n");

        wprintf_s(L"\tData format: ");
        DisplayGuid(&storageSchemaArray[index].DataFormat);
        wprintf_s(L"\n");

        wprintf_s(L"\tAttributes:  0x%08x\n",
                 storageSchemaArray[index].Attributes);

        wprintf_s(L"\tFile path:   %ws\n",
                 storageSchemaArray[index].FilePath );

        wprintf_s(L"\tCnx string:  %ws\n",
                 storageSchemaArray[index].ConnectionString );

        wprintf_s(L"\n");
    }

e_Exit:
    if (storageSchemaArray != NULL)
    {
        WinBioFree(storageSchemaArray);
        storageSchemaArray = NULL;
    }

    wprintf_s(L"\nPress any key to exit...");
    _getch();

    return hr;
}

//------------------------------------------------------------------------
// The following function displays a GUID to the console window.
//
VOID DisplayGuid( __in PWINBIO_UUID Guid )
{
    wprintf_s(
        L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
        Guid->Data1,
        Guid->Data2,
        Guid->Data3,
        Guid->Data4[0],
        Guid->Data4[1],
        Guid->Data4[2],
        Guid->Data4[3],
        Guid->Data4[4],
        Guid->Data4[5],
        Guid->Data4[6],
        Guid->Data4[7]
        );
}

```

## See also

[WINBIO_STORAGE_SCHEMA](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-storage-schema)

[WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits)

[WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments)

[WinBioEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumserviceproviders)