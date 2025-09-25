# PIBIO_ENGINE_QUERY_PREFERRED_FORMAT_FN callback function

## Description

Called by the sensor adapter on the biometric unit to determine the input data format preferred by the engine adapter.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `StandardFormat` [out]

Pointer to a [WINBIO_REGISTERED_FORMAT](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-registered-format) structure that specifies the format of the data in the **StandardDataBlock** member of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) object. The format is an IBIA-registered name/value pair.

### `VendorFormat` [out]

Pointer to a GUID that receives the vendor-defined format of the data in the **VendorDataBlock** member of the [WINBIO_BIR](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-bir) object.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer parameter is **NULL**. |

## Remarks

The sensor adapter calls this function to determine the biometric capture format.

#### Examples

The following pseudocode shows one possible implementation of this function. The example does not compile. You must adapt it to suit your purpose.

```cpp
//////////////////////////////////////////////////////////////////////////////////////////
//
// EngineAdapterQueryPreferredFormat
//
// Purpose:
//      Called by the sensor adapter on the biometric unit to determine the
//      input data format preferred by the engine adapter.
//
// Parameters:
//      Pipeline        - Pointer to a WINBIO_PIPELINE structure associated
//                        with the biometric unit performing the operation.
//      StandardFormat  - Pointer to a WINBIO_REGISTERED_FORMAT structure
//                        that specifies the format of the data in the
//                        StandardDataBlock member of the WINBIO_BIR object.
//                        The format is an IBIA-registered name/value pair.
//      VendorFormat    - Pointer to a GUID that receives the vendor-defined
//                        format of the data in the VendorDataBlock member of
//                        the WINBIO_BIR object.
//
static HRESULT
WINAPI
EngineAdapterQueryPreferredFormat(
    __inout PWINBIO_PIPELINE Pipeline,
    __out PWINBIO_REGISTERED_FORMAT StandardFormat,
    __out PWINBIO_UUID VendorFormat
    )
{
   HRESULT hr = S_OK;

   // Verify that pointer arguments are not NULL.
   if (!ARGUMENT_PRESENT(Pipeline) ||
       !ARGUMENT_PRESENT(StandardFormat) ||
       !ARGUMENT_PRESENT(VendorFormat))
   {
        hr = E_POINTER;
        goto cleanup;
   }

   // Specify the preferred data formats.
   StandardFormat->Owner = WINBIO_ANSI_381_FORMAT_OWNER;
   StandardFormat->Type = WINBIO_ANSI_381_FORMAT_TYPE;
   *VendorFormat = VENDOR_UUID_VALUE;

cleanup:

    return hr;
}
```

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)