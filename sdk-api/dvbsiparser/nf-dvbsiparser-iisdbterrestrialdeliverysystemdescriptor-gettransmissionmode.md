# IIsdbTerrestrialDeliverySystemDescriptor::GetTransmissionMode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the transmission mode from an Integrated Services Digital Broadcasting (ISDB) terrestrial delivery system descriptor.

## Parameters

### `pbVal` [out]

Receives a code indicating the transmission mode. This code can be any of the following values.

| Value | Meaning |
| --- | --- |
| 00 | Mode 1. |
| 01 | Mode 2. |
| 10 | Mode 3. |
| 11 | Undefined. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbTerrestrialDeliverySystemDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbterrestrialdeliverysystemdescriptor)