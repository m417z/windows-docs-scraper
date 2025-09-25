# ITextStoreACP::AdviseSink

## Description

The **ITextStoreACP::AdviseSink** method installs a new advise sink from the [ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink) interface or modifies an existing advise sink. The sink interface is specified by the *punk* parameter.

## Parameters

### `riid` [in]

Specifies the sink interface.

### `punk` [in]

Pointer to the sink interface. Cannot be **NULL**.

### `dwMask` [in]

Specifies the events that notify the advise sink. For more information about possible parameter values, see [TS_AS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-as--constants).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **CONNECT_E_ADVISELIMIT** | A sink interface pointer could not be obtained. |
| **E_INVALIDARG** | The specified sink interface is unsupported. |
| **E_UNEXPECTED** | The specified sink object could not be obtained. |

## Remarks

Subsequent calls with the same interface, represented by the *punk* parameter, are handled as requests to update the *dwMask* parameter. Servers should not call the **AddRef** method on the sink in response to such a request.

Servers only maintain a single connection point. Attempts to advise a second sink object fail until the original sink object is removed. Applications should use the [ITextStoreACP::UnadviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-unadvisesink) method to unregister the sink object when notifications are not required.

Use this method to get the [ITextStoreACPServices](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itextstoreacpservices) interface.

#### Examples

CMyTextEditor
[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

```cpp

STDMETHODIMP CMyTextEditor::AdviseSink(REFIID riid, IUnknown *punk, DWORD dwMask)
{
        HRESULT         hr;
        IUnknown                *punkID;
        typedef struct
        {
        IUnknown                *punkID;
        ITextStoreACPSink       *pTextStoreACPSink;
        DWORD                   dwMask;
        }ADVISE_SINK, *PADVISE_SINK;

        // Determine if the sink interface exists.
        // Get the pointer to the IUnknown interface and check if the IUnknown
        // pointer is the same as a pointer to an existing sink.
        // If the sink exists, update the existing sink with the
        // dwMask parameters passed to this method.
        hr = QueryInterface(IID_IUnknown, (LPVOID*)&punkID);

        if(FAILED(hr))
        {
                hr = E_INVALIDARG;
        }

        if(punkID == m_AdviseSink.punkID)
        {
                m_AdviseSink.dwMask = dwMask;
                hr = S_OK;
        }

        // If the sink does not exist, do the following:
        // 1. Install a new sink.
        // 2. Keep the pointer to the IUnknown interface to uniquely
        //        identify this advise sink.
        // 3. Set the dwMask parameter of this new sink to the dwMask
        //    parameters passed to this method.
        // 4. Increment the reference count.
        // 5. Release the IUnknown pointer, since this pointer is no
        //        longer required.

        if(IsEqualIID(riid, IID_ITextStoreACPSink))
        {
                punk->QueryInterface(IID_ITextStoreACPSink,
                         (LPVOID*)&m_AdviseSink.pTextStoreACPSink);
                m_AdviseSink.punkID = punkID;
                m_AdviseSink.dwMask = dwMask;
                punkID->AddRef();
                punkID->Release();

                hr = S_OK;
        }
        return hr;

}

```

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::UnadviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-unadvisesink)

[ITextStoreACPServices](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itextstoreacpservices)

[TS_AS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-as--constants)