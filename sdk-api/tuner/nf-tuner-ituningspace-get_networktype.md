# ITuningSpace::get_NetworkType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_NetworkType** method retrieves the network type of the tuning space as a **BSTR**.

This method is intended for Automation clients, because it returns the CLSID as a **BSTR**. C++ applications can use the [ITuningSpace::get__NetworkType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspace-get__networktype) method instead, which returns a GUID value

## Parameters

### `NetworkTypeGuid` [out]

Pointer to a variable that receives a string containing the network type GUID.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

The caller must release the returned **BSTR** by calling **SysFreeString**.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)