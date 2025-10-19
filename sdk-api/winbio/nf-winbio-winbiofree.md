# WinBioFree function

## Description

Releases memory allocated for the client application by an earlier call to a Windows Biometric Framework API function. Starting with Windows 10, build 1607, this function is available to use with a mobile image.

## Parameters

### `Address` [in]

Address of the memory block to delete.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Address* parameter cannot be **NULL**. |

## Remarks

Multiple functions in the Windows Biometric Framework API allocate memory for the client application and pass the address of that memory to the client. To prevent memory leaks, you must call **WinBioFree** to delete the block when you are done using the information it contains. You delete the memory by passing its address to **WinBioFree**. You can find the address by de-referencing the pointer specified by the appropriate parameter in each of the following functions.

| Function | Parameter | Type of block allocated |
| --- | --- | --- |
| [WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample) | *Sample* | Structure |
| [WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits) | *UnitSchemaArray* | Array of structures |
| [WinBioEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumdatabases) | *StorageSchemaArray* | Array of structures |
| [WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments) | *SubFactorArray* | Array of integers |
| [WinBioEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumserviceproviders) | *BspSchemaArray* | Array of structures |
| EventCallBack | *Event* | Structure |
| CaptureCallback | *Sample* | Structure |

#### Examples

The following function calls [WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits) to enumerate
the installed biometric sensors, and it calls **WinBioFree** to release the
memory created by **WinBioEnumBiometricUnits**. Link to the Winbio.lib static library and include the following header files:

* Windows.h
* Stdio.h
* Conio.h
* Winbio.h

```cpp
HRESULT EnumerateSensors( )
{
    HRESULT hr = S_OK;
    PWINBIO_UNIT_SCHEMA unitSchema = NULL;
    SIZE_T unitCount = 0;

    // Enumerate the installed biometric units.
    hr = WinBioEnumBiometricUnits(
            WINBIO_TYPE_FINGERPRINT,        // Type of biometric unit
            &unitSchema,                    // Array of unit schemas
            &unitCount );                   // Count of unit schemas

    if (FAILED(hr))
    {
        wprintf_s(L"\nWinBioEnumBiometricUnits failed. hr = 0x%x\n", hr);
        goto e_Exit;
    }

e_Exit:

    // Free memory.
    if (unitSchema != NULL)
    {
        WinBioFree(unitSchema);
        unitSchema = NULL;
    }

    return hr;
}

```

## See also

[WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample)

[WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits)

[WinBioEnumDatabases](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumdatabases)

[WinBioEnumEnrollments](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumenrollments)

[WinBioEnumServiceProviders](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumserviceproviders)