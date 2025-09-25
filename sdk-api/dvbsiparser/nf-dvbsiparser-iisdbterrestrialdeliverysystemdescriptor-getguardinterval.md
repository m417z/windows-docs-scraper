# IIsdbTerrestrialDeliverySystemDescriptor::GetGuardInterval

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the guard interval from an Integrated Services Digital Broadcasting (ISDB) terrestrial delivery system descriptor. The guard interval specifies the fraction of an orthogonal frequency division multiplexing (OFDM) symbol period that separates each pair of OFDM symbols.

## Parameters

### `pbVal` [out]

Receives the code indicating the guard value. This code can be any of the following values.

| Value | Meaning |
| --- | --- |
| 00 | 1/32 |

| Value | Meaning |
| --- | --- |
| 01 | 1/16 |

| Value | Meaning |
| --- | --- |
| 10 | 1/8 |

| Value | Meaning |
| --- | --- |
| 11 | 1/4 |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbTerrestrialDeliverySystemDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbterrestrialdeliverysystemdescriptor)