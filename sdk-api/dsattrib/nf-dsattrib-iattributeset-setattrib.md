# IAttributeSet::SetAttrib

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **SetAttrib** method sets an attribute on the object.

## Parameters

### `guidAttribute` [in]

**GUID** that identifies the attribute.

### `pbAttribute` [in]

Pointer to a buffer that contains the attribute value.

### `dwAttributeLength` [in]

Size of the *pbAttribute* buffer, in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **__HRESULT_FROM_WIN32(ERROR_DUPLICATE_TAG)** | An attribute with this **GUID** already exists on this object. |
| **S_OK** | The method succeeded. |

## See also

[IAttributeSet Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dsattrib/nn-dsattrib-iattributeset)