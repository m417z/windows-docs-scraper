# IStreamBufferConfigure3::SetNamespace

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetNamespace** method specifies a prefix that is added to the names of the synchronization objects that the Stream Buffer Engine uses to synchronize the reader and writer.

## Parameters

### `pszNamespace` [in]

Pointer to a null-terminated wide character string. If **NULL**, no prefix is used. Currently, the following values are supported.

* L"Global"
* **NULL**

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **CO_E_NOT_SUPPORTED** | The specified prefix is not supported. |

## Remarks

The default value is "Global".

If the value is "Global", the synchronization objects are created in the global name space, which requires administrator privileges in Windows Vista or later. If the value is **NULL**, the synchronization objects are created in the local session name space, which does not require administrator privileges.

## See also

[IStreamBufferConfigure3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure3)