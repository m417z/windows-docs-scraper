# IBDA_IPV6Filter::GetMulticastListSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetMulticastListSize** method retrieves the size in bytes of the list of multicast addresses.

## Parameters

### `pulcbAddresses` [in, out]

Pointer that receives the size in bytes.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is used by the [BDA IP Sink](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-ip-sink-filter) filter to request that a Network Provider make its best effort to tune to the stream(s) on which a list of IPv6 multicast addresses may be transmitted. Addresses in the address list are byte aligned in Network order. *UlcbAddresses* will always be an integer multiple of the size of an IPv6 address.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBDA_IPV6Filter Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_ipv6filter)