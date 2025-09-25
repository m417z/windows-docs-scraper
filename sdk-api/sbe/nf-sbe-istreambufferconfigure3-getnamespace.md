# IStreamBufferConfigure3::GetNamespace

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNamespace** method retrieves the prefix that is added to the names of the synchronization objects that the Stream Buffer Engine uses to synchronize the reader and writer.

## Parameters

### `ppszNamespace` [out]

Receives a pointer to a null-terminated, wide-character string. The caller must free the string by calling **CoTaskMemFree**. If no prefix is defined, this variable receives a **NULL** pointer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IStreamBufferConfigure3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure3)