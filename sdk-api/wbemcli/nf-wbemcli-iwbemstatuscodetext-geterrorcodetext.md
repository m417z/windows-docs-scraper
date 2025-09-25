# IWbemStatusCodeText::GetErrorCodeText

## Description

The
**IWbemStatusCodeText::GetErrorCodeText**
method returns the text string description associated with the error code.

## Parameters

### `hRes` [in]

Handle to the error code for which you want a description.

### `LocaleId` [in]

Reserved. This parameter must be 0 (zero).

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `MessageText` [out]

Pointer to a string containing the descriptive text of the error code.

## Return value

This method returns **WBEM_S_NO_ERROR** if successful.

## Remarks

To enable **GetErrorCodeText** to
return the text string description, the caller must free the pointer in the *MessageText*
parameter.

#### Examples

The following example describes how to implement
**GetErrorCodeText**.

```cpp
IWbemStatusCodeText * pStatus = NULL;

    SCODE sc = CoCreateInstance(CLSID_WbemStatusCodeText,
                                0,
                                CLSCTX_INPROC_SERVER,
                                IID_IWbemStatusCodeText,
                                (LPVOID *) &pStatus);

    if(sc == S_OK)
    {
        BSTR bstr = 0;

        // The m_hres isan HRESULT variable that has already
        // been declared and initialized.
        sc = pStatus->GetErrorCodeText(m_hres, 0, 0, &bstr);
        if(sc == S_OK)
        {
            // to do, display this:
            SysFreeString(bstr);
            bstr = 0;
        }
        sc = pStatus->GetFacilityCodeText(m_hres, 0, 0, &bstr);
        if(sc == S_OK)
        {
            // to do, display this:
            SysFreeString(bstr);
            bstr = 0;
        }
        pStatus->Release();
    }

    // clean up.
    pStatus->Release();
```