# IMFMediaEvent::GetValue

## Description

Retrieves the value associated with the event, if any. The value is retrieved as a **PROPVARIANT** structure. The actual data type and the meaning of the value depend on the event.

## Parameters

### `pvValue` [out]

Pointer to a **PROPVARIANT** structure. The method fills this structure with the data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Before calling this method, call **PropVariantInit** to initialize the **PROPVARIANT** structure. After the method returns, call **PropVariantClear** to free the memory that was allocated for the **PROPVARIANT** data.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

#### Examples

The following function gets the event value if the value is an **IUnknown** pointer. If the **PROPVARIANT** type is not **VT_UNKOWN**, the function returns **MF_E_INVALIDTYPE**.

```cpp
//  Gets an IUnknown pointer from an IMFMediaEvent event and queries
//  the pointer for a specified interface.
//
//  NOTE: Applies only to events that contain IUnknown pointers.
//        Otherwise, the function returns MF_E_INVALIDTYPE.

template <class Q>
HRESULT GetEventObject(IMFMediaEvent *pEvent, Q **ppObject)
{
    *ppObject = NULL;   // zero output

    PROPVARIANT var;
    HRESULT hr = pEvent->GetValue(&var);
    if (SUCCEEDED(hr))
    {
        if (var.vt == VT_UNKNOWN)
        {
            hr = var.punkVal->QueryInterface(ppObject);
        }
        else
        {
            hr = MF_E_INVALIDTYPE;
        }
        PropVariantClear(&var);
    }
    return hr;
}

```

## See also

[IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent)

[Media Event Generators](https://learn.microsoft.com/windows/desktop/medfound/media-event-generators)