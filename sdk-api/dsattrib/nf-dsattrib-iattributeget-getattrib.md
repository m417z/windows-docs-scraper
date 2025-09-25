# IAttributeGet::GetAttrib

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetAttrib** method returns an attribute value, specified by **GUID**.

## Parameters

### `guidAttribute` [in]

**GUID** that specifies the attribute to retrieve.

### `pbAttribute` [in, out]

Pointer to a buffer that receives the attribute value. This parameter can be **NULL**.

### `pdwAttributeLength` [in, out]

If *pbAttribute* is **NULL**, this parameter receives the size of the attribute data, in bytes. If *pbAttribute* is non-**NULL**, this parameter specifies the size of the *pbAttribute* buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer value. |
| **NS_E_UNSUPPORTED_PROPERTY** | The specified **GUID** does not match any attribute on this object. |
| **S_OK** | The method succeeded. |

## See also

[IAttributeGet Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dsattrib/nn-dsattrib-iattributeget)