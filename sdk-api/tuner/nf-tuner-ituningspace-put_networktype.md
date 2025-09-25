# ITuningSpace::put_NetworkType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_NetworkType** method specifies the network type of the tuning space as a **BSTR**.

This method is intended for Automation clients, because it specifies the CLSID as a **BSTR**. C++ applications can use the [ITuningSpace::put__NetworkType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-ituningspace-put__networktype) method instead, which takes a GUID value.

## Parameters

### `NetworkTypeGuid` [in]

Contains the string representation of the network type GUID.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[ITuningSpace Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ituningspace)