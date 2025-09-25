# IWMDMDevice2::GetCanonicalName

## Description

The **GetCanonicalName** method retrieves the canonical name of the device.

## Parameters

### `pwszPnPName` [out]

Wide-character buffer for the canonical names. This buffer must be allocated and released by the caller.

### `nMaxChars` [in]

Integer specifying the maximum number of characters that can be placed in *pwszPnPName*, including the termination character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *pwszPnPName* parameter is an invalid or **NULL** pointer. |
| **WMDM_E_NOTSUPPORTED** | The device does not support a canonical name. |
| **WMDM_E_BUFFERTOOSMALL** | The buffer specified is too small for the canonical name. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The application can use the retrieved canonical name to call [IWMDeviceManager2::GetDeviceFromCanonicalName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-getdevicefromcanonicalname) to find this device again.

The returned canonical name is in the format < *PnP Device Path* >$< *index* >, where *index* is a zero-based index into the device objects returned by the service provider for the specified PnP device path.

The format of canonical name is subject to change in future releases of Windows Media Device Manager.

#### Examples

The following C++ code retrieves a device canonical name.

```cpp

// Obtain an IWMDMDevice2 interface and call
// some methods.
const UINT MAX_CHARS = 100;
CComQIPtr<IWMDMDevice2> pIWMDMDevice2(pIWMDMDevice);
if (pIWMDMDevice2 != NULL)
{
    // Get the canonical name.
    WCHAR canonicalName[MAX_CHARS];
    hr = pIWMDMDevice2->GetCanonicalName(canonicalName, MAX_CHARS);
    if (hr == S_OK)
    {
        // TODO: Retrieve the canonical name.
    }

    // Find out the driver.
    myGetDriverName(pIWMDMDevice2);
}

```

## See also

[IWMDMDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice2)

[IWMDeviceManager2::GetDeviceFromCanonicalName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-getdevicefromcanonicalname)