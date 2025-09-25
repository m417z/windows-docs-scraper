# IBDA_EthernetFilter::GetMulticastListSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetMulticastListSize** method retrieves the number of addresses currently in the list.

## Parameters

### `pulcbAddresses` [out]

Pointer that receives the number of addresses currently in the Network Provider's list.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Addresses in the address list are byte aligned in Network order. *UlcbAddresses* will always be an integer multiple of the size of an Ethernet address.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_EthernetFilter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ethernetfilter)