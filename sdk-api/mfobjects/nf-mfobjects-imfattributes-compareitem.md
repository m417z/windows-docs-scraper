# IMFAttributes::CompareItem

## Description

Queries whether a stored attribute value equals to a specified **PROPVARIANT**.

## Parameters

### `guidKey` [in]

GUID that identifies which value to query.

### `Value` [in]

**PROPVARIANT** that contains the value to compare.

### `pbResult` [out]

Receives a Boolean value indicating whether the attribute matches the value given in *Value*. See Remarks. This parameter must not be **NULL**. If this parameter is **NULL**, an access violation occurs.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The method sets *pbResult* to **FALSE** for any of the following reasons:

* No attribute is found whose key matches the one given in *guidKey*.
* The attribute's **PROPVARIANT** type does not match the type given in *Value*.
* The attribute value does not match the value given in *Value*.
* The method fails.

Otherwise, the method sets *pbResult* to **TRUE**.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Attributes and Properties](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes)