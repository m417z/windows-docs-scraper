# IPropertyUI::FormatForDisplay

## Description

Developers should use [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription) instead. Gets a formatted, Unicode string representation of a property value.

## Parameters

### `fmtid` [in]

Type: **REFFMTID**

### `pid` [in]

Type: **PROPID**

### `ppropvar` [in]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

A [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure that contains the type and value of the property.

### `puiff` [in]

Type: **PROPERTYUI_FORMAT_FLAGS**

The format for the returned property value.

#### PUIFFDF_DEFAULT (0x00000000)

0x00000000.

#### PUIFFDF_RIGHTTOLEFT (0x00000001)

0x00000001. Deprecated, do not use.

#### PUIFFDF_SHORTFORMAT (0x00000002)

0x00000002. Use the short format version of the string.

#### PUIFFDF_NOTIME (0x00000004)

0x00000004. Truncate time to days, not hours/mins/sec.

#### PUIFFDF_FRIENDLYDATE (0x00000008)

0x00000008. Use the friendly name for date: "Today", "Yesterday", and so on.

### `pwszText` [out]

Type: **LPWSTR**

The property value, formatted for display.

### `cchText` [in]

Type: **DWORD**

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.