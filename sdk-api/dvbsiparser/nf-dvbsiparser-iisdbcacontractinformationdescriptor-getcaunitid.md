# IIsdbCAContractInformationDescriptor::GetCAUnitId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the value of the CA_unit_id field from an Integrated Services Digital Broadcasting (ISDB) conditional access (CA) contract information descriptor. This field identifies the billing or nonbilling unit to which the component belongs.

## Parameters

### `pbVal` [out]

Receives the conditional access unit identifier. This can be any of the following values.

| Value | Meaning |
| --- | --- |
| 0x0 | Nonbilling unit group. |
| 0x1 | Billing unit group including default event ES group. |
| 0x2 - 0xF | Billing unit group other than the default event ES group. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbCAContractInformationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcacontractinformationdescriptor)