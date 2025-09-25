# IDTFilter3::GetProtectionType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetProtectionType** method retrieves the type of content protection that is currently in effect.

## Parameters

### `pProtectionType` [out]

Receives the current protection type, specified as a member of the [ProtType](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/ne-encdec-prottype) enumeration type.

## Return value

Returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## See also

[IDTFilter3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-idtfilter3)