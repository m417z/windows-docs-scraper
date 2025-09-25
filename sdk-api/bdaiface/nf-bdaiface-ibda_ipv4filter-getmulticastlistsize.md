# IBDA_IPV4Filter::GetMulticastListSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetMulticastListSize** method retrieves the number of addresses in the list.

## Parameters

### `pulcbAddresses` [in, out]

Pointer that receives the number of addresses multiplied by the size of an IPv4 address.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is used by an IPv4 Network Data Sink filter to request that a Network Provider make its best effort to tune to the stream(s) on which a list of IPv4 multicast addresses may be transmitted. Addresses in the address list are byte-aligned in Network order. *UlcbAddresses* will always be an integer multiple of the size of an IPv4 address.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPV4Filter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipv4filter)