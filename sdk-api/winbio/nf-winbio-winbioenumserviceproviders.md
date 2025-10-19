# WinBioEnumServiceProviders function

## Description

Retrieves information about installed biometric service providers. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `Factor` [in]

A bitmask of WINBIO_BIOMETRIC_TYPE flags that specifies the biometric unit types to be enumerated. Only **WINBIO_TYPE_FINGERPRINT** is currently supported.

### `BspSchemaArray` [out]

Address of a variable that receives a pointer to an array of [WINBIO_BSP_SCHEMA](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bsp-schema) structures that contain information about each of the available service providers. If the function does not succeed, the pointer is set to **NULL**. If the function succeeds, you must pass the pointer to [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release memory allocated internally for the array.

### `BspCount` [out]

Pointer to a value that specifies the number of structures pointed to by the *BspSchemaArray* parameter.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The bitmask contained in the *Factor* parameter contains one or more an invalid type bits. |
| **E_OUTOFMEMORY** | There was insufficient memory to complete the request. |
| **E_POINTER** | The *BspSchemaArray* and *BspCount* parameters cannot be **NULL**. |

## Remarks

Only **WINBIO_TYPE_FINGERPRINT** is currently supported in the *Factor* parameter.

After you are finished using the structures returned to the *BspSchemaArray* parameter, you must call [WinBioFree](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiofree) to release the memory allocated internally for the array.

If all of the factor bits in the *Factor* bitmask refer to unsupported biometric types, the function returns S_OK but the value pointed to by the *BspSchemaArray* parameter will be **NULL** and the *BspCount* parameter will contain zero. Although it is not an error to inquire about unsupported biometric factors, the result of the query will be an empty set.

#### Examples

The following code example calls **WinBioEnumServiceProviders** to enumerate
the installed service providers. The example also includes a function, DisplayGuid, to display the provider ID. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT EnumSvcProviders( )
{
    // Declare variables.
    HRESULT hr = S_OK;
    PWINBIO_BSP_SCHEMA bspSchemaArray = NULL;
    SIZE_T bspCount = 0;
    SIZE_T index = 0;

    // Enumerate the service providers.
    hr = WinBioEnumServiceProviders(
            WINBIO_TYPE_FINGERPRINT,    // Provider to enumerate
            &bspSchemaArray,            // Provider schema array
            &bspCount );                // Number of schemas returned
    if (FAILED(hr))
    {
        wprintf_s(L"\n WinBioEnumServiceProviders failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

    // Display the schema information.
    wprintf_s(L"\nService providers: \n");
    for (index = 0; index < bspCount; ++index)
    {
        wprintf_s(L"\n[%d]: \tBiometric factor: 0x%08x\n",
                 index,
                 bspSchemaArray[index].BiometricFactor );

        wprintf_s(L"\tBspId: ");
        DisplayGuid(&bspSchemaArray[index].BspId);
        wprintf_s(L"\n");

        wprintf_s(L"\tDescription: %ws\n",
                 bspSchemaArray[index].Description);
        wprintf_s(L"\tVendor: %ws\n",
                 bspSchemaArray[index].Vendor );
        wprintf_s(L"\tVersion: %d.%d\n",
                 bspSchemaArray[index].Version.MajorVersion,
                 bspSchemaArray[index].Version.MinorVersion);

        wprintf_s(L"\n");
    }

e_Exit:
    if (bspSchemaArray != NULL)
    {
        WinBioFree(bspSchemaArray);
        bspSchemaArray = NULL;
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

[WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits)

[WinBioEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumdatabases)

[WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments)