# IKsFormatSupport::GetDevicePreferredFormat

## Description

The **GetDevicePreferredFormat** method gets the preferred audio stream format for the connection.

## Parameters

### `ppKsFormat` [out]

Pointer to a pointer variable into which the method writes the address of a buffer that contains the format specifier for the preferred format. The specifier begins with a **KSDATAFORMAT** structure that might be followed by additional format information. The method allocates the storage for the format specifier. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the method fails, **ppKsFormat* is **NULL**. For more information about **KSDATAFORMAT**, format specifiers, and **CoTaskMemFree**, see the Windows DDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *ppKsFormat* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## See also

[IKsFormatSupport Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksformatsupport)