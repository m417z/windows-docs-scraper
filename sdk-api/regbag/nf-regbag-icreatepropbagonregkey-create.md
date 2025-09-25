# ICreatePropBagOnRegKey::Create

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Create** method creates a property bag that can store information in the system registry.

## Parameters

### `hkey` [in]

Specifies a handle to the registry key.

### `subkey` [in]

Specifies the subkey.

### `ulOptions` [in]

Reserved; must be zero.

### `samDesired` [in]

Specifies the desired access rights to the key. The value can be any combination of flags from the *samDesired* parameter in the Win32 **RegOpenKeyEx** function.

### `iid`

Specifies the interface identifier (IID) of a property bag interface. Use the value IID_IPropertyBag or IID_IPropertyBag2.

### `ppBag` [out]

Address of a variable that receives the interface specified by the *iid* parameter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | The specified IID is not supported. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |

## Remarks

This method creates a property bag and returns a pointer to the **IPropertyBag** or **IPropertyBag2** interface, depending on the value of the *iid* parameter. The returned property bag can access the specified registry key, using the access rights given in the *samDesired* parameter. The various property bag methods require different access rights, as follows:

| Method | Required Access Rights |
| --- | --- |
| **IPropertyBag::Read** | KEY_READ |
| **IPropertyBag::Write** | KEY_WRITE |
| **IPropertyBag2::CountProperties** | KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS |
| **IPropertyBag2::GetPropertyInfo** | KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS |

If you write a value of VT_EMPTY or VT_NULL the property is removed from the bag and the corresponding registry values are deleted.

#### Examples

The following example code shows how to create a read back a default tune request in the registry:

```cpp

CComPtr <ICreatePropBagOnRegKey> pCreateRegBag;
HRESULT hr = pCreateRegBag.CoCreateInstance(CLSID_CreatePropBagOnRegKey);
CComPtr <IPropertyBag> pRegBag;
hr = pCreateRegBag->Create(HKEY_CURRENT_USER,
    OLESTR("SOFTWARE\\Microsoft\\MSVidCtl\\DefaultTuneRequest"),
    0, KEY_READ | KEY_WRITE, IID_IPropertyBag, (void**)&pRegBag);
if(FAILED(hr))
{
  ATLASSERT(FALSE);
  return E_FAIL;
}
CComPtr <IAnalogTVTuningSpace> pTuneSpace;
hr = pTuneSpace.CoCreateInstance(CLSID_AnalogTVTuningSpace);
if(FAILED(hr))
{
  ATLASSERT(FALSE);
  return E_FAIL;
}
CComPtr<ITuneRequest> pTuneRequest;
hr = pTuneSpace->CreateTuneRequest(&pTuneRequest);
if(FAILED(hr))
{
  ATLASSERT(FALSE);
  return E_FAIL;
}
CComQIPtr <IPersistPropertyBag> pPersist(pTuneRequest);
CComVariant v((IUnknown*)(pTuneRequest));
hr = pRegBag->Write(L"tr", &v);
if(FAILED(hr))
{
  ATLASSERT(FALSE);
  return E_FAIL;
}

//restore
CComPtr <IPropertyBag> pRegBag2;
hr = pCreateRegBag->Create(HKEY_CURRENT_USER,
OLESTR("SOFTWARE\\Microsoft\\MSVidCtl\\DefaultTuneRequest"),0, KEY_READ,
IID_IPropertyBag, reinterpret_cast<void**>(&pRegBag2));
if(FAILED(hr))
{
  ATLASSERT(FALSE);
  return E_FAIL;
}
CComVariant var;
hr = pRegBag2->Read(OLESTR("tr"), &var, NULL);
if(FAILED(hr))
{
  ATLASSERT(FALSE);
  return E_FAIL;
}

// Make sure we have a tune request object.
CComQIPtr<ITuneRequest> pTune;
switch (var.vt)
{
  case VT_UNKNOWN:
    pTune = var.punkVal;
    break;
  case VT_DISPATCH:
    pTune = var.pdispVal;
    break;
}

```

The following example loads the default tune request and returns an [ITuneRequest](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunerequest) interface pointer:

```cpp

HRESULT LoadDefaultTuneReq(ITuneRequest **ppTuneReq)
{
    HRESULT hr;
    *ppTuneReq = NULL;
    CComPtr<ICreatePropBagOnRegKey> pCreateRegBag;
    hr = pCreateRegBag.CoCreateInstance(CLSID_CreatePropBagOnRegKey,
        NULL, CLSCTX_INPROC_SERVER);
    if (FAILED(hr)) return hr;

    //Create the property bag.
    CComPtr<IPropertyBag> pRegBag;
    hr = pCreateRegBag->Create(HKEY_CURRENT_USER,
        OLESTR("SOFTWARE\\Microsoft\\MSVidCtl"), 0, KEY_READ,
        IID_IPropertyBag, reinterpret_cast<void**>(&pRegBag));
    if (FAILED(hr)) return hr;

    // Read the default tune request from the property bag.
    CComVariant var;
    hr = pRegBag->Read(OLESTR("DefaultTuneRequest"), &var, NULL);
    if (FAILED(hr)) return hr;

    // Make sure we got a tune request object.
    CComQIPtr<ITuneRequest> pTune;
    switch (var.vt)
    {
    case VT_UNKNOWN:
        pTune = var.punkVal;
        break;
    case VT_DISPATCH:
        pTune = var.pdispVal;
        break;
    }
    if (pTune)
    {
        *ppTuneReq = pTune.Detach();
        return S_OK;
    }
    return E_FAIL;
}

```

## See also

[ICreatePropBagOnRegKey Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/regbag/nn-regbag-icreatepropbagonregkey)