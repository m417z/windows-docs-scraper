# IDTFilter2::GetLastErrorCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetLastErrorCode** method returns the most recent error code from the Decrypter/Detagger filter.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **NS_E_DRM_APPCERT_REVOKED** | A problem has occurred in the digital rights management (DRM) component. |
| **NS_E_DRM_CERTIFICATE_REVOKED** | The client's certificate has been revoked. |
| **S_OK** | No DRM errors have occurred. |

## See also

[IDTFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter)