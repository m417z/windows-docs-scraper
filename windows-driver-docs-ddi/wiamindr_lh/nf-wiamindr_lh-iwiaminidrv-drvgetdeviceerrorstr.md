## Description

The **IWiaMiniDrv::drvGetDeviceErrorStr** method maps an error code to a Unicode string that describes the error.

## Parameters

### `__MIDL__IWiaMiniDrv0039`

*lDevErrVal* [in]

Specifies the device error value to be mapped to a string. A value of zero indicates that no error occurred.

### `__MIDL__IWiaMiniDrv0040`

*lFlags* [in]

Reserved.

### `__MIDL__IWiaMiniDrv0041`

*plDevErr* [out]

Points to a memory location that will receive a status code for this method. If this method returns **S_OK**, the value stored will be zero. Otherwise, a minidriver-specific error code will be stored at the location pointed to by this parameter.

### `__MIDL__IWiaMiniDrv0042`

*ppszDevErrStr* [out, optional]

Points to a memory location that will receive the address of a string describing the error.

## Return value

On success, the method should return **S_OK** and clear the device error value pointed to by *plDevErr*. If the minidriver does not fully implement this method, the method should return **E_NOTIMPL**. If the minidriver does not recognize the error value passed to this method, the method should return **E_INVALIDARG**. If the method fails, it should return a standard COM error code and place a minidriver-specific error code value in the memory pointed to by *plDevErr*.

## Remarks

To obtain an error string that describes a device-specific minidriver-generated error value, the WIA service calls the **IWiaMiniDrv::drvGetDeviceErrorStr** method. In response to this call, the minidriver should use [**CoTaskMemAlloc**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc) to allocate memory that will contain a localized Unicode string corresponding to the error code passed to the minidriver. The WIA service (or an application) will free the memory. It is likely that an application will display the string, so it should be meaningful to an end user. The string should be loaded from a resource file, so that it can be localized into a variety of languages.