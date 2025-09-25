# IStreamBufferInitialize::SetHKEY

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetHKEY** method sets the registry key where the stream buffer object stores its configuration information.

## Parameters

### `hkeyRoot` [in]

Handle to the registry key.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | **SetHKEY** was called on a filter after it initialized internally. |

## Remarks

This method enables an application to specify a registry key where the stream buffer objects will save configuration information, including the location of the backing files, the number of backing files, and their size.

You must call this method before the object is initialized, either explicitly or implicitly. For the Stream Buffer Sink filter, call the method before the profile is locked. For the Stream Buffer Source filter, call the method before setting the source file name.

To use this method, do the following:

1. Create a new registry key or open an existing key.
2. Create an instance of the **StreamBufferConfig** object.
3. Query the **StreamBufferConfig** object for the **IStreamBufferInitialize** interface.
4. Call **SetHKey** on the **StreamBufferConfig** object, with a handle to the registry key.
5. Optionally, call **IStreamBufferConfigure** methods to modify the configuration information that will be stored in the registry key.
6. Call **SetHKey** on the Stream Buffer Source filter and the Stream Buffer Sink filter, using the same registry key.

The application is responsible for ensuring that the user has read/write permissions for the registry key.

The caller may release the registry key handle after calling this method.

#### Examples

The following code shows how to configure the backing file directory. Error checking is omitted for brevity.

```cpp

// Create the StreamBufferConfig object.
CComPtr<IStreamBufferConfigure> pConfig;
hr = pConfig.CoCreateInstance(CLSID_StreamBufferConfig);

// Create a new registry key to hold our settings.
HKEY hkey = 0;
long lRes = RegCreateKey(HKEY_LOCAL_MACHINE,
    TEXT("SOFTWARE\\MyStreamBufferKey"), &hkey);

// Set the registry key.
CComPtr<IStreamBufferInitialize> pInit;
hr = pConfig.QueryInterface(&pInit);
hr = pInit->SetHKEY(hkey);
pInit.Release();

// Set the backing file directory.
hr = pConfig->SetDirectory(L"C:\\MyDirectory");

// Create the Stream Buffer Sink filter and set the registry key.
CComPtr<IStreamBufferSink> pSink;
hr = pSink.CoCreateInstance(CLSID_StreamBufferSink);
hr = pSink.QueryInterface(&pInit);
hr = pInit->SetHKEY(hkey);
pInit.Release();

// Create the Stream Buffer Source filter and set the registry key.
CComPtr<IStreamBufferSource> pSource;
hr = pSource.CoCreateInstance(CLSID_StreamBufferSource);
hr = pSource.QueryInterface(&pInit);
hr = pInit->SetHKEY(hkey);

```

## See also

[IStreamBufferInitialize Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferinitialize)