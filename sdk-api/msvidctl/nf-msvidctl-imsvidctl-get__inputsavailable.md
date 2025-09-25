# IMSVidCtl::get__InputsAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__InputsAvailable** method retrieves the input devices that are available in a specified category.

## Parameters

### `CategoryGuid` [in]

Pointer to a GUID that specifies the category to enumerate. Supported categories include the following.

| Value | Description |
| --- | --- |
| KSCATEGORY_BDA_NETWORK_PROVIDER | BDA-compatible tuner devices. |
| KSCATEGORY_TVTUNER | Non-BDA analog tuner devices. |
| GUID_NULL | Miscellaneous devices (file source, DVD). |

### `pVal` [out]

Receives an [IMSVidInputDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevices) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method returns a read-only collection of input devices. Use the returned [IMSVidInputDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidinputdevices) pointer to enumerate the collection.

#### Examples

The following example enumerates the available BDA-compatible tuners and retrieves their friendly names.

```cpp

CComPtr<IMSVidInputDevices> pInputs;
hr = pVidControl->get__InputsAvailable(&KSCATEGORY_BDA_NETWORK_PROVIDER, &pInputs);
if (SUCCEEDED(hr))
{
    long lCount;
    hr = pInputs->get_Count(&lCount);
    for (long ix = 0; ix < lCount; ix++)
    {
        CComBSTR bstrName;
        CComVariant var(ix);
        CComPtr<IMSVidInputDevice> pInput;
        hr = pInputs->get_Item(var, &pInput);
        hr = pInput->get_Name(&bstrName);
        // Display the name.
    }
}

```

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_InputActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_inputactive)